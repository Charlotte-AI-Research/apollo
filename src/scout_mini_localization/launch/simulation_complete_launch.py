#!/usr/bin/env python3
"""
Complete simulation launch file for testing Scout Mini with Nav2
This file launches:
- Gazebo with the robot
- Robot state publisher
- Controllers
- Localization (AMCL)
- RViz
"""

import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import Command, FindExecutable, PathJoinSubstitution, LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    # Package directories
    pkg_gazebo_ros = get_package_share_directory('gazebo_ros')
    pkg_scout_mini_description = get_package_share_directory('scout_mini_description')
    pkg_scout_mini_base = get_package_share_directory('scout_mini_base')
    pkg_scout_mini_localization = get_package_share_directory('scout_mini_localization')

    # Launch configuration
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')

    # File paths
    gazebo_urdf_path = os.path.join(pkg_scout_mini_description, 'urdf', 'scout_mini_gazebo.urdf.xacro')
    robot_config_path = os.path.join(pkg_scout_mini_base, 'config', 'scout_mini.yaml')
    map_yaml_file = os.path.join(pkg_scout_mini_localization, 'maps', '4th_floor.yaml')
    amcl_config_file = os.path.join(pkg_scout_mini_localization, 'config', 'amcl.yaml')
    rviz_config_file = os.path.join(pkg_scout_mini_localization, 'rviz', 'localization.rviz')

    # Robot description
    robot_description_content = Command(
        [
            PathJoinSubstitution([FindExecutable(name="xacro")]),
            " ",
            gazebo_urdf_path,
        ]
    )
    robot_description = {"robot_description": robot_description_content}

    # ========================
    # Gazebo
    # ========================
    gazebo_server = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_gazebo_ros, 'launch', 'gzserver.launch.py')
        ),
        launch_arguments={'verbose': 'true'}.items()
    )

    gazebo_client = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_gazebo_ros, 'launch', 'gzclient.launch.py')
        )
    )

    # ========================
    # Robot State Publisher
    # ========================
    robot_state_publisher = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        output="screen",
        parameters=[robot_description, {'use_sim_time': use_sim_time}],
    )

    # ========================
    # Spawn Robot in Gazebo
    # ========================
    spawn_robot = Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        arguments=[
            '-entity', 'scout_mini',
            '-topic', 'robot_description',
            '-x', '0.0',
            '-y', '0.0',
            '-z', '0.2',
        ],
        output='screen',
    )

    # ========================
    # Joint State Broadcaster
    # ========================
    joint_state_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[
            "joint_state_broadcaster",
            "--controller-manager",
            "/controller_manager",
        ],
        output="screen",
    )

    # ========================
    # Diff Drive Controller
    # ========================
    robot_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=[
            "scout_mini_base_controller",
            "--controller-manager",
            "/controller_manager",
        ],
        output="screen",
    )

    # ========================
    # Twist Mux
    # ========================
    twist_mux = Node(
        package="twist_mux",
        executable="twist_mux",
        output="screen",
        parameters=[robot_config_path, {'use_sim_time': use_sim_time}],
        remappings=[
            ("/cmd_vel_out", "/scout_mini_base_controller/cmd_vel_unstamped")
        ],
    )

    # ========================
    # Map Server
    # ========================
    map_server = Node(
        package='nav2_map_server',
        executable='map_server',
        name='map_server',
        output='screen',
        parameters=[{
            'yaml_filename': map_yaml_file,
            'topic_name': 'map',
            'frame_id': 'map',
            'use_sim_time': use_sim_time
        }]
    )

    # ========================
    # AMCL (Localization)
    # ========================
    amcl = Node(
        package='nav2_amcl',
        executable='amcl',
        name='amcl',
        output='screen',
        parameters=[amcl_config_file, {'use_sim_time': use_sim_time}]
    )

    # ========================
    # Lifecycle Manager for Localization
    # ========================
    lifecycle_manager = Node(
        package='nav2_lifecycle_manager',
        executable='lifecycle_manager',
        name='lifecycle_manager_localization',
        output='screen',
        parameters=[{
            'use_sim_time': use_sim_time,
            'autostart': True,
            'node_names': ['map_server', 'amcl']
        }]
    )

    # ========================
    # RViz
    # ========================
    rviz = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        arguments=['-d', rviz_config_file],
        parameters=[{'use_sim_time': use_sim_time}],
        output='screen'
    )

    return LaunchDescription([
        # Arguments
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='true',
            description='Use simulation clock'
        ),

        # Launch everything in order
        gazebo_server,
        gazebo_client,
        robot_state_publisher,
        spawn_robot,
        joint_state_broadcaster_spawner,
        robot_controller_spawner,
        twist_mux,
        map_server,
        amcl,
        lifecycle_manager,
        rviz,
    ])