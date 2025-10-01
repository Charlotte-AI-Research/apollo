#!/usr/bin/env python3
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import Command
import os

from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    pkg_share = get_package_share_directory('scout_mini_localization')

    map_yaml_file = os.path.join(pkg_share, 'maps', '4th_floor.yaml')
    amcl_config_file = os.path.join(pkg_share, 'config', 'amcl.yaml')

    return LaunchDescription([

        # Robot State Publisher - CRITICAL FOR TF TREE
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{
                'robot_description': Command([
                    'xacro ', 
                    os.path.join(get_package_share_directory('scout_mini_description'), 'urdf', 'scout_mini.urdf.xacro')
                ])
            }]
        ),

        # Static transform publisher to link rslidar frame to laser_link - CRITICAL FIX
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='rslidar_to_laser_link',
            arguments=['0', '0', '0', '0', '0', '0', 'laser_link', 'rslidar'],
            output='screen'
        ),

        # Map server
        Node(
            package='nav2_map_server',
            executable='map_server',
            name='map_server',
            output='screen',
            parameters=[{
                'yaml_filename': map_yaml_file,
                'topic_name': 'map',
                'frame_id': 'map'  
            }]
        ),

        # AMCL
        Node(
            package='nav2_amcl',
            executable='amcl',
            name='amcl',
            output='screen',
            parameters=[amcl_config_file]
        ),

        # Lifecycle Manager
        Node(
            package='nav2_lifecycle_manager',
            executable='lifecycle_manager',
            name='lifecycle_manager_localization',
            output='screen',
            parameters=[{
                'use_sim_time': False,
                'autostart': True,
                'node_names': ['map_server', 'amcl']
            }]
        ),

        # LiDAR driver (RoboSense SDK)
        Node(
            package='rslidar_sdk',
            executable='rslidar_sdk_node',
            name='rslidar_sdk',
            output='screen'
        ),

        # PointCloud → LaserScan Converter with optimized parameters for organized clouds
        Node(
            package='pointcloud_to_laserscan',
            executable='pointcloud_to_laserscan_node',
            name='pointcloud_to_laserscan',
            output='screen',
            parameters=[{
                'target_frame': '',  # Use source frame
                'transform_tolerance': 0.1,
                'min_height': -0.05,  # Tight height range for horizontal slice
                'max_height': 0.05,
                'angle_min': -3.14159,
                'angle_max': 3.14159,
                'angle_increment': 0.0087,  # ~0.5 degrees
                'scan_time': 0.1,
                'range_min': 0.1,
                'range_max': 30.0,
                'use_inf': False,  # Use max_range instead of inf
                'inf_epsilon': 1.0
            }],
            remappings=[
                ('cloud_in', '/rslidar_points'),
                ('scan', '/scan')
            ]
        ),

        # RViz2 for visualization
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=['-d', os.path.join(pkg_share, 'rviz', 'localization.rviz')],
            output='screen'
        ),
    ])
