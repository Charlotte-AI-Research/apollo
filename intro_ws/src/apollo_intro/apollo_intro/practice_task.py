#!/usr/bin/env python3

# TODO: Import rclpy and Node
# TODO: Import String message type from std_msgs.msg


# TODO: Create a class called CustomPublisherNode that inherits from Node
class CustomPublisherNode(Node):
    def __init__(self):
        # TODO: Initialize the node with a name (e.g., 'custom_publisher_node')

        # TODO: Create a publisher that sends String messages to '/custom_topic_name'

        # TODO: Create a timer that calls a function every second (1.0)

        pass

    # TODO: Define a function called publish_message (or similar)
    # Inside it:
    # - Create a String message
    # - Set msg.data to a custom message (your name, number, timestamp, etc.)
    # - Publish the message
    # - Log the message using self.get_logger().info()


# Required ROS 2 boilerplate for running the node
def main(args=None):
    # TODO: Initialize ROS 2 (rclpy.init)

    # TODO: Create the node and spin it

    # TODO: On shutdown, destroy the node and call rclpy.shutdown()


# This ensures the script runs when executed directly
if __name__ == '__main__':
    main()
