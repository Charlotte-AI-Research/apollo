#!/usr/bin/env python3

# Author: Brighten Lee

import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    use_sim_time = LaunchConfiguration("use_sim_time", default="false")

    rviz2_config_dir = LaunchConfiguration(
        "rviz_config_dir",
        default=os.path.join(
            get_package_share_directory("scout_mini_description"), "rviz", "scout_mini.rviz"
        ),
    )

    return LaunchDescription(
        [
            Node(
                package="rviz2",
                executable="rviz2",
                name="rviz2",
                output="screen",
                arguments=["-d", rviz2_config_dir],
                parameters=[{"use_sim_time": use_sim_time}],
            ),
        ]
    )
