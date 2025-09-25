import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Pose
from scout_mini_msgs.msg import DistanceMessage  # Same as used in follower_node

class TestDistancePublisher(Node):
    def __init__(self):
        super().__init__('test_distance_publisher')
        self.publisher_ = self.create_publisher(DistanceMessage, 'distance_topic', 10)
        self.timer = self.create_timer(1.0, self.timer_callback)  # Publish every 1 sec
        self.get_logger().info('TestDistancePublisher started.')

    def timer_callback(self):
        msg = DistanceMessage()
        msg.human_id = 1  # Must match TARGET_HUMAN_ID in your follower_node

        # Simulate pose in the 'odom' frame
        msg.pose = Pose()
        msg.pose.position.x = 2.0  # 2 meters ahead
        msg.pose.position.y = 1.0  # 1 meter to the left
        msg.pose.position.z = 0.0

        msg.angle = 0.0  # This field is unused by the follower

        self.publisher_.publish(msg)
        self.get_logger().info(
            f'Published DistanceMessage: x={msg.pose.position.x:.2f}, y={msg.pose.position.y:.2f}'
        )

def main(args=None):
    rclpy.init(args=args)
    node = TestDistancePublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
