import rclpy
from rclpy.node import Node
import math
from geometry_msgs.msg import Twist, PoseStamped
from scout_mini_msgs.msg import DistanceMessage

from tf2_ros import Buffer, TransformListener
from tf2_geometry_msgs import do_transform_pose
from rclpy.duration import Duration


class FollowerNode(Node):
    def __init__(self):
        super().__init__('follower_node')

        self.TARGET_DISTANCE = 1.0
        self.TARGET_HUMAN_ID = 1
        self.is_aligned = False

        self.target_pose = None  # PoseStamped

        # ROS2 interfaces
        self.subscription = self.create_subscription(
            DistanceMessage,
            'distance_topic',
            self.distance_callback,
            10
        )
        self.cmd_vel_publisher = self.create_publisher(Twist, '/cmd_vel', 10)

        # TF2 setup
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # Control loop at 10 Hz
        self.control_timer = self.create_timer(0.1, self.control_loop)

        self.get_logger().info("FollowerNode with TF2 initialized.")

    def distance_callback(self, msg):
        if msg.human_id == self.TARGET_HUMAN_ID:
            # Wrap Pose in a PoseStamped so we can use TF2
            stamped = PoseStamped()
            stamped.header.frame_id = 'odom'  # Assume all test poses are in 'odom'
            stamped.header.stamp = self.get_clock().now().to_msg()
            stamped.pose = msg.pose
            self.target_pose = stamped

    def control_loop(self):
        if self.target_pose is None:
            return

        try:
            # Transform the human's pose into the robot's local frame
            transform = self.tf_buffer.lookup_transform(
                'base_link',  # target frame
                self.target_pose.header.frame_id,  # source frame (odom)
                rclpy.time.Time(),
                timeout=Duration(seconds=0.5)
            )

            transformed_pose = do_transform_pose(self.target_pose, transform)
            x = transformed_pose.pose.position.x
            y = transformed_pose.pose.position.y

            angle = math.atan2(y, x)
            distance = math.sqrt(x**2 + y**2)
            distance_error = distance - self.TARGET_DISTANCE

            twist = Twist()

            if abs(angle) > 0.2:
                twist.angular.z = angle * 0.8
                twist.linear.x = 0.0
                self.is_aligned = False
            else:
                self.is_aligned = True

            if self.is_aligned and distance_error > 0.03:
                twist.linear.x = min(0.4, distance_error * 0.5)
                twist.angular.z = 0.0

            self.cmd_vel_publisher.publish(twist)

            self.get_logger().info(
                f"[TF-FOLLOW] x={x:.2f}, y={y:.2f}, angle={angle:.2f}, dist={distance:.2f}, lin.x={twist.linear.x:.2f}, ang.z={twist.angular.z:.2f}"
            )

        except Exception as e:
            self.get_logger().warn(f"TF2 transform failed: {str(e)}")

    def set_target_distance(self, new_distance):
        self.TARGET_DISTANCE = new_distance

    def get_target_distance(self):
        return self.TARGET_DISTANCE


def main(args=None):
    rclpy.init(args=args)
    follower_node = FollowerNode()
    rclpy.spin(follower_node)
    follower_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
