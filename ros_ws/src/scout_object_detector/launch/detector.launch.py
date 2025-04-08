from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='scout_object_detector',
            executable='detection_node',
            name='object_detection_node',
            output='screen'
        )
    ])