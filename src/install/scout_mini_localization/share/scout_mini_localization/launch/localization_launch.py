#!/usr/bin/env python3
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration, Command, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    scout_loc_dir = FindPackageShare('scout_mini_localization')
    scout_nav_dir = FindPackageShare('scout_mini_navigation')
    scout_desc_dir = FindPackageShare('scout_mini_description')

    map_file = LaunchConfiguration('map')
    use_sim_time = LaunchConfiguration('use_sim_time', default='false')
    use_rviz = LaunchConfiguration('use_rviz', default='true')

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

    declare_use_rviz_cmd = DeclareLaunchArgument(
        'use_rviz',
        default_value='true',
        description='Launch RViz2'
    )

    robot_state_publisher_node = Node(
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
    )

    rslidar_to_laser_link_node = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='rslidar_to_laser_link',
        arguments=['0', '0', '0', '0', '0', '0', 'laser_link', 'rslidar'],
        output='screen'
    )

    map_server_node = Node(
        package='nav2_map_server',
        executable='map_server',
        name='map_server',
        output='screen',
        parameters=[
            {'use_sim_time': use_sim_time},
            {'yaml_filename': map_file}
        ]
    )

    amcl_node = Node(
        package='nav2_amcl',
        executable='amcl',
        name='amcl',
        output='screen',
        parameters=[nav2_params_file]
    )

    lifecycle_manager_localization_node = Node(
        package='nav2_lifecycle_manager',
        executable='lifecycle_manager',
        name='lifecycle_manager_localization',
        output='screen',
        parameters=[nav2_params_file]
    )

    rslidar_sdk_node = Node(
        package='rslidar_sdk',
        executable='rslidar_sdk_node',
        name='rslidar_sdk',
        output='screen'
    )

    pointcloud_to_laserscan_node = Node(
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
    )

    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        arguments=['-d', PathJoinSubstitution([scout_loc_dir, 'rviz', 'localization.rviz'])],
        output='screen',
        condition=IfCondition(use_rviz)
    )

    return LaunchDescription([
        declare_map_yaml_cmd,
        declare_use_sim_time_cmd,
        declare_use_rviz_cmd,
        robot_state_publisher_node,
        rslidar_to_laser_link_node,
        map_server_node,
        amcl_node,
        lifecycle_manager_localization_node,
        rslidar_sdk_node,
        pointcloud_to_laserscan_node,
        rviz_node
    ])