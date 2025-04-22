#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from follow_human.msg import TrackedObject

import pyrealsense2 as rs
import numpy as np
from ultralytics import YOLO

class TrackingNode(Node):
    def __init__(self):                                                                                                                                                                                                                                                                         
        super().__init__('tracking_node')

        self.publisher = self.create_publisher(TrackedObject, '/tracked_objects', 10)

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
        self.get_logger().info("YOLOv8 model loaded with tracking.")

    def run(self):
        while rclpy.ok():
            try:
                frames = self.pipeline.wait_for_frames()
                color_frame = frames.get_color_frame()
                if not color_frame:
                    continue

                color_image = np.asanyarray(color_frame.get_data())

                results = self.model.track(source=color_image, persist=True, verbose=False)

                for result in results:
                    boxes = result.boxes
                    for i in range(len(boxes.cls)):
                        class_id = int(boxes.cls[i].item())
                        class_label = self.model.names[class_id]

                        # Only track people
                        if class_label != 'person':
                            continue

                        box = boxes[i]
                        track_id = int(box.id.item()) if box.id is not None else -1

                        xmin, ymin, xmax, ymax = box.xyxy[0].tolist()

                        msg = TrackedObject()
                        msg.id = track_id
                        msg.class_label = class_label
                        msg.confidence = float(box.conf.item())
                        msg.x = int(xmin)
                        msg.y = int(ymin)
                        msg.width = int(xmax - xmin)
                        msg.height = int(ymax - ymin)

                        self.publisher.publish(msg)

                        self.get_logger().info(
                            f"[ID {msg.id}] {msg.class_label}, conf={msg.confidence:.2f}, "
                            f"bbox=({msg.x},{msg.y},{msg.width},{msg.height})"
                        )

            except Exception as e:
                self.get_logger().error(f"Tracking error: {e}")
                break

    def destroy(self):
        self.pipeline.stop()
        self.get_logger().info("RealSense pipeline stopped.")

def main(args=None):
    rclpy.init(args=args)
    node = TrackingNode()
    try:
        node.run()
    finally:
        node.destroy()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
