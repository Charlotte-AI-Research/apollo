#!/usr/bin/env python3

# Author: Brighten Lee

import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch.substitutions import Command, FindExecutable, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    use_sim_time = LaunchConfiguration("use_sim_time", default="false")
    robot_config_dir = LaunchConfiguration(
        "robot_config_dir",
        default=os.path.join(
            get_package_share_directory("scout_mini_base"), "config", "scout_mini.yaml"
        ),
    )
    robot_description_content = Command(
        [
            PathJoinSubstitution([FindExecutable(name="xacro")]),
            " ",
            PathJoinSubstitution(
                [
                    FindPackageShare("scout_mini_description"),
                    "urdf",
                    "scout_mini.urdf.xacro",
                ]
            ),
        ]
    )
    robot_description = {"robot_description": robot_description_content}

    return LaunchDescription(
        [
            Node(
                package="robot_state_publisher",
                executable="robot_state_publisher",
                name="robot_state_publisher",
                output="screen",
                parameters=[robot_description],
            ),
            Node(
                package="controller_manager",
                executable="ros2_control_node",
                parameters=[robot_description, robot_config_dir],
                output="screen",
            ),
            Node(
                package="controller_manager",
                executable="spawner",
                arguments=[
                    "joint_state_broadcaster",
                    "--controller-manager",
                    "/controller_manager",
                ],
                output="screen",
            ),
            Node(
                package="controller_manager",
                executable="spawner",
                arguments=[
                    "scout_mini_base_controller",
                    "--controller-manager",
                    "/controller_manager",
                ],
                output="screen",
            ),
            Node(
                package="twist_mux",
                executable="twist_mux",
                output="screen",
                parameters=[robot_config_dir],
                remappings={
                    ("/cmd_vel_out", "/scout_mini_base_controller/cmd_vel_unstamped")
                },
            ),
        ]
    )
