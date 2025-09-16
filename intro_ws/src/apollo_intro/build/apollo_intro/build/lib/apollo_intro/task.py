#!/usr/bin/env python3

# Import the ROS 2 Python client library
import rclpy
from rclpy.node import Node

# Import a basic built-in message type: String
from std_msgs.msg import String


# Define your custom ROS 2 node by extending the Node base class
class CustomPublisherNode(Node):
    def __init__(self):
        # Initialize the node with a name
        super().__init__('custom_publisher_node')

        # Create a publisher that publishes String messages to '/custom_topic_name'
        # The '10' is the size of the message queue (how many to keep buffered)
        self.publisher = self.create_publisher(String, '/custom_topic_name', 10)

        # Set up a timer to call the publish_message function every second
        self.timer = self.create_timer(1.0, self.publish_message)

        self.count = 0


    def publish_message(self):
        # Create a String message
        msg = String()

        # Set the message data to a custom message
        msg.data = f"Custom message from your node. Count = {self.count}"

        # Publish the message to the topic
        self.publisher.publish(msg)

        # Log the message to the terminal
        self.get_logger().info(f"Published: '{msg.data}'")

        # Increment the counter
        self.count += 1


# Standard ROS 2 Python main entry point
def main(args=None):
    rclpy.init(args=args)
    node = CustomPublisherNode()
    rclpy.spin(node)            # Keeps the node alive until interrupted
    node.destroy_node()         # Clean up the node on shutdown
    rclpy.shutdown()            # Shutdown ROS 2


# This ensures the script runs if you call python3 practice_task.py
if __name__ == '__main__':
    main()
