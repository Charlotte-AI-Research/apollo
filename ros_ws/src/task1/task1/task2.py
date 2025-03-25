import rclpy
from rclpy.node import Node
import numpy as np
import pyrealsense2 as rs
from ultralytics import YOLO
from geometry_msgs.msg import Twist
import time

class RobotController(Node):
    def __init__(self):
        super().__init__('robot_controller')
        self.stop_indicator = False
        self.cmd_vel_publisher = self.create_publisher(Twist, '/cmd_vel', 10)

    def move(self, linear_speed=0.0, angular_speed=0.0, duration=1.0, pipeline=None, model=None):
        """
        Move the robot with real-time stop sign detection.
        :param linear_speed: Forward speed (m/s)
        :param angular_speed: Rotation speed (rad/s)
        :param duration: Movement duration in seconds
        :param pipeline: RealSense camera pipeline
        :param model: YOLOv8 model for detection
        """
        twist = Twist()
        twist.linear.x = linear_speed
        twist.angular.z = angular_speed
        self.cmd_vel_publisher.publish(twist)

        start_time = time.time()
        while time.time() - start_time < duration:
            # Stop mid-movement if stop sign is detected
            if self.detect_stop_sign(pipeline, model):
                break
            time.sleep(0.1) # Small delay

        # Stop robot
        twist.linear.x = 0.0
        twist.angular.z = 0.0
        self.cmd_vel_publisher.publish(twist)

    def detect_stop_sign(self, pipeline, model):
        """Detects a stop sign in the camera feed."""
        if pipeline is None or model is None:
            return False

        frames = pipeline.wait_for_frames()
        color_frame = frames.get_color_frame()
        if not color_frame:
            return False

        color_image = np.asanyarray(color_frame.get_data())
        results = model.track(color_image, verbose=False, persist=True, tracker="botsort.yaml")

        for result in results:
            if result.boxes is not None:
                for cls_id in result.boxes.cls:
                    cls_name = model.names[int(cls_id)]
                    print(f"Detected class: {cls_name}")
                    if cls_name == "stop sign":
                        self.stop_indicator = True
                        print("Stop sign detected, stopping.")
                        return True

        return False

def main(args=None):
    rclpy.init(args=args)
    robot_controller = RobotController()

    # Initialize RealSense pipeline
    pipeline = rs.pipeline()
    config = rs.config()
    config.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)
    config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)
    pipeline.start(config)

    model = YOLO("yolov8n.pt")

    # Movement sequence (speed, turn, duration)
    movement_sequence = [
        (0.5, 0.0, 3),
        (0.0, 1.0, 2),
        (0.5, 0.0, 2),
        (0.0, -1.0, 2),
        (0.5, 0.0, 2),
    ]

    try:
        for linear_speed, angular_speed, duration in movement_sequence:
            if robot_controller.stop_indicator:
                break  # Stop completely if already detected

            # Move and check for stop signs mid-motion
            robot_controller.move(linear_speed, angular_speed, duration, pipeline, model)

            if robot_controller.stop_indicator:
                break  # Stop sequence immediately if needed

    finally:
        robot_controller.destroy_node()
        rclpy.shutdown()
        pipeline.stop()
        print("ROS 2 node stopped.")

if __name__ == '__main__':
    main()
