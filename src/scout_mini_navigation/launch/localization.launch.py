#!/usr/bin/env python3
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import Command
import os

from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    # TODO: CHANGE PACKAGE NAME for Phase 3
    # Use 'scout_mini_navigation' instead of 'scout_mini_localization'
    pkg_share = get_package_share_directory('scout_mini_localization')

    # TODO: Keep your existing map, but later reference this via LaunchArgument (see below)
    map_yaml_file = os.path.join(pkg_share, 'maps', '4th_floor.yaml')

    # TODO: REMOVE this once moving to Nav2 Phase 3
    # AMCL parameters will come from nav2_params.yaml instead of amcl.yaml
    amcl_config_file = os.path.join(pkg_share, 'config', 'amcl.yaml')

    return LaunchDescription([

        # ------------------------------------------------------
        # Robot State Publisher - KEEP THIS (needed for TF tree)
        # ------------------------------------------------------
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{
                'robot_description': Command([
                    'xacro ',
                    os.path.join(
                        get_package_share_directory('scout_mini_description'),
                        'urdf',
                        'scout_mini.urdf.xacro'
                    )
                ])
            }]
        ),

        # ------------------------------------------------------
        # Static transform publisher - KEEP THIS
        # Still needed to connect LiDAR and laser_link frames
        # ------------------------------------------------------
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='rslidar_to_laser_link',
            arguments=['0', '0', '0', '0', '0', '0', 'laser_link', 'rslidar'],
            output='screen'
        ),

        # ------------------------------------------------------
        # Map Server - NEEDS UPDATE FOR PHASE 3
        # ------------------------------------------------------
        # TODO:
        # - Keep 'nav2_map_server' (correct)
        # - Add 'use_sim_time' as LaunchArgument
        # - Instead of inline parameters, load from nav2_params.yaml
        #   (Team 1 section in that file will define map_server params)
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

        # ------------------------------------------------------
        # AMCL - NEEDS UPDATE FOR PHASE 3
        # ------------------------------------------------------
        # TODO:
        # - Keep 'nav2_amcl' package (correct)
        # - Replace 'amcl_config_file' with path to nav2_params.yaml
        # - Pass parameters=[nav2_params_file] instead of direct AMCL YAML
        # - Use LaunchConfiguration for 'use_sim_time'
        Node(
            package='nav2_amcl',
            executable='amcl',
            name='amcl',
            output='screen',
            parameters=[amcl_config_file]
        ),

        # ------------------------------------------------------
        # Lifecycle Manager - NEEDS UPDATE FOR PHASE 3
        # ------------------------------------------------------
        # TODO:
        # - Keep this node (required for Nav2)
        # - Later, remove hardcoded dict and load from nav2_params.yaml
        # - Ensure node_names match exactly ['map_server', 'amcl']
        # - Add this lifecycle section to Team 1's part of nav2_params.yaml
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

        # ------------------------------------------------------
        # LiDAR Driver - OPTIONAL
        # ------------------------------------------------------
        # TODO:
        # - Only include this if the driver isn’t already started elsewhere
        # - Eventually move this to a hardware bringup launch file (not Nav2)
        Node(
            package='rslidar_sdk',
            executable='rslidar_sdk_node',
            name='rslidar_sdk',
            output='screen'
        ),

        # ------------------------------------------------------
        # PointCloud → LaserScan Converter - KEEP
        # ------------------------------------------------------
        # TODO:
        # - Keep same parameters for now
        # - Team 2 may later tune this for obstacle layer accuracy
        Node(
            package='pointcloud_to_laserscan',
            executable='pointcloud_to_laserscan_node',
            name='pointcloud_to_laserscan',
            output='screen',
            parameters=[{
                'target_frame': '',  # Use source frame
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

        # ------------------------------------------------------
        # RViz2 - OPTIONAL FOR TESTING
        # ------------------------------------------------------
        # TODO:
        # - Keep this during development
        # - Replace with Nav2 RViz config ('navigation.rviz') in Phase 3
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=['-d', os.path.join(pkg_share, 'rviz', 'localization.rviz')],
            output='screen'
        ),
    ])
