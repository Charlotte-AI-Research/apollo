cmake_minimum_required(VERSION 3.5)
project(scout_mini_base)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(
  DEPENDENCIES
  ros2_control
  ros2_controllers
  twist_mux
)

find_package(ament_cmake REQUIRED)
foreach(Dependency IN ITEMS ${DEPENDENCIES})
  find_package(${Dependency} REQUIRED)
endforeach()

install(
  DIRECTORY config launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()