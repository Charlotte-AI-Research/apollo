#!/usr/bin/env python3
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch_ros.actions import Node
from launch.substitutions import Command, LaunchConfiguration
import os

from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    pkg_share = get_package_share_directory('scout_mini_localization')
    nav_pkg_share = get_package_share_directory('scout_mini_navigation')

    nav2_params_file = os.path.join(nav_pkg_share, 'config', 'nav2_params.yaml')

    # Launch arguments
    use_rviz = LaunchConfiguration('use_rviz', default='true')
    use_sim_time = LaunchConfiguration('use_sim_time', default='false')

    return LaunchDescription([
        # Declare launch arguments
        DeclareLaunchArgument(
            'use_rviz',
            default_value='true',
            description='Whether to launch RViz for localization visualization'
        ),

        DeclareLaunchArgument(
            'use_sim_time',
            default_value='false',
            description='Use simulation time'
        ),

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
            parameters=[nav2_params_file]
        ),

        # AMCL
        Node(
            package='nav2_amcl',
            executable='amcl',
            name='amcl',
            output='screen',
            parameters=[nav2_params_file]
        ),

        # Note: Lifecycle manager is NOT launched here.
        # It will be managed by the navigation launch file's lifecycle_manager_localization
        # which is configured in nav2_params.yaml

        # LiDAR driver (RoboSense SDK)
        Node(
            package='rslidar_sdk',
            executable='rslidar_sdk_node',
            name='rslidar_sdk',
            output='screen'
        ),

        # PointCloud → LaserScan Converter
        Node(
            package='pointcloud_to_laserscan',
            executable='pointcloud_to_laserscan_node',
            name='pointcloud_to_laserscan',
            output='screen',
            parameters=[nav2_params_file],
            remappings=[
                ('cloud_in', '/rslidar_points'),
                ('scan', '/scan')
            ]
        ),

        # RViz2 for visualization (conditional)
        Node(
            condition=IfCondition(use_rviz),
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=['-d', os.path.join(pkg_share, 'rviz', 'localization.rviz')],
            output='screen'
        ),
    ])
