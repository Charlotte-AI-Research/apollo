#!/usr/bin/env python3

"""
Launch file for RSLidar to LaserScan converter

This launch file starts the converter node with configurable parameters.
It can be used standalone or included in other launch files.

Author: Smit Patel
License: Apache-2.0
"""

import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    """
    Generate launch description for RSLidar to LaserScan converter
    """

    # Package directory
    pkg_share = get_package_share_directory('rslidar_laserscan_converter')

    # Launch arguments
    config_file_arg = DeclareLaunchArgument(
        'config_file',
        default_value=os.path.join(pkg_share, 'config', 'rslidar_converter.yaml'),
        description='Path to the converter configuration file'
    )

    input_topic_arg = DeclareLaunchArgument(
        'input_topic',
        default_value='/rslidar_points',
        description='Input PointCloud2 topic'
    )

    output_topic_arg = DeclareLaunchArgument(
        'output_topic',
        default_value='/scan',
        description='Output LaserScan topic'
    )

    frame_id_arg = DeclareLaunchArgument(
        'frame_id',
        default_value='laser_link',
        description='Frame ID for the LaserScan message'
    )

    conversion_mode_arg = DeclareLaunchArgument(
        'conversion_mode',
        default_value='ring',
        description='Conversion mode: ring or z_slice'
    )

    target_ring_arg = DeclareLaunchArgument(
        'target_ring',
        default_value='8',
        description='Target ring number for ring mode (0-15)'
    )

    # Converter node
    converter_node = Node(
        package='rslidar_laserscan_converter',
        executable='rslidar_to_laserscan_node.py',
        name='rslidar_to_laserscan_node',
        output='screen',
        parameters=[
            LaunchConfiguration('config_file'),
            {
                'input_topic': LaunchConfiguration('input_topic'),
                'output_topic': LaunchConfiguration('output_topic'),
                'frame_id': LaunchConfiguration('frame_id'),
                'conversion_mode': LaunchConfiguration('conversion_mode'),
                'target_ring': LaunchConfiguration('target_ring'),
            }
        ],
        remappings=[
            ('~/input', LaunchConfiguration('input_topic')),
            ('~/output', LaunchConfiguration('output_topic')),
        ]
    )

    return LaunchDescription([
        config_file_arg,
        input_topic_arg,
        output_topic_arg,
        frame_id_arg,
        conversion_mode_arg,
        target_ring_arg,
        converter_node
    ])