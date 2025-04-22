#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from follow_human.msg import TrackedObject

from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
from ultralytics import YOLO

class TrackingNode(Node):
    def __init__(self):
        super().__init__('tracking_node')

        self.publisher = self.create_publisher(TrackedObject, '/tracked_objects', 10)

        self.bridge = CvBridge()
        self.subscription = self.create_subscription(
            Image,
            '/camera/color/image_raw',
            self.image_callback,
            10
        )

        self.model = YOLO("yolov8n.pt")
        self.get_logger().info("YOLOv8 model loaded with tracking.")
        self.get_logger().info("TrackingNode subscribed to /camera/color/image_raw.")

    def image_callback(self, msg):
        try:
            color_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        except Exception as e:
            self.get_logger().error(f"Failed to convert image: {e}")
            return

        try:
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

                    msg_out = TrackedObject()
                    msg_out.id = track_id
                    msg_out.class_label = class_label
                    msg_out.confidence = float(box.conf.item())
                    msg_out.x = int(xmin)
                    msg_out.y = int(ymin)
                    msg_out.width = int(xmax - xmin)
                    msg_out.height = int(ymax - ymin)

                    self.publisher.publish(msg_out)

                    self.get_logger().info(
                        f"[ID {msg_out.id}] {msg_out.class_label}, conf={msg_out.confidence:.2f}, "
                        f"bbox=({msg_out.x},{msg_out.y},{msg_out.width},{msg_out.height})"
                    )

        except Exception as e:
            self.get_logger().error(f"Tracking error: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = TrackingNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
