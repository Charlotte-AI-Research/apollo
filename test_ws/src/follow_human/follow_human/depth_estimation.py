#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from follow_human.msg import TrackedObject, DepthEstimation
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np

class DepthEstimationNode(Node):
    def __init__(self):
        super().__init__('depth_estimation_node')

        self.bridge = CvBridge()
        self.depth_image = None

        self.subscription_depth = self.create_subscription(
            Image,
            '/camera/aligned_depth_to_color/image_raw',
            self.depth_callback,
            10
        )

        self.subscription_tracker = self.create_subscription(
            TrackedObject,
            '/tracked_objects',
            self.tracker_callback,
            10
        )

        self.publisher = self.create_publisher(
            DepthEstimation,
            '/tracked_objects_with_depth',
            10
        )

        self.get_logger().info("Depth Estimation Node initialized.")

    def depth_callback(self, msg):
        try:
            self.depth_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="passthrough")
        except Exception as e:
            self.get_logger().error(f"Depth image conversion error: {e}")

    def tracker_callback(self, msg: TrackedObject):
        if self.depth_image is None:
            self.get_logger().warn("Depth image not available yet.")
            return

        cx = int(msg.x + msg.width / 2)
        cy = int(msg.y + msg.height / 2)

        if cx < 0 or cx >= self.depth_image.shape[1] or cy < 0 or cy >= self.depth_image.shape[0]:
            self.get_logger().warn("Bounding box center is out of depth image bounds.")
            return

        region = self.depth_image[max(0, cy - 1):cy + 2, max(0, cx - 1):cx + 2]

        if region.dtype == np.uint16:
            valid_depths = region[region > 0]
            depth = float(np.median(valid_depths)) / 1000.0 if valid_depths.size > 0 else -1.0
        elif region.dtype == np.float32:
            valid_depths = region[region > 0.1]
            depth = float(np.median(valid_depths)) if valid_depths.size > 0 else -1.0
        else:
            self.get_logger().error("Unsupported depth image format.")
            return

        msg_out = DepthEstimation()
        msg_out.id = msg.id
        msg_out.class_label = msg.class_label
        msg_out.confidence = msg.confidence
        msg_out.x = msg.x
        msg_out.y = msg.y
        msg_out.width = msg.width
        msg_out.height = msg.height
        msg_out.depth_m = depth

        self.publisher.publish(msg_out)

        self.get_logger().info(
            f"[ID {msg_out.id}] {msg_out.class_label}, depth={msg_out.depth_m:.2f}m, "
            f"bbox=({msg_out.x},{msg_out.y},{msg_out.width},{msg_out.height})"
        )

def main(args=None):
    rclpy.init(args=args)
    node = DepthEstimationNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
