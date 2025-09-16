# Import the core ROS 2 Python library
import rclpy

# Import the Node class to create a custom ROS 2 node
from rclpy.node import Node

# Import the standard message type we’ll publish (a simple string)
from std_msgs.msg import String


# This class defines a ROS 2 node that publishes messages to a topic
class ApolloStatusPublisher(Node):
    def __init__(self):
        # Initialize the node and give it a name ('apollo_status_publisher')
        super().__init__('apollo_status_publisher')

        # Create a publisher that sends String messages to the topic '/apollo_status'
        # The '10' is the message queue size (how many messages to buffer)
        self.publisher = self.create_publisher(String, '/apollo_status', 10)

        # Create a timer that triggers a function every 1.0 second
        # Each time it triggers, it will call self.timer_callback()
        self.timer = self.create_timer(1.0, self.timer_callback)

        # Initialize a counter to include in the message (you can customize this logic)
        self.count = 0

    # This function runs once every second because of the timer
    def timer_callback(self):
        # Create a new String message object
        msg = String()

        # Fill the message data with a string that includes the counter value
        msg.data = f'Apollo system alive. Count = {self.count}'

        # Publish the message to the '/apollo_status' topic
        self.publisher.publish(msg)

        # Log the message to the console so we can see it being published
        self.get_logger().info(f'Published: "{msg.data}"')

        # Increment the counter so each message is slightly different
        self.count += 1


# This function is the entry point of the node
def main():
    # Initialize the ROS 2 Python client library
    rclpy.init()

    # Create an instance of the node we just defined
    node = ApolloStatusPublisher()

    # Keep the node running until the process is interrupted (e.g. Ctrl+C)
    rclpy.spin(node)

    # Once the node stops running, clean up
    node.destroy_node()
    rclpy.shutdown()


# This ensures the main() function runs if this script is executed directly
if __name__ == '__main__':
    main()
