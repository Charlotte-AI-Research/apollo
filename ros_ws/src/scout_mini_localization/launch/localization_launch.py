from launch import LaunchDescription
from launch_ros.actions import Node
import os

from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    pkg_share = get_package_share_directory('scout_mini_localization')

    map_yaml_file = os.path.join(pkg_share, 'maps', '4th_floor.yaml')
    amcl_config_file = os.path.join(pkg_share, 'config', 'amcl.yaml')

    return LaunchDescription([

        # Map server
        Node(
            package='nav2_map_server',
            executable='map_server',
            name='map_server',
            output='screen',
            parameters=[{'yaml_filename': map_yaml_file}]
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

        # ===================================================================
        # TODO (Team 1 - Sensors & TF):
        # Add lidar driver node here (RoboSense or other).
        # Example placeholder:
        # Node(
        #     package='robosense_driver',
        #     executable='rslidar_driver_node',
        #     name='rslidar_driver',
        #     output='screen',
        #     parameters=[{'some_param': 'value'}]
        # ),
        #
        # TODO (Team 1 - Sensors & TF):
        # Add pointcloud_to_laserscan node to generate /scan from /rslidar_points.
        # Node(
        #     package='pointcloud_to_laserscan',
        #     executable='pointcloud_to_laserscan_node',
        #     name='pointcloud_to_laserscan',
        #     output='screen',
        #     parameters=[{
        #         'target_frame': 'laser_link',
        #         'transform_tolerance': 0.01,
        #         'min_height': -0.1,
        #         'max_height': 0.1
        #     }],
        #     remappings=[('cloud_in', '/rslidar_points'), ('scan', '/scan')]
        # ),

        # ===================================================================
        # TODO (Team 3 - RViz):
        # Add RViz launch node once localization.rviz is created.
        # Node(
        #     package='rviz2',
        #     executable='rviz2',
        #     name='rviz2',
        #     arguments=['-d', os.path.join(pkg_share, 'rviz', 'localization.rviz')],
        #     output='screen'
        # ),
        # ===================================================================
    ])
