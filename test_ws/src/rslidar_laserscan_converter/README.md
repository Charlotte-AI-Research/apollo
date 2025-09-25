# RSLidar LaserScan Converter

A ROS 2 Humble package that converts RoboSense organized PointCloud2 data to LaserScan format for AMCL localization.

## Overview

This package solves the issue where `pointcloud_to_laserscan` fails to convert organized 3D point clouds (height > 1) from RoboSense LiDAR sensors. It provides two conversion modes:

1. **Ring extraction**: Extract a specific ring from the organized point cloud
2. **Z-slice filtering**: Extract points within a configurable height range

## Features

- ✅ Handles organized PointCloud2 data (height=16, width=1800 for RSHELIOS-16P)
- ✅ Configurable conversion modes (ring or z-slice)
- ✅ Proper LaserScan message generation for AMCL
- ✅ Configurable parameters via YAML files
- ✅ 10 Hz publishing rate matching LiDAR frequency

## Installation

1. Copy this package to your ROS 2 workspace:
```bash
cp -r rslidar_laserscan_converter ~/test_ws/src/
```

2. Build the package:
```bash
cd ~/test_ws
colcon build --packages-select rslidar_laserscan_converter
source install/setup.bash
```

## Usage

### Standalone Launch

```bash
# Ring extraction mode (default)
ros2 launch rslidar_laserscan_converter rslidar_laserscan_launch.py

# Z-slice filtering mode
ros2 launch rslidar_laserscan_converter rslidar_laserscan_launch.py config_file:=config/z_slice_mode.yaml

# Custom parameters
ros2 launch rslidar_laserscan_converter rslidar_laserscan_launch.py target_ring:=10 conversion_mode:=ring
```

### Integration with Localization

Replace the old `pointcloud_to_laserscan` node in your `localization_launch.py` with this converter.

## Configuration

### Ring Mode (Default)
Extracts a specific ring from the organized point cloud. Best for consistent horizontal scanning.

### Z-Slice Mode
Extracts all points within a height range. Provides more data but may include noise from multiple elevations.

See `config/rslidar_converter.yaml` for detailed parameter documentation.

## Troubleshooting

### No /scan messages published
- Check that `/rslidar_points` is being published: `ros2 topic echo /rslidar_points`
- Verify the point cloud is organized: `ros2 topic info /rslidar_points -v`
- Check converter logs: `ros2 node list` and look for warnings

### AMCL not localizing
- Verify `/scan` frame_id matches your URDF: Should be `laser_link`
- Check scan range parameters match your environment
- Ensure map and laser data are in reasonable coordinate frames

## Topics

### Subscribed
- `/rslidar_points` (sensor_msgs/PointCloud2): Input organized point cloud

### Published
- `/scan` (sensor_msgs/LaserScan): Output laser scan for AMCL

## Parameters

| Parameter | Type | Default | Description |
|-----------|------|---------|-------------|
| `input_topic` | string | `/rslidar_points` | Input PointCloud2 topic |
| `output_topic` | string | `/scan` | Output LaserScan topic |
| `frame_id` | string | `laser_link` | Frame ID for LaserScan |
| `conversion_mode` | string | `ring` | Mode: `ring` or `z_slice` |
| `target_ring` | int | 8 | Ring number for ring mode (0-15) |
| `z_min` | double | -0.02 | Min Z for z_slice mode (m) |
| `z_max` | double | 0.02 | Max Z for z_slice mode (m) |
| `range_min` | double | 0.1 | Minimum scan range (m) |
| `range_max` | double | 30.0 | Maximum scan range (m) |

## License

Apache-2.0