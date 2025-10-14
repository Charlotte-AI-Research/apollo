#!/usr/bin/env python3
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, Command, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
import os
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    scout_loc_dir = FindPackageShare('scout_mini_localization')
    scout_nav_dir = FindPackageShare('scout_mini_navigation')
    scout_desc_dir = FindPackageShare('scout_mini_description')

    map_file = LaunchConfiguration('map')
    use_sim_time = LaunchConfiguration('use_sim_time', default='false')

    # Use unified Nav2 parameters
    nav2_params_file = PathJoinSubstitution([scout_nav_dir, 'config', 'nav2_params.yaml'])

    declare_map_yaml_cmd = DeclareLaunchArgument(
        'map',
        default_value=PathJoinSubstitution([scout_loc_dir, 'maps', '4th_floor.yaml']),
        description='Full path to map yaml file'
    )

    declare_use_sim_time_cmd = DeclareLaunchArgument(
        'use_sim_time',
        default_value='false',
        description='Use simulation time'
    )

    return LaunchDescription([
        declare_map_yaml_cmd,
        declare_use_sim_time_cmd,

        # Robot State Publisher - CRITICAL FOR TF TREE
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{
                'robot_description': Command([
                    'xacro ', 
                    PathJoinSubstitution([scout_desc_dir, 'urdf', 'scout_mini.urdf.xacro'])
                ])
            }]
        ),

        # Static transform publisher to link rslidar frame to laser_link
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
            parameters=[
                {'use_sim_time': use_sim_time},
                {'yaml_filename': map_file}
            ]
        ),

        # AMCL - now uses Nav2 unified parameters
        Node(
            package='nav2_amcl',
            executable='amcl',
            name='amcl',
            output='screen',
            parameters=[nav2_params_file]
        ),

        # Lifecycle Manager for localization
        Node(
            package='nav2_lifecycle_manager',
            executable='lifecycle_manager',
            name='lifecycle_manager_localization',
            output='screen',
            parameters=[nav2_params_file]
        ),

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
            parameters=[{
                'target_frame': '',
                'transform_tolerance': 0.1,
                'min_height': -0.05,
                'max_height': 0.05,
                'angle_min': -3.14159,
                'angle_max': 3.14159,
                'angle_increment': 0.0087,
                'scan_time': 0.1,
                'range_min': 0.1,
                'range_max': 30.0,
                'use_inf': False,
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
            arguments=['-d', PathJoinSubstitution([scout_loc_dir, 'rviz', 'localization.rviz'])],
            output='screen'
        ),
    ])