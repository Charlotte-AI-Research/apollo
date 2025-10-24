#!/usr/bin/env python3

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, TimerAction, RegisterEventHandler
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch.event_handlers import OnProcessStart
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    scout_nav_dir = FindPackageShare('scout_mini_navigation')
    scout_localization_dir = FindPackageShare('scout_mini_localization')

    # Get the package share directory for file paths
    scout_nav_dir_path = get_package_share_directory('scout_mini_navigation')

    use_sim_time = LaunchConfiguration('use_sim_time', default='false')
    use_rviz = LaunchConfiguration('use_rviz', default='true')
    nav2_params_file = os.path.join(scout_nav_dir_path, 'config', 'nav2_params.yaml')
    rviz_config_file = os.path.join(scout_nav_dir_path, 'rviz', 'navigation.rviz')

    declare_use_sim_time_cmd = DeclareLaunchArgument(
        'use_sim_time',
        default_value='false',
        description='Use simulation time'
    )

    declare_use_rviz_cmd = DeclareLaunchArgument(
        'use_rviz',
        default_value='true',
        description='Whether to launch RViz for visualization'
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
        executable='nav2_costmap_2d',
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
        executable='nav2_costmap_2d',
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

    controller_server_node = Node(
        package='nav2_controller',
        executable='controller_server',
        name='controller_server',
        output='screen',
        parameters=[nav2_params_file]
    )

    behavior_server_node = Node(
        package='nav2_behaviors',
        executable='behavior_server',
        name='behavior_server',
        output='screen',
        parameters=[nav2_params_file]
    )

    bt_navigator_node = Node(
        package='nav2_bt_navigator',
        executable='bt_navigator',
        name='bt_navigator',
        output='screen',
        parameters=[nav2_params_file]
    )

    waypoint_follower_node = Node(
        package='nav2_waypoint_follower',
        executable='waypoint_follower',
        name='waypoint_follower',
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

    lifecycle_manager_navigation_node = Node(
        package='nav2_lifecycle_manager',
        executable='lifecycle_manager',
        name='lifecycle_manager_navigation',
        output='screen',
        parameters=[nav2_params_file]
    )

    # Launch RViz for visualization
    # Note: Condition removed due to launch configuration scoping issue
    # To disable RViz, comment out this node in the LaunchDescription below
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2_navigation',
        output='screen',
        arguments=['-d', rviz_config_file]
    )

    # Delay lifecycle managers to give nodes time to fully initialize
    # Localization manager needs time for map_server and amcl to initialize
    # Navigation manager must start AFTER localization completes (add extra buffer)
    delayed_lifecycle_manager_localization = TimerAction(
        period=15.0,
        actions=[lifecycle_manager_localization_node]
    )

    delayed_lifecycle_manager_navigation = TimerAction(
        period=30.0,
        actions=[lifecycle_manager_navigation_node]
    )

    return LaunchDescription([
        declare_use_sim_time_cmd,
        declare_use_rviz_cmd,
        localization_launch,
        # Note: global_costmap and local_costmap are managed internally by
        # planner_server and controller_server respectively, not launched separately
        planner_server_node,
        smoother_server_node,
        controller_server_node,
        behavior_server_node,
        bt_navigator_node,
        waypoint_follower_node,
        rviz_node,
        delayed_lifecycle_manager_localization,
        delayed_lifecycle_manager_navigation
    ])