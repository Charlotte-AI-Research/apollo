cmake_minimum_required(VERSION 3.8)
project(scout_object_detector)

find_package(ament_cmake REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

set(msg_files
  "msg/YoloDetection.msg"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
  DEPENDENCIES std_msgs
)

install(PROGRAMS
  scout_object_detector/object_detection_node.py
  DESTINATION lib/${PROJECT_NAME}
  RENAME object_detection_node
)

install(PROGRAMS
  scout_object_detector/object_detection_node.py
  DESTINATION lib/${PROJECT_NAME}
  RENAME detection_node
)

ament_export_dependencies(rosidl_default_runtime)
ament_package()