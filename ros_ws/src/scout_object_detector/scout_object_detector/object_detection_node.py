#!/usr/bin/env python3

# Import ROS 2 core libraries
import rclpy
from rclpy.node import Node

# Import the custom message type defined in scout_object_detector/msg/YoloDetection.msg
from scout_object_detector.msg import YoloDetection

# Import RealSense and OpenCV dependencies
import pyrealsense2 as rs
import numpy as np

# Import YOLOv8 from the Ultralytics library
from ultralytics import YOLO


class ObjectDetectionNode(Node):
    def __init__(self):
        # Initialize the ROS 2 node with a unique name
        super().__init__('object_detection_node')

        # Set up a publisher that sends YoloDetection messages to the topic 'detected_objects'
        self.publisher = self.create_publisher(YoloDetection, 'detected_objects', 10)

        # RealSense camera configuration
        self.pipeline = rs.pipeline()              # Create a RealSense pipeline to manage streaming
        self.config = rs.config()                  # Create a config object to specify stream settings
        self.config.enable_stream(                 # Enable the color stream (RGB camera)
            rs.stream.color, 640, 480, rs.format.bgr8, 30
        )

        # Try starting the camera stream
        try:
            self.pipeline.start(self.config)
            self.get_logger().info("Started RealSense camera stream.")
        except Exception as e:
            self.get_logger().error(f"Failed to start RealSense camera: {e}")
            raise  # Exit if the camera fails to start

        # Load the YOLOv8 object detection model (nano version)
        self.model = YOLO("yolov8n.pt")
        self.get_logger().info("YOLOv8 model loaded.")

    def run(self):
        # Loop continuously while ROS 2 is running
        while rclpy.ok():
            try:
                # Wait for the next camera frame
                frames = self.pipeline.wait_for_frames()
                color_frame = frames.get_color_frame()

                # If no color frame is received, skip this loop iteration
                if not color_frame:
                    self.get_logger().warn("No color frame received.")
                    continue

                # Convert the RealSense color frame to a NumPy image array
                color_image = np.asanyarray(color_frame.get_data())

                # Run object detection using the YOLO model on the current image frame
                results = self.model.predict(source=color_image, verbose=False)

                # Loop through all detected results
                for result in results:
                    boxes = result.boxes

                    # For each detected object (bounding box)
                    for i in range(len(boxes.cls)):
                        msg = YoloDetection()  # Create a new detection message

                        box = boxes[i]  # Get the i-th bounding box

                        # Fill in the detection message fields
                        msg.id = int(box.cls.item())  # Numeric class ID (e.g., 0 = person)
                        msg.class_label = self.model.names[msg.id]  # Human-readable class label
                        msg.confidence = float(box.conf.item())  # Detection confidence score

                        # Get bounding box coordinates
                        xmin, ymin, xmax, ymax = box.xyxy[0].tolist()
                        msg.x = int(xmin)
                        msg.y = int(ymin)
                        msg.width = int(xmax - xmin)
                        msg.height = int(ymax - ymin)

                        # Publish the detection to the ROS 2 topic
                        self.publisher.publish(msg)

                        # Log the detection info in the console
                        self.get_logger().info(
                            f"[{msg.class_label}] id={msg.id}, conf={msg.confidence:.2f}, "
                            f"x={msg.x}, y={msg.y}, w={msg.width}, h={msg.height}"
                        )

            except Exception as e:
                # If anything goes wrong in detection or camera stream, log and break
                self.get_logger().error(f"Detection error: {e}")
                break

    def destroy(self):
        # Cleanly stop the RealSense camera stream
        self.pipeline.stop()
        self.get_logger().info("RealSense pipeline stopped.")


def main(args=None):
    # Initialize ROS 2
    rclpy.init(args=args)

    # Create and run the object detection node
    node = ObjectDetectionNode()
    try:
        node.run()
    finally:
        # When done or interrupted, stop the camera and shut down ROS
        node.destroy()
        rclpy.shutdown()


# This block runs when the script is executed directly
if __name__ == '__main__':
    main()
