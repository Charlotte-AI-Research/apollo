#!/usr/bin/env python3

"""
RoboSense LiDAR PointCloud2 to LaserScan Converter

This node subscribes to organized PointCloud2 data from RoboSense LiDAR
and converts it to LaserScan format for AMCL localization.

Supports two conversion modes:
1. Ring extraction: Extract a specific ring from the organized point cloud
2. Z-slice filtering: Extract points within a Z height range

Author: Smit Patel
License: Apache-2.0
"""

import math
import numpy as np
import struct
from typing import Optional, Tuple, List

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy

from sensor_msgs.msg import PointCloud2, LaserScan
from sensor_msgs_py import point_cloud2
from std_msgs.msg import Header


class RSLidarToLaserScanNode(Node):
    """
    Converts RoboSense organized PointCloud2 to LaserScan
    """

    def __init__(self):
        super().__init__('rslidar_to_laserscan_node')

        # Declare parameters
        self.declare_parameter('input_topic', '/rslidar_points')
        self.declare_parameter('output_topic', '/scan')
        self.declare_parameter('frame_id', 'laser_link')

        # Conversion mode: 'ring' or 'z_slice'
        self.declare_parameter('conversion_mode', 'ring')

        # Ring extraction parameters
        self.declare_parameter('target_ring', 8)  # Ring 8 of 16 (middle)

        # Z-slice parameters
        self.declare_parameter('z_min', -0.02)  # 2cm below sensor
        self.declare_parameter('z_max', 0.02)   # 2cm above sensor

        # LaserScan parameters
        self.declare_parameter('angle_min', -math.pi)
        self.declare_parameter('angle_max', math.pi)
        self.declare_parameter('angle_increment', 0.0)  # Auto-calculate if 0
        self.declare_parameter('range_min', 0.1)
        self.declare_parameter('range_max', 30.0)
        self.declare_parameter('scan_time', 0.1)  # 10 Hz

        # Get parameters
        self.input_topic = self.get_parameter('input_topic').get_parameter_value().string_value
        self.output_topic = self.get_parameter('output_topic').get_parameter_value().string_value
        self.frame_id = self.get_parameter('frame_id').get_parameter_value().string_value
        self.conversion_mode = self.get_parameter('conversion_mode').get_parameter_value().string_value
        self.target_ring = self.get_parameter('target_ring').get_parameter_value().integer_value
        self.z_min = self.get_parameter('z_min').get_parameter_value().double_value
        self.z_max = self.get_parameter('z_max').get_parameter_value().double_value
        self.angle_min = self.get_parameter('angle_min').get_parameter_value().double_value
        self.angle_max = self.get_parameter('angle_max').get_parameter_value().double_value
        self.angle_increment = self.get_parameter('angle_increment').get_parameter_value().double_value
        self.range_min = self.get_parameter('range_min').get_parameter_value().double_value
        self.range_max = self.get_parameter('range_max').get_parameter_value().double_value
        self.scan_time = self.get_parameter('scan_time').get_parameter_value().double_value

        # Validate parameters
        if self.conversion_mode not in ['ring', 'z_slice']:
            self.get_logger().error(f"Invalid conversion_mode: {self.conversion_mode}. Must be 'ring' or 'z_slice'")
            raise ValueError("Invalid conversion_mode")

        if self.target_ring < 0 or self.target_ring >= 16:
            self.get_logger().error(f"Invalid target_ring: {self.target_ring}. Must be 0-15 for RSHELIOS-16P")
            raise ValueError("Invalid target_ring")

        # Set up QoS profiles
        qos_profile = QoSProfile(
            depth=10,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE
        )

        # Create subscriber and publisher
        self.pointcloud_sub = self.create_subscription(
            PointCloud2,
            self.input_topic,
            self.pointcloud_callback,
            qos_profile
        )

        self.laserscan_pub = self.create_publisher(
            LaserScan,
            self.output_topic,
            10
        )

        # Initialize angle increment if not set
        if self.angle_increment <= 0.0:
            # RoboSense RSHELIOS-16P typically has 1800 points per revolution
            self.angle_increment = (self.angle_max - self.angle_min) / 1800.0

        self.get_logger().info(f"RSLidar to LaserScan converter started")
        self.get_logger().info(f"Mode: {self.conversion_mode}")
        if self.conversion_mode == 'ring':
            self.get_logger().info(f"Target ring: {self.target_ring}")
        else:
            self.get_logger().info(f"Z-slice range: [{self.z_min:.3f}, {self.z_max:.3f}] m")
        self.get_logger().info(f"Input: {self.input_topic} -> Output: {self.output_topic}")

    def pointcloud_callback(self, msg: PointCloud2):
        """
        Process incoming PointCloud2 message and convert to LaserScan
        """
        try:
            if self.conversion_mode == 'ring':
                scan_msg = self.convert_ring_to_laserscan(msg)
            # else:  # z_slice
            #     scan_msg = self.convert_z_slice_to_laserscan(msg)

            if scan_msg is not None:
                self.laserscan_pub.publish(scan_msg)

        except Exception as e:
            self.get_logger().error(f"Error converting pointcloud: {str(e)}")
 
    def convert_ring_to_laserscan(self, msg: PointCloud2) -> Optional[LaserScan]:
        if msg.height <= 1 or msg.width <= 1:
            self.get_logger().warning(
                f"Unexpected cloud layout: height={msg.height}, width={msg.width}"
            )
            return None

        points = []

        # Case A: height = number of rings (typical layout)
        if msg.height <= 64 and msg.width > msg.height:
            num_rings = msg.height
            points_per_ring = msg.width
            if self.target_ring >= num_rings:
                self.get_logger().warning(f"Target ring {self.target_ring} out of range (0-{num_rings-1})")
                return None
            for i in range(points_per_ring):
                uvs = [[self.target_ring, i]]
                point_data = point_cloud2.read_points_list(msg, field_names=['x','y','z'],
                                                        skip_nans=False, uvs=uvs)
                if point_data:
                    p = point_data[0]
                    if not (math.isnan(p[0]) or math.isnan(p[1]) or math.isnan(p[2])):
                        points.append(p)

        # Case B: width = number of rings (your RSHELIOS-16P layout)
        elif msg.width <= 64 and msg.height > msg.width:
            num_rings = msg.width
            points_per_ring = msg.height
            if self.target_ring >= num_rings:
                self.get_logger().warning(f"Target ring {self.target_ring} out of range (0-{num_rings-1})")
                return None
            for i in range(points_per_ring):
                uvs = [[i, self.target_ring]]
                point_data = point_cloud2.read_points_list(msg, field_names=['x','y','z'],
                                                        skip_nans=False, uvs=uvs)
                if point_data:
                    p = point_data[0]
                    if not (math.isnan(p[0]) or math.isnan(p[1]) or math.isnan(p[2])):
                        points.append(p)

        else:
            self.get_logger().error(
                f"Unsupported cloud dimensions: height={msg.height}, width={msg.width}"
            )
            return None

        if not points:
            self.get_logger().warning(f"No valid points found in ring {self.target_ring}")
            return None

        return self.create_laserscan_from_points(points, msg.header)


def main(args=None):
    """
    Main entry point for the node
    """
    rclpy.init(args=args)

    try:
        node = RSLidarToLaserScanNode()
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    except Exception as e:
        print(f"Error: {e}")
    finally:
        rclpy.shutdown()


if __name__ == '__main__':
    main()
