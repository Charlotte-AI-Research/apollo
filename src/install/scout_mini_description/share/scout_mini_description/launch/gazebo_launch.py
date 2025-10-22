#!/usr/bin/env python3

import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, ExecuteProcess
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import Command, FindExecutable, PathJoinSubstitution, LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    # Get package directories
    pkg_gazebo_ros = get_package_share_directory('gazebo_ros')
    pkg_scout_mini_description = get_package_share_directory('scout_mini_description')
    pkg_scout_mini_base = get_package_share_directory('scout_mini_base')

    # Launch configuration variables
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')
    world_name = LaunchConfiguration('world', default='')

    # Paths
    gazebo_urdf_path = os.path.join(pkg_scout_mini_description, 'urdf', 'scout_mini_gazebo.urdf.xacro')
    robot_config_path = os.path.join(pkg_scout_mini_base, 'config', 'scout_mini.yaml')

    # Robot description
    robot_description_content = Command(
        [
            PathJoinSubstitution([FindExecutable(name="xacro")]),
            " ",
            gazebo_urdf_path,
        ]
    )
    robot_description = {"robot_description": robot_description_content}

    # Robot state publisher
    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        output="screen",
        parameters=[robot_description, {'use_sim_time': use_sim_time}],
    )

    # Gazebo server
    gazebo_server = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_gazebo_ros, 'launch', 'gzserver.launch.py')
        ),
        launch_arguments={'world': world_name, 'verbose': 'true'}.items()
    )

    # Gazebo client
    gazebo_client = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_gazebo_ros, 'launch', 'gzclient.launch.py')
        )
    )

    # Spawn robot
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

    # Controller manager and spawners
    controller_manager = Node(
        package="controller_manager",
        executable="ros2_control_node",
        parameters=[robot_description, robot_config_path, {'use_sim_time': use_sim_time}],
        output="screen",
    )

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

    # Twist mux
    twist_mux_node = Node(
        package="twist_mux",
        executable="twist_mux",
        output="screen",
        parameters=[robot_config_path, {'use_sim_time': use_sim_time}],
        remappings={
            ("/cmd_vel_out", "/scout_mini_base_controller/cmd_vel_unstamped")
        },
    )

    return LaunchDescription([
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='true',
            description='Use simulation clock if true'
        ),
        DeclareLaunchArgument(
            'world',
            default_value='',
            description='Path to world file'
        ),
        
        # Launch Gazebo
        gazebo_server,
        gazebo_client,
        
        # Robot setup
        robot_state_publisher_node,
        spawn_robot,
        
        # Controllers (commented out for now - will be managed by Gazebo plugin)
        # controller_manager,
        # joint_state_broadcaster_spawner,
        # robot_controller_spawner,
        # twist_mux_node,
    ])