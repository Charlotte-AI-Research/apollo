cmake_minimum_required(VERSION 3.8)
project(scout_mini_localization)

# Compiler settings
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Core build dependency
find_package(ament_cmake REQUIRED)

# Install launch files
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

# Install configuration files
install(DIRECTORY config
  DESTINATION share/${PROJECT_NAME}
)

# Install map files (PGM + YAML)
install(DIRECTORY maps
  DESTINATION share/${PROJECT_NAME}
)

# Install RViz configuration files
install(DIRECTORY rviz
  DESTINATION share/${PROJECT_NAME}
)

# Testing
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
