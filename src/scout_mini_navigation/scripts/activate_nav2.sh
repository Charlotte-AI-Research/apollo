#!/bin/bash

# Wait for nodes to be ready
sleep 5

echo "Activating localization nodes..."
ros2 lifecycle set /lifecycle_manager_localization configure
ros2 lifecycle set /lifecycle_manager_localization activate

sleep 2

echo "Activating navigation nodes..."
ros2 lifecycle set /lifecycle_manager_navigation configure
ros2 lifecycle set /lifecycle_manager_navigation activate

echo "Nav2 stack activated!"
