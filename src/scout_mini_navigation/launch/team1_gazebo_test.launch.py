#!/usr/bin/env python3
"""
Team 1 Gazebo Testing Launch File
Tests localization (AMCL, map_server, lifecycle) in simulation
Includes automatic velocity timeout for safe teleoperation
"""

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument, ExecuteProcess, SetEnvironmentVariable
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution, Command
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    scout_loc_dir = FindPackageShare('scout_mini_localization')
    scout_nav_dir = FindPackageShare('scout_mini_navigation')
    scout_desc_dir = FindPackageShare('scout_mini_description')
    scout_base_dir = FindPackageShare('scout_mini_base')

    # Parameters
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')
    world_file = LaunchConfiguration('world', default='empty.world')

    nav2_params_file = PathJoinSubstitution([scout_nav_dir, 'config', 'nav2_params.yaml'])

    return LaunchDescription([
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='true',
            description='Use simulation time'
        ),

        DeclareLaunchArgument(
            'world',
            default_value='empty.world',
            description='Gazebo world file'
        ),

        # Start Gazebo
        ExecuteProcess(
            cmd=['gazebo', '--verbose', '-s', 'libgazebo_ros_factory.so', world_file],
            output='screen'
        ),

        # Spawn Scout Mini in Gazebo
        Node(
            package='gazebo_ros',
            executable='spawn_entity.py',
            name='spawn_scout_mini',
            arguments=[
                '-entity', 'scout_mini',
                '-topic', 'robot_description',
                '-x', '0.0',
                '-y', '0.0',
                '-z', '0.1'
            ],
            output='screen'
        ),

        # Robot State Publisher
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{
                'use_sim_time': use_sim_time,
                'robot_description': Command([
                    'xacro ',
                    PathJoinSubstitution([scout_desc_dir, 'urdf', 'scout_mini.urdf.xacro'])
                ])
            }]
        ),

        # Joint State Publisher (for Gazebo)
        Node(
            package='joint_state_publisher',
            executable='joint_state_publisher',
            name='joint_state_publisher',
            parameters=[{'use_sim_time': use_sim_time}]
        ),

        # Map Server
        Node(
            package='nav2_map_server',
            executable='map_server',
            name='map_server',
            output='screen',
            parameters=[
                {'use_sim_time': use_sim_time},
                {'yaml_filename': PathJoinSubstitution([scout_loc_dir, 'maps', '4th_floor.yaml'])}
            ]
        ),

        # AMCL
        Node(
            package='nav2_amcl',
            executable='amcl',
            name='amcl',
            output='screen',
            parameters=[
                nav2_params_file,
                {'use_sim_time': use_sim_time}
            ]
        ),

        # Lifecycle Manager for Localization
        Node(
            package='nav2_lifecycle_manager',
            executable='lifecycle_manager',
            name='lifecycle_manager_localization',
            output='screen',
            parameters=[
                nav2_params_file,
                {'use_sim_time': use_sim_time}
            ]
        ),


        ExecuteProcess(
            cmd=['python3', '/apollo_ws/src/scout_mini_navigation/scripts/cmd_vel_timeout.py'],
            output='screen'
        ),

        # RViz with proper Gazebo navigation config
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=['-d', PathJoinSubstitution([scout_nav_dir, 'rviz', 'gazebo_nav.rviz'])],
            parameters=[{'use_sim_time': use_sim_time}],
            output='screen'
        ),
    ])