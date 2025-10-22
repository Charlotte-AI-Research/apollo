#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import time

class CmdVelTimeout(Node):
    def __init__(self):
        super().__init__('cmd_vel_timeout')
        
        # Timeout in seconds
        self.timeout = 0.5
        
        # Subscribe to teleop commands
        self.sub = self.create_subscription(
            Twist, '/cmd_vel_raw', self.cmd_vel_callback, 10)
        
        # Publish to robot
        self.pub = self.create_publisher(Twist, '/cmd_vel', 10)
        
        # Timer to check for timeout
        self.timer = self.create_timer(0.1, self.check_timeout)
        
        self.last_cmd_time = time.time()
        self.last_cmd = Twist()
        
        self.get_logger().info('Cmd vel timeout node started. Timeout: 0.5s')
        
    def cmd_vel_callback(self, msg):
        # Forward the command immediately
        self.last_cmd = msg
        self.last_cmd_time = time.time()
        self.pub.publish(msg)
        
    def check_timeout(self):
        # If timeout exceeded, send stop command
        time_since_last = time.time() - self.last_cmd_time
        
        if time_since_last > self.timeout:
            # Send zero velocity
            stop_msg = Twist()
            self.pub.publish(stop_msg)

def main(args=None):
    rclpy.init(args=args)
    node = CmdVelTimeout()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
