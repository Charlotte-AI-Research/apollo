#!/usr/bin/env python3

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    scout_nav_dir = FindPackageShare('scout_mini_navigation')
    scout_localization_dir = FindPackageShare('scout_mini_localization')

    use_sim_time = LaunchConfiguration('use_sim_time', default='false')
    use_rviz = LaunchConfiguration('use_rviz', default='true')
    nav2_params_file = PathJoinSubstitution([scout_nav_dir, 'config', 'nav2_params.yaml'])
    rviz_config_file = PathJoinSubstitution([scout_nav_dir, 'rviz', 'navigation.rviz'])

    declare_use_sim_time_cmd = DeclareLaunchArgument(
        'use_sim_time',
        default_value='false',
        description='Use simulation time'
    )

    declare_use_rviz_cmd = DeclareLaunchArgument(
        'use_rviz',
        default_value='true',
        description='Whether to launch RViz for navigation'
    )

    localization_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            scout_localization_dir,
            '/launch/localization_launch.py'
        ]),
        launch_arguments={
            'use_sim_time': use_sim_time,
            'use_rviz': 'False',
        }.items()
    )

    global_costmap_node = Node(
        package='nav2_costmap_2d',
        executable='costmap_2d_node',
        name='global_costmap',
        output='screen',
        parameters=[nav2_params_file],
        remappings=[
            ('costmap', 'global_costmap/costmap'),
            ('costmap_updates', 'global_costmap/costmap_updates')
        ]
    )

    local_costmap_node = Node(
        package='nav2_costmap_2d',
        executable='costmap_2d_node',
        name='local_costmap',
        output='screen',
        parameters=[nav2_params_file],
        remappings=[
            ('costmap', 'local_costmap/costmap'),
            ('costmap_updates', 'local_costmap/costmap_updates')
        ]
    )

    planner_server_node = Node(
        package='nav2_planner',
        executable='planner_server',
        name='planner_server',
        output='screen',
        parameters=[nav2_params_file]
    )

    smoother_server_node = Node(
        package='nav2_smoother',
        executable='smoother_server',
        name='smoother_server',
        output='screen',
        parameters=[nav2_params_file]
    )

    lifecycle_manager_navigation_node = Node(
        package='nav2_lifecycle_manager',
        executable='lifecycle_manager',
        name='lifecycle_manager_navigation',
        output='screen',
        parameters=[nav2_params_file]
    )

    rviz_node = Node(
        condition=IfCondition(use_rviz),
        package='rviz2',
        executable='rviz2',
        name='rviz2_navigation',
        output='screen',
        arguments=['-d', rviz_config_file]
    )

    return LaunchDescription([
        declare_use_sim_time_cmd,
        declare_use_rviz_cmd,
        localization_launch,
        global_costmap_node,
        local_costmap_node,
        planner_server_node,
        smoother_server_node,
        lifecycle_manager_navigation_node,
        rviz_node
    ])