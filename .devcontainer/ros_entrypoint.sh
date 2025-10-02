#!/bin/bash
set -e

# Source ROS2 Humble environment
source /opt/ros/humble/setup.bash

# Source Apollo workspace if it exists
if [ -f /apollo_ws/install/setup.bash ]; then
    source /apollo_ws/install/setup.bash
fi

# Execute the command passed to the script
exec "$@"