cmake_minimum_required(VERSION 3.5)
project(scout_mini_hardware)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(
  DEPENDENCIES
  rclcpp
  hardware_interface
  pluginlib
  realtime_tools
  std_msgs
  can_msgs
  ros2_socketcan
  ros2_socketcan_msgs
  scout_mini_msgs
)

find_package(ament_cmake REQUIRED)
foreach(Dependency IN ITEMS ${DEPENDENCIES})
  find_package(${Dependency} REQUIRED)
endforeach()

add_library(
  ${PROJECT_NAME}
  SHARED
  src/scout_mini_hardware.cpp
)
target_link_libraries(${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PRIVATE include)
ament_target_dependencies(${PROJECT_NAME} ${DEPENDENCIES})

pluginlib_export_plugin_description_file(hardware_interface scout_mini_hardware.xml)

install(
  TARGETS ${PROJECT_NAME} 
  DESTINATION lib
)

install(
  DIRECTORY include
  DESTINATION include
)

ament_export_dependencies(${DEPENDENCIES})
ament_export_libraries(${PROJECT_NAME})
ament_export_include_directories(include)

ament_package()