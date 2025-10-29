# Team 1: Person Detection & Color Filtering

Detect people in the camera feed, identify which person is wearing bright green, and publish the target person's location for Team 2 to use.

---

## What You're Building

**Node Name:** `person_detector_node.py`

**Location:** `scout_mini_perception/nodes/person_detector_node.py`

---

## ROS2 Concepts

### What is a Node?
A ROS2 node is a running program that performs a specific task. Your node will process camera images and detect people.

### What is a Topic?
Topics are named channels that nodes use to send messages to each other. Think of it like a radio station - one node broadcasts on a topic, and other nodes tune in to receive the messages.

### What is Subscribe/Publish?
- **Subscribe:** Your node listens to a topic to receive messages (like tuning into a radio station)
- **Publish:** Your node sends messages on a topic for others to receive (like broadcasting on a radio station)

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
Camera Hardware
    ↓
/camera/color/image_raw (you subscribe here)
    ↓
Your Node (person_detector_node)
    ↓
/target_person (you publish here)
    ↓
Team 2's Node
```

---

## Implementation (Most of the folders and files have already been created.)

### Step 1: Create ROS2 Node
- Create a class that inherits from `Node`
- Give your node a name: `person_detector_node`
- This is the foundation of your program

### Step 2: Subscribe to Camera Topic
- **Topic name:** `/camera/color/image_raw`
- **Message type:** `sensor_msgs/Image`
- **What it contains:** Raw color images from the RealSense camera
- **Frequency:** 30 frames per second
- Create a callback function that runs every time a new image arrives

### Step 3: Convert ROS Image to OpenCV Format
- ROS2 uses its own image format
- OpenCV (the vision library) uses a different format
- Use **cv_bridge** to convert between them
- This lets you process the image with OpenCV and YOLO

### Step 4: Run Person Detection with YOLOv11s
- Load YOLOv11s model (pre-trained on 80 object classes)
- Filter to only detect "person" class (class ID = 0)
- Ignore the other 79 classes (cars, dogs, chairs, etc.)
- YOLO returns bounding boxes around detected people
- **Bounding box:** A rectangle defined by (x, y, width, height)
  - x, y = top-left corner position in pixels
  - width, height = size of rectangle in pixels

### Step 5: Apply Color Filtering (Note: Can be any bright color based on what the target person is wearing.)
For each detected person:
- Extract the bounding box region from the image
- Convert from BGR color to HSV color space
  - **HSV:** Hue (color type), Saturation (color intensity), Value (brightness)
  - HSV is better for color detection than RGB
- Define what "bright green" means in HSV values:
  - Hue: 50-90 (the green color range)
  - Saturation: 100-255 (vivid, not pale)
  - Value: 100-255 (bright, not dark)
- Count how many pixels in the box fall within this green range
- Calculate percentage: green_pixels / total_pixels_in_box

### Step 6: Select Target Person
- Compare all detected people
- Person with highest green percentage wins
- Set minimum threshold (e.g., must be >30% green to count)
- If no person meets threshold: no target found
- If multiple people have green, pick the one with most green

### Step 7: Calculate Center Point
From the target person's bounding box:
- Center X = x + (width / 2)
- Center Y = y + (height / 2)
- This gives you the pixel coordinates of the person's center
- These coordinates tell you where in the image the person is located

### Step 8: Create and Publish Message
- Create a `TargetPerson` message
- Fill in all the fields:
  - **header:** Contains timestamp (when image was captured)
  - **target_found:** true if target detected, false if not
  - **bbox_x, bbox_y, bbox_width, bbox_height:** The bounding box coordinates
  - **center_u, center_v:** Center point in image (u, v are standard terms for image coordinates)
  - **color_match_score:** Green percentage as decimal (0.6 means 60% green)
  - **confidence:** YOLO's confidence in the detection (0.0-1.0)
- Publish this message on `/target_person` topic
- Publish at 10 Hz (10 times per second) for smooth tracking

---

### Step 9: Configuration File

**File:** `config/params.yaml`

**How to use it:**
In your node's `__init__`, declare and read parameters:
```python
self.declare_parameter('confidence_threshold', 0.5)
self.confidence_threshold = self.get_parameter('confidence_threshold').value
```

**Parameters you should load:**

```yaml
person_detector_node:
  ros__parameters:
    model_path: "yolov11s.pt"              # Path to YOLO model file
    confidence_threshold: 0.5               # Minimum detection confidence (0.0-1.0)
    green_hue_min: 50                       # HSV hue lower bound for green
    green_hue_max: 90                       # HSV hue upper bound for green
    green_sat_min: 100                      # Minimum saturation for vivid green
    green_val_min: 100                      # Minimum brightness for green
    min_green_percentage: 0.3               # Minimum 30% green to be target
```

**When to tune these parameters:**

| Parameter | Tune if... | Try adjusting... |
|-----------|-----------|------------------|
| `confidence_threshold` | Too many false detections | Increase to 0.6-0.7 |
| `confidence_threshold` | Missing real people | Decrease to 0.3-0.4 |
| `green_hue_min/max` | Not detecting green vest | Widen range (try 40-100) |
| `green_sat_min` | Detecting pale/washed-out colors | Increase to 120-150 |
| `green_val_min` | Not working in bright light | Decrease to 80 |
| `min_green_percentage` | Switching between people | Increase to 0.4-0.5 |
| `min_green_percentage` | Not detecting partially visible vest | Decrease to 0.2 |

**To launch with config file:**
```bash
ros2 run scout_mini_perception person_detector_node --ros-args --params-file config/params.yaml
```

---

## Custom Message Definition

**File:** `msg/TargetPerson.msg`

**Fields you need to define:**
```
std_msgs/Header header
bool target_found
float32 bbox_x
float32 bbox_y
float32 bbox_width
float32 bbox_height
float32 center_u
float32 center_v
float32 color_match_score
float32 confidence
```

---

## Testing Your Node (Note: Will only work on the robot)

### Basic Testing Commands
```bash
# Terminal 1: Launch camera
ros2 launch realsense2_camera rs_launch.py

# Terminal 2: Run your node
ros2 run scout_mini_perception person_detector_node

# Terminal 3: Check if your topic is publishing
ros2 topic list | grep target_person
ros2 topic echo /target_person
```

### Test Scenarios
1. **Single person with green:** Should detect and publish target_found=true
2. **Single person without green:** Should publish target_found=false
3. **Multiple people, one with green:** Should select the green person
4. **Person leaves frame:** Should publish target_found=false
5. **Varying lighting:** Should still detect green (may need to adjust HSV ranges)

---

## Key Concepts

### Image Coordinates
- Origin (0,0) is at top-left of image
- X increases going right
- Y increases going down
- For 640x480 image: center is at (320, 240)

### Color Spaces
- **BGR:** Blue-Green-Red (OpenCV's default format)
- **HSV:** Hue-Saturation-Value (better for color detection)
- **RGB:** Red-Green-Blue (standard but harder for color filtering)

### Frame Rate
- Camera publishes at 30 FPS
- You don't need to process every frame
- Processing at 10 FPS is enough for following

---

## What Team 2 Needs From You

Team 2 will take your `/target_person` message and use it to:
- Look up depth values at the bounding box location
- Calculate how far away the person is
- Calculate what angle they're at

---

## Common Issues and Solutions

**Issue:** YOLO detects too many false positives
- **Solution:** Increase confidence threshold (try 0.6 or 0.7)

**Issue:** Color detection doesn't work in different lighting
- **Solution:** Widen HSV ranges or test with actual green vest in 4th floor lighting

**Issue:** Target selection flickers between people
- **Solution:** Add hysteresis - require new target to have significantly more green before switching

**Issue:** Running too slow (< 10 FPS)
- **Solution:** Reduce image resolution before running YOLO, or process every 2nd frame

**Issue:** Can't see camera topic
- **Solution:** Make sure RealSense camera is launched first

---

## Success Criteria

- Detects person with green vest reliably (>85% accuracy)
- Ignores people without green
- Target selection doesn't flicker
- Works in various lighting conditions on 4th floor
- Bounding box and center point are accurate