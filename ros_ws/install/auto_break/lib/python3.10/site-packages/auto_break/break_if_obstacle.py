import pyrealsense2 as rs
from ultralytics import YOLO
import numpy as np
import cv2
import math
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

# Represent a pixel/point on screen
class Point:
    def __init__(self, cls, x, y, depth):
        self.cls = cls
        self.x = x
        self.y = y
        self.depth = depth
    
    def toString(self):
        return f'{self.cls} at ({self.x},{self.y}): {float(self.depth):.3f}m'

# Load model
model = YOLO("yolov8m.pt")

classNames = ["person", "bicycle", "car", "motorbike", "aeroplane", "bus", "train", "truck", "boat",
                "traffic light", "fire hydrant", "stop sign", "parking meter", "bench", "bird", "cat",
                "dog", "horse", "sheep", "cow", "elephant", "bear", "zebra", "giraffe", "backpack", "umbrella",
                "handbag", "tie", "suitcase", "frisbee", "skis", "snowboard", "sports ball", "kite", "baseball bat",
                "baseball glove", "skateboard", "surfboard", "tennis racket", "bottle", "wine glass", "cup",
                "fork", "knife", "spoon", "bowl", "banana", "apple", "sandwich", "orange", "broccoli",
                "carrot", "hot dog", "pizza", "donut", "cake", "chair", "sofa", "pottedplant", "bed",
                "diningtable", "toilet", "tvmonitor", "laptop", "mouse", "remote", "keyboard", "cell phone",
                "microwave", "oven", "toaster", "sink", "refrigerator", "book", "clock", "vase", "scissors",
                "teddy bear", "hair drier", "toothbrush"
                ]

# ROS 2 Node to Stop Robot
class RobotStopNode(Node):
    def __init__(self):
        super().__init__('robot_stop_node')
        self.publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        
    def stop_robot(self, duration=1.0, rate=10):
        stop_msg = Twist()
        start_time = self.get_clock().now()
        
        while (self.get_clock().now() - start_time).nanoseconds / 1e9 < duration:
            self.publisher.publish(stop_msg)
            rclpy.spin_once(self, timeout_sec=1.0 / rate)

        self.get_logger().info("Stopping the robot due to low TTC.")

    def reverse_robot(self, duration=3.0, rate=10):
        reverse_msg = Twist()
        reverse_msg.linear.x = -0.2
        reverse_msg.angular.z = 0.0

        start_time = self.get_clock().now()
        while (self.get_clock().now() - start_time).nanoseconds / 1e9 < duration:
            self.publisher.publish(reverse_msg)
            rclpy.spin_once(self, timeout_sec=1.0 / rate)
        
        self.get_logger().info("Reversing robot due to close proximity to object.")


def main(args=None):
    rclpy.init(args=args)
    node = RobotStopNode()
    
    # Realsense pipeline setup
    pipeline = rs.pipeline()
    config = rs.config()
    config.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)
    config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)
    pipeline.start(config)

    previous_depth = None
    velocity = 0  # m/s
    TTC = float('inf')  # initialized as big value
    object_info = {}

    try:
        while True:
            frames = pipeline.wait_for_frames()
            depth_frame = frames.get_depth_frame()
            color_frame = frames.get_color_frame()

            if not depth_frame or not color_frame:
                continue

            # Process images for bounding boxes
            depth_image = np.asanyarray(depth_frame.get_data())
            color_image = np.asanyarray(color_frame.get_data())
            depth_colormap = cv2.applyColorMap(cv2.convertScaleAbs(depth_image, alpha=0.03), cv2.COLORMAP_JET)

            points = []
            center_x = depth_colormap.shape[1] // 2
            center_y = depth_colormap.shape[0] // 2
            points.append(Point('center', center_x, center_y, 0))

            results = model.track(color_image, verbose=False, persist=True, tracker="botsort.yaml")

            for result in results:
                boxes = result.boxes
                threshold = 0.6

                for box in boxes:
                    confidence = math.ceil((box.conf[0] * 100)) / 100
                    if confidence < threshold:
                        continue

                    object_id = box.id.item() if box.id is not None else None

                    cls = classNames[int(box.cls[0])]

                    if cls != 'person':
                        break

                    print(cls)

                    x1, y1, x2, y2 = map(int, box.xyxy[0])
                    width, height = depth_frame.get_width(), depth_frame.get_height()

                    depth_arr = np.asanyarray(depth_frame.get_data()).reshape((height, width))
                    bbox_depths = depth_arr[y1:y2, x1:x2]

                    valid_depths = bbox_depths[bbox_depths > 0]

                    if valid_depths.size > 0:
                        min_depth_value = np.min(valid_depths)
                        min_depth_y, min_depth_x = np.unravel_index(np.argmin(bbox_depths), bbox_depths.shape)
                        min_depth_y += y1
                        min_depth_x += x1
                    else:
                        min_depth_value = 10
                        min_depth_x, min_depth_y = (x1 + x2) // 2, (y1 + y2) // 2

                    # Store point with corrected depth
                    new_point = Point(cls, min_depth_x, min_depth_y, min_depth_value)
                    points.append(new_point)

                    if object_id not in object_info:
                        object_info[object_id] = {'depths': [min_depth_value]}
                    else:
                        object_info[object_id]['depths'].append(min_depth_value)

                    # Exponential smoothing and TTC calculation
                    alpha = 0.35
                    r = 0.01
                    new_depth = object_info[object_id]["depths"][-1]
                    last_depth_avg = object_info[object_id].get("curr_depth_avg", new_depth)
                    curr_depth_avg = alpha * new_depth + (1 - alpha) * last_depth_avg
                    object_info[object_id]["curr_depth_avg"] = curr_depth_avg

                    delta_depth = curr_depth_avg - last_depth_avg
                    delta_time = 0.0333
                    velocity = delta_depth / delta_time

                    if velocity < 0:
                        TTC = curr_depth_avg / abs(velocity)
                    else:
                        TTC = 1000

                    if TTC < 5:
                        # Stop robot if TTC < 5 seconds
                        node.stop_robot()

                    if curr_depth_avg < 1.5:
                        node.reverse_robot()
                
            cv2.imshow('Depth Stream', depth_colormap)
            if cv2.waitKey(1) == 27:
                break

    finally:
        pipeline.stop()
        rclpy.shutdown()
        cv2.destroyAllWindows()

if __name__ == '__main__':
    main()
