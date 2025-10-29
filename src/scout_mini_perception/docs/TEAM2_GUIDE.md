# Team 2: Depth Estimation

# General Overview
Subscribe to Team 1's target person detections and the RealSense depth camera stream. When a target is detected, extract depth values from the center region of the target's bounding box (avoiding noisy edges). Filter out invalid depth readings, calculate the median distance, and apply temporal smoothing to reduce jitter. Use camera intrinsic parameters to convert the target's pixel coordinates into a lateral angle (how far left or right of center). Publish a custom message with distance, angle, and confidence metrics that Team 3 will use for robot control.

---

## What You're Building

**Node Name:** `depth_estimator_node.py`

**Location:** `scout_mini_perception/nodes/depth_estimator_node.py`

---

## ROS2 Concepts

### What is a Node?
A ROS2 node is a running program that performs a specific task. Your node will process camera images and detect people.

### What is a Topic?
Topics are named channels that nodes use to send messages to each other. Think of it like a radio station - one node broadcasts on a topic, and other nodes tune in to receive the messages.

### What is Subscribe/Publish?
- **Subscribe:** Your node listens to a topic to receive messages (like tuning into a radio station)
- **Publish:** Your node sends messages on a topic for others to receive (like broadcasting on a radio station)

### What is Synchronization?
You need data from multiple topics (target location, depth image, camera info) that arrive at slightly different times. You need to match them up correctly.

### What is a Transform (TF2)?
Different parts of the robot have their own coordinate systems. The camera sees in "camera frame" but the robot thinks in "base_link frame". Transforms convert positions between these coordinate systems.

### What is a Message?
A message file (.msg) is like a data template or form that defines what information gets sent between ROS2 nodes. Think of it like designing a custom envelope that can carry specific types of information. 

### Why Do We Need Custom Messages? 
ROS2 comes with many built-in message types (like Image, String, Twist), but sometimes you need to send a specific combination of data that doesn't exist yet. That's when you create a custom message. Example: You need to send information about a detected person, including:

Whether a target was found
The bounding box coordinates
The center position
A confidence score
No single built-in message has all of these, so you create a custom message.

---

## Possible Pipeline (Could change if needed)

```
Team 1's Node
    ↓
/target_person (you subscribe here)
    
Depth Camera
    ↓
/camera/depth/aligned_to_color/image_raw (you subscribe here)
    
Camera Parameters
    ↓
/camera/color/camera_info (you subscribe here)
    
    ↓
Your Node (depth_estimator_node)
    ↓
/target_state (you publish here)
    ↓
Team 3's Node
```

---

## Implementation (Most of the folders and files have already been created.)

### Step 1: Create ROS2 Node and Subscriptions
- Create a class that inherits from `Node`
- Name your node: `depth_estimator_node`
- Subscribe to three topics:
  - `/target_person` from Team 1
  - `/camera/depth/aligned_to_color/image_raw` from RealSense
  - `/camera/color/camera_info` from RealSense

### Step 2: Understand the Depth Image
- **What it is:** A 2D image where each pixel contains a distance value (in millimeters)
- **What "aligned" means:** The depth pixels match up exactly with color pixels
  - Pixel (100, 200) in color image = Pixel (100, 200) in depth image
  - This makes it easy to look up depth for any detection
- **Invalid values:** Some pixels have no depth (0, NaN, or very large numbers)
  - Happens with reflective surfaces, transparent objects, or out of range

### Step 3: Understand Camera Info
- **What it contains:** Camera calibration parameters
- **Intrinsics:** Mathematical properties of the camera lens
  - **Focal length (fx, fy):** How much the camera "zooms" (in pixels)
  - **Principal point (cx, cy):** Center of the image where optical axis hits
- **Why you need it:** To convert from 2D pixel coordinates to 3D angles

### Step 4: Sample Depth from Target Bounding Box
When you receive a target person message from Team 1:
- Check if `target_found` is true (if false, skip processing)
- Extract the bounding box coordinates (x, y, width, height)
- **Important:** Don't sample the entire box - edges are noisy
- Sample only the **center 50%** of the bounding box
  - If box is 100 pixels wide, only sample middle 50 pixels
  - This gives more reliable depth values
- Extract all depth values from this center region
- You now have an array of depth measurements

### Step 5: Filter Invalid Depth Values
Not all depth values are trustworthy. Remove:
- **Values less than 0.3 meters:** Too close, likely error
- **Values greater than 5.0 meters:** Too far, unreliable
- **Zero values:** Sensor couldn't measure
- **NaN values:** Invalid/missing data
- Keep only the valid depth samples in a clean list

### Step 6: Calculate Distance to Person
- From your valid depth samples, calculate the **median** (not mean)
  - Median is more robust to outliers than average
  - If you have [2.0, 2.1, 2.0, 8.5, 2.1], median is 2.1 (ignores the 8.5 outlier)
- Convert to meters if needed (RealSense may give millimeters)
- This median value is your **distance to the person**
- Apply smoothing to reduce jitter:
  - Simple method: `smoothed_distance = 0.7 * old_distance + 0.3 * new_distance`
  - This filters out noise while staying responsive

### Step 7: Calculate Lateral Angle
You need to know if the person is left, right, or centered:

**The math:**
- Get image center X: `image_center_x = image_width / 2` (usually 320 for 640-wide image)
- Get person center X from Team 1: `person_center_x` (from center_u field)
- Calculate pixel offset: `delta_x = person_center_x - image_center_x`
  - Positive = person is to the right
  - Negative = person is to the left
  - Zero = person is centered
- Get focal length from camera_info: `fx` (it's in the K matrix)
- Convert to angle: `angle = arctan(delta_x / fx)`
  - Use atan or atan2 function
  - Result is in radians
- Apply smoothing to angle as well

**What this means:**
- angle = 0 rad → person is centered
- angle > 0 → person is to the right
- angle < 0 → person is to the left

### Step 8: Calculate Confidence Score
Track how good your depth data is:
- Count valid samples vs total samples
- Formula: `confidence = valid_samples / total_samples`
- Example: If 80 out of 100 depth pixels were valid, confidence = 0.8
- Team 3 uses this to know when to trust your data
- Low confidence (<0.5) means Team 3 should slow down or stop

### Step 9: Optional - Estimate Velocity
Track how distance changes over time:
- Store previous distance and timestamp
- Calculate: `velocity = (current_distance - previous_distance) / time_elapsed`
- Positive velocity = person moving away
- Negative velocity = person moving toward robot
- Helps Team 3 be more proactive

### Step 10: Create and Publish Message
- Create a `TargetState` message
- Fill in all fields:
  - **header:** Timestamp from the depth image
  - **target_found:** Pass through from Team 1
  - **distance:** The median filtered distance in meters
  - **lateral_angle:** The angle in radians
  - **distance_confidence:** Your confidence score (0.0-1.0)
  - **velocity:** Optional, how fast distance is changing
- Publish this message on `/target_state` topic
- Publish at 10-20 Hz for responsive control

---

### Step 11: Configuration File

**File:** `config/params.yaml`

**What is it?**
A configuration file that lets you adjust depth processing parameters without changing code. Essential for tuning filtering and smoothing.

**How to use it:**
In your node's `__init__`, declare and read parameters:
```python
self.declare_parameter('min_depth', 0.3)
self.min_depth = self.get_parameter('min_depth').value
```

**Parameters you should load:**

```yaml
depth_estimator_node:
  ros__parameters:
    min_depth: 0.3                    # Minimum valid depth in meters
    max_depth: 5.0                    # Maximum valid depth in meters
    smoothing_factor: 0.7             # Weight for previous value (0.0-1.0)
    sample_ratio: 0.5                 # Fraction of bbox to sample (0.5 = center 50%)
```

**When to tune these parameters:**

| Parameter | Tune if... | Try adjusting... |
|-----------|-----------|------------------|
| `min_depth` | Getting noise from very close objects | Increase to 0.5m |
| `max_depth` | Need to detect people further away | Increase to 6.0-7.0m |
| `smoothing_factor` | Distance jumps around too much | Increase to 0.8-0.9 (more smoothing) |
| `smoothing_factor` | Too much lag/slow response | Decrease to 0.5-0.6 (less smoothing) |
| `sample_ratio` | Low confidence scores | Increase to 0.6-0.7 (larger sample area) |
| `sample_ratio` | Getting edge noise in depth | Decrease to 0.4 (smaller center region) |

**Understanding smoothing_factor:**
- `0.9` = New reading has 10% influence (very smooth, slow response)
- `0.7` = New reading has 30% influence (balanced - recommended)
- `0.5` = New reading has 50% influence (quick response, more jitter)
- Formula: `new = smoothing_factor × old + (1 - smoothing_factor) × measurement`

**To launch with config file:**
```bash
ros2 run scout_mini_perception depth_estimator_node --ros-args --params-file config/params.yaml
```

---

## Custom Message Definition

**File:** `msg/TargetState.msg`

**Fields you need to define:**
```
std_msgs/Header header
bool target_found
float32 distance
float32 lateral_angle
float32 distance_confidence
float32 velocity
```

---

## Testing Your Node (Will only work on the robot)

### Basic Testing Commands
```bash
# Terminal 1: Launch camera
ros2 launch realsense2_camera rs_launch.py

# Terminal 2: Run Team 1's node
ros2 run scout_mini_perception person_detector_node

# Terminal 3: Run your node
ros2 run scout_mini_perception depth_estimator_node

# Terminal 4: Check your output
ros2 topic echo /target_state
```

### Test Scenarios with Measurements
1. **Person at 1 meter:** Use tape measure, verify your published distance is close
2. **Person at 2 meters:** Verify accuracy
3. **Person at 3 meters:** Verify accuracy
4. **Person moves left:** Verify angle becomes negative
5. **Person moves right:** Verify angle becomes positive
6. **Person centered:** Verify angle is near zero
7. **Person walks away:** Verify distance increases smoothly
8. **Person walks toward:** Verify distance decreases smoothly

---

## Key Concepts

### Depth Camera Accuracy
- Most accurate: 1-3 meters
- Less accurate: <0.5m or >4m
- Fails on: reflective surfaces, transparent objects, very dark objects

### Median vs Mean
- **Mean (average):** Sum all values / count - affected by outliers
- **Median (middle value):** Sort all values, pick middle one - ignores outliers
- Use median for depth because outliers are common

### Smoothing and Lag
- More smoothing = less jitter, but more lag
- Less smoothing = more responsive, but more jitter
- Find balance: 0.7/0.3 mix is a good starting point

### Coordinate Frames
- **camera_link:** Camera's perspective (forward = Z axis)
- **base_link:** Robot's perspective (forward = X axis)
- May need to transform if Team 3 wants base_link coordinates

---

## What Team 3 Needs From You

Team 3 will use your `/target_state` message to control the robot:
- **Accurate distance:** Within 0.1-0.2 meters of actual
- **Accurate angle:** Within 5-10 degrees of actual
- **Smooth values:** Not jumping around randomly
- **Quick response:** Less than 100ms lag from smoothing
- **Clear confidence:** So they know when data is unreliable

---

## Common Issues and Solutions

**Issue:** Distance values jump around wildly
- **Solution:** Increase smoothing factor (try 0.8/0.2 or 0.9/0.1)

**Issue:** Distance is consistently wrong (e.g., off by 0.5m)
- **Solution:** Check depth image units (mm vs meters), verify sampling region

**Issue:** Can't get valid depth samples
- **Solution:** Person might be too close/far, or camera isn't working properly

**Issue:** Angle calculation seems backwards
- **Solution:** Check sign of delta_x calculation, verify focal length is correct

**Issue:** Low confidence scores all the time
- **Solution:** Widen valid depth range, or check if depth camera is functioning

---

## Success Criteria

- Distance accuracy within 0.2m at 1-3m range
- Angle accuracy within 10 degrees
- Smooth output (minimal jitter)
- Confidence metric reflects data quality
- Handles target loss gracefully (target_found = false)