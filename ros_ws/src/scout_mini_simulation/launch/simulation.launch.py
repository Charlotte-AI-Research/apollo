from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    urdf_file = os.path.join(
        get_package_share_directory('scout_mini_description'),
        'urdf',
        'scout_mini.urdf'
    )

    if not os.path.exists(urdf_file):
        raise FileNotFoundError(f"URDF file not found at {urdf_file}")

    ros2_control_config = os.path.join(
        get_package_share_directory('scout_mini_simulation'),
        'config',
        'scout_mini.yaml'
    )

    # Gazebo launch
    gazebo = ExecuteProcess(
        cmd=['gazebo', '--verbose', '-s', 'libgazebo_ros_init.so', '-s', 'libgazebo_ros_factory.so'],
        output='screen'
    )

    # Spawn entity
    spawn_entity = Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        arguments=['-entity', 'scout_mini', '-file', urdf_file],
        output='screen'
    )

    # Controller manager
    controller_manager = Node(
        package='controller_manager',
        executable='ros2_control_node',
        parameters=[ros2_control_config],
        output='screen'
    )

    # Return the launch description
    return LaunchDescription([
        gazebo,
        spawn_entity,
        controller_manager
    ])
