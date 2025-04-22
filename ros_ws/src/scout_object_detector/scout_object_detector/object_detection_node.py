#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from scout_object_detector.msg import YoloDetection

import pyrealsense2 as rs
import numpy as np
from ultralytics import YOLO

class ObjectDetectionNode(Node):
    def __init__(self):
        super().__init__('object_detection_node')
        self.publisher = self.create_publisher(YoloDetection, 'detected_objects', 10)

        self.pipeline = rs.pipeline()
        self.config = rs.config()
        self.config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)

        try:
            self.pipeline.start(self.config)
            self.get_logger().info("Started RealSense camera stream.")
        except Exception as e:
            self.get_logger().error(f"Failed to start RealSense camera: {e}")
            raise

        self.model = YOLO("yolov8n.pt")
        self.get_logger().info("YOLOv8 model loaded.")

    def run(self):
        while rclpy.ok():
            try:
                frames = self.pipeline.wait_for_frames()
                color_frame = frames.get_color_frame()

                if not color_frame:
                    self.get_logger().warn("No color frame received.")
                    continue

                color_image = np.asanyarray(color_frame.get_data())
                results = self.model.predict(source=color_image, verbose=False)

                for result in results:
                    boxes = result.boxes
                    for i in range(len(boxes.cls)):
                        msg = YoloDetection()

                        box = boxes[i]

                        msg.id = int(box.cls.item())
                        msg.class_label = self.model.names[msg.id]
                        msg.confidence = float(box.conf.item())

                        xmin, ymin, xmax, ymax = box.xyxy[0].tolist()
                        msg.x = int(xmin)
                        msg.y = int(ymin)
                        msg.width = int(xmax - xmin)
                        msg.height = int(ymax - ymin)

                        self.publisher.publish(msg)

                        self.get_logger().info(
                            f"[{msg.class_label}] id={msg.id}, conf={msg.confidence:.2f}, "
                            f"x={msg.x}, y={msg.y}, w={msg.width}, h={msg.height}"
                        )

            except Exception as e:
                self.get_logger().error(f"Detection error: {e}")
                break

    def destroy(self):
        self.pipeline.stop()
        self.get_logger().info("RealSense pipeline stopped.")

def main(args=None):
    rclpy.init(args=args)
    node = ObjectDetectionNode()
    try:
        node.run()
    finally:
        node.destroy()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
