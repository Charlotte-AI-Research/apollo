cmake_minimum_required(VERSION 3.5)
project(scout_mini_msgs)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(std_msgs REQUIRED)

set(
  MSG_FILES
  "msg/DriverState.msg"
  "msg/FaultState.msg"
  "msg/LightCommand.msg"
  "msg/LightState.msg"
  "msg/MotorState.msg"
  "msg/RobotState.msg"
)

rosidl_generate_interfaces(
  ${PROJECT_NAME}
  ${MSG_FILES}
  DEPENDENCIES builtin_interfaces std_msgs
)

ament_export_dependencies(rosidl_default_runtime)

ament_package()