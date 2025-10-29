# Team 3: Follow Controller

Control the robot to follow the target person while maintaining 3 feet distance. Use distance and angle information from Team 2 to generate smooth, safe movement commands.

---

## What You're Building

**Node Name:** `follow_controller_node.py`

**Location:** `scout_mini_perception/nodes/follow_controller_node.py`

---

## ROS2 Concepts

### What is a Node?
A ROS2 node is a running program that performs a specific task. Your node will process camera images and detect people.

### What is a Topic?
Topics are named channels that nodes use to send messages to each other. Think of it like a radio station - one node broadcasts on a topic, and other nodes tune in to receive the messages.

### What is Subscribe/Publish?
- **Subscribe:** Your node listens to a topic to receive messages (like tuning into a radio station)
- **Publish:** Your node sends messages on a topic for others to receive (like broadcasting on a radio station)

### What is a Control Loop?
Your node will run continuously (like a game loop), checking the target state and adjusting robot speed many times per second.

### What is cmd_vel?
This is the standard ROS2 topic for controlling mobile robot motion. It uses the Twist message type to specify linear and angular velocities.

### What is Proportional Control?
A control strategy where the correction is proportional to the error. Bigger error = bigger correction. Smaller error = smaller correction.

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
Team 2's Node
    ↓
/target_state (you subscribe here)
    ↓
Your Node (follow_controller_node)
    ↓
/cmd_vel (you publish here)
    ↓
Robot Base Controller
    ↓
Robot Wheels Move
```

---

## Implementation

### Step 1: Create ROS2 Node
- Create a class that inherits from `Node`
- Name your node: `follow_controller_node`
- Subscribe to `/target_state` from Team 2
- Create publisher for `/cmd_vel` topic

### Step 2: Understand the Twist Message
**Message type:** `geometry_msgs/Twist`

**Two main fields you'll use:**
- `linear.x`: Forward/backward speed (meters per second)
  - Positive value = move forward
  - Negative value = move backward
  - Zero = stop forward/backward motion
- `angular.z`: Rotation speed (radians per second)
  - Positive value = rotate left (counter-clockwise)
  - Negative value = rotate right (clockwise)
  - Zero = stop rotation

**The robot can do both simultaneously!**
- Example: linear.x = 0.2, angular.z = 0.1 means "drive forward while turning slightly left"

### Step 3: Set Up Control Loop Timer
- Create a timer that runs at 20 Hz (every 0.05 seconds)
- This timer calls your control function repeatedly
- 20 Hz is fast enough for smooth control without being excessive

### Step 4: Implement State Machine
Your controller should have different states:

**SEARCHING:**
- No target detected
- Rotate slowly in place (angular.z = 0.2 rad/s)
- Keep rotating until target found

**FOLLOWING:**
- Target detected and being followed
- Use distance and angle control (see below)
- Normal operation mode

**LOST:**
- Target was there but now lost
- Stop all motion (linear.x = 0, angular.z = 0)
- Wait 2 seconds to see if target reappears
- If not, go to SEARCHING

**EMERGENCY_STOP:**
- Person too close (< 0.4m)
- Override everything else
- Back up at fixed speed (linear.x = -0.2 m/s)
- Stay in this mode until distance > 0.6m

### Step 5: Implement Distance Control
**Goal:** Maintain 3 feet (0.914 meters) from target

**The control logic:**
1. Set your target distance: `target_distance = 0.914` (3 feet in meters)
2. Calculate error: `distance_error = current_distance - target_distance`
3. Examples:
   - Current = 2.0m, Target = 0.914m → Error = +1.086m (too far, move forward)
   - Current = 0.5m, Target = 0.914m → Error = -0.414m (too close, move backward)
   - Current = 0.914m, Target = 0.914m → Error = 0m (perfect, don't move)

**Proportional control:**
- `forward_speed = K_p_distance * distance_error`
- Start with `K_p_distance = 0.3`
- Example: error = 1.0m → speed = 0.3 * 1.0 = 0.3 m/s

**Add dead zone:**
- If error is very small, don't move (prevents oscillation)
- If `abs(distance_error) < 0.1m`, set `forward_speed = 0`

**Add speed limits:**
- Max forward: 0.3 m/s (safety limit)
- Max backward: -0.2 m/s (slower when reversing)
- Clamp your calculated speed: `speed = max(min(speed, 0.3), -0.2)`

### Step 6: Implement Angle Control
**Goal:** Keep person centered in camera view (angle = 0)

**The control logic:**
1. Target angle is 0 (centered)
2. Calculate error: `angle_error = current_angle` (since target is 0)
3. Examples:
   - Current = +0.3 rad → Person is right, need to rotate right (negative rotation)
   - Current = -0.2 rad → Person is left, need to rotate left (positive rotation)
   - Current = 0 rad → Centered, don't rotate

**Proportional control:**
- `rotation_speed = K_p_angle * angle_error`
- Start with `K_p_angle = 1.0`
- Example: error = 0.2 rad → speed = 1.0 * 0.2 = 0.2 rad/s

**Add dead zone:**
- If `abs(angle_error) < 0.1 rad` (~6 degrees), set `rotation_speed = 0`

**Add rotation limits:**
- Max rotation: 0.5 rad/s (about 30 degrees per second)
- Clamp: `rotation = max(min(rotation, 0.5), -0.5)`

### Step 7: Combine Distance and Angle Control
In your control loop:
```
Calculate forward_speed from distance control
Calculate rotation_speed from angle control

Create Twist message:
  msg.linear.x = forward_speed
  msg.angular.z = rotation_speed

Publish to /cmd_vel
```

The robot will move forward/backward AND rotate simultaneously - this creates smooth following!

### Step 8: Implement Safety Checks

**Safety Check 1: Emergency Stop Distance**
- If `current_distance < 0.4m`:
  - Ignore all other controls
  - Set `linear.x = -0.2` (back up)
  - Set `angular.z = 0` (don't rotate)
  - Stay in EMERGENCY_STOP state until distance > 0.6m

**Safety Check 2: Target Loss Timeout**
- If `target_found == false` for more than 2 seconds:
  - Set both speeds to 0
  - Go to LOST state
  - Don't drive blindly

**Safety Check 3: Confidence Check**
- If `distance_confidence < 0.5`:
  - Reduce speeds by 50% (less confident = slower)
- If `distance_confidence < 0.3`:
  - Stop completely (data too unreliable)

**Safety Check 4: Maximum Distance**
- If `current_distance > 5.0m`:
  - Target probably lost or measurement error
  - Stop and go to LOST state

### Step 9: Add Velocity Ramping (Smoothing)
Don't change speeds instantly - this causes jerky motion:

**Simple ramping:**
```
desired_speed = calculated from control
current_speed = robot's current speed

new_speed = 0.8 * current_speed + 0.2 * desired_speed
```

This creates smooth acceleration and deceleration.

### Step 10: Add Logging for Debugging
Log important information:
- Current state (SEARCHING, FOLLOWING, etc.)
- Distance error and calculated forward speed
- Angle error and calculated rotation speed
- Any safety triggers (emergency stop, target loss)

---

### Step 11: Configuration File

**File:** `config/params.yaml`

**What is it?**
A configuration file that stores all your control parameters. This is crucial for tuning your controller's behavior without modifying code. You'll adjust these values frequently during testing.

**How to use it:**
In your node's `__init__`, declare and read parameters:
```python
self.declare_parameter('target_distance', 0.914)
self.target_distance = self.get_parameter('target_distance').value
```

**Parameters you should load:**

```yaml
follow_controller_node:
  ros__parameters:
    target_distance: 0.914            # Goal distance in meters (3 feet)
    k_p_distance: 0.3                 # Distance control gain
    k_p_angle: 1.0                    # Angle control gain
    distance_dead_zone: 0.1           # Don't move if within ±0.1m of target
    angle_dead_zone: 0.1              # Don't rotate if within ±0.1 rad (~6°)
    max_linear_speed: 0.3             # Maximum forward speed (m/s)
    max_angular_speed: 0.5            # Maximum rotation speed (rad/s)
    emergency_stop_distance: 0.4      # Back up if person closer than this
    target_loss_timeout: 2.0          # Seconds before going to LOST state
    min_confidence: 0.5               # Minimum confidence to trust data
```

**When to tune these parameters:**

| Parameter | Tune if... | Try adjusting... |
|-----------|-----------|------------------|
| `k_p_distance` | Robot oscillates back/forth | Decrease to 0.2 |
| `k_p_distance` | Robot too slow to reach target | Increase to 0.4-0.5 |
| `k_p_angle` | Robot wobbles/rotates too much | Decrease to 0.7-0.8 |
| `k_p_angle` | Robot doesn't center person well | Increase to 1.2-1.5 |
| `distance_dead_zone` | Robot never stops moving | Increase to 0.15-0.2m |
| `distance_dead_zone` | Robot doesn't maintain distance | Decrease to 0.05m |
| `angle_dead_zone` | Robot constantly adjusting angle | Increase to 0.15-0.2 rad |
| `max_linear_speed` | Robot too aggressive/scary | Decrease to 0.2 m/s |
| `max_angular_speed` | Turns too fast | Decrease to 0.3 rad/s |
| `emergency_stop_distance` | Robot gets too close to people | Increase to 0.5-0.6m |
| `target_loss_timeout` | Robot gives up too quickly | Increase to 3.0-4.0s |
| `min_confidence` | Robot stops unnecessarily | Decrease to 0.3-0.4 |

**Tuning workflow:**
1. Start with default values
2. Test basic following
3. If robot oscillates → reduce K_p gains
4. If robot is sluggish → increase K_p gains or max speeds
5. If motion is jerky → increase dead zones
6. If robot doesn't respond → decrease dead zones
7. Iterate until smooth, stable following

**Quick tuning tips:**
- **For smoother motion:** Increase dead zones and decrease gains
- **For faster response:** Decrease dead zones and increase gains
- **For safety:** Increase emergency_stop_distance and target_loss_timeout
- **Always test incrementally** - change one parameter at a time

**To launch with config file:**
```bash
ros2 run scout_mini_perception follow_controller_node --ros-args --params-file config/params.yaml
```

---

## Testing Your Controller (Will only work on the robot)

### Basic Testing Commands
```bash
# Terminal 1: Launch camera
ros2 launch realsense2_camera rs_launch.py

# Terminal 2: Run Team 1
ros2 run scout_mini_perception person_detector_node

# Terminal 3: Run Team 2
ros2 run scout_mini_perception depth_estimator_node

# Terminal 4: Run your controller
ros2 run scout_mini_perception follow_controller_node

# Terminal 5: Monitor cmd_vel
ros2 topic echo /cmd_vel
```

### Test Scenarios (Do these in order!) (Will only work on the robot)

**Test 1: Static Person at 3 Feet**
- Person stands still at target distance
- Robot should stop (both speeds near zero)
- Check for oscillation (robot moving back and forth)
- If oscillating: reduce K_p gains or increase dead zones

**Test 2: Approach from Far**
- Start person at 5 feet
- Robot should smoothly approach to 3 feet
- Should slow down as it gets closer (not crash into person)

**Test 3: Person Too Close**
- Start person at 1 foot
- Robot should back up to 3 feet
- Emergency stop should trigger if person < 0.4m

**Test 4: Lateral Movement**
- Person at 3 feet but moves left/right
- Robot should rotate to keep person centered
- Should maintain 3 feet distance while rotating

**Test 5: Following - Person Walks Away**
- Person walks slowly away
- Robot should follow, maintaining distance
- Motion should be smooth, not jerky

**Test 6: Following - Person Walks Toward**
- Person walks toward robot
- Robot should back up to maintain distance
- Should not panic or move erratically

**Test 7: Target Loss**
- Person leaves camera view
- Robot should stop within 2 seconds
- Should go to SEARCHING mode (rotate slowly)

**Test 8: Target Reacquisition**
- After target loss, person returns to view
- Robot should smoothly resume following
- No sudden jerky movements

---

## Key Concepts

### Proportional Control (P Control)
- Output is proportional to error
- Formula: `output = K_p * error`
- Larger K_p = more aggressive response
- Smaller K_p = gentler response

### Dead Zones
- Small range where no action is taken
- Prevents tiny errors from causing constant corrections
- Essential for stability

### Control Loop Frequency
- 20 Hz = control updates 50 times per second
- Fast enough for smooth motion
- Not so fast that it wastes computation

---

## Parameter Tuning Guide

### Starting Values
```
Distance Control:
- target_distance: 0.914m (3 feet)
- K_p_distance: 0.3
- distance_dead_zone: 0.1m
- max_forward: 0.3 m/s
- max_backward: -0.2 m/s

Angle Control:
- K_p_angle: 1.0
- angle_dead_zone: 0.1 rad
- max_rotation: 0.5 rad/s

Safety:
- emergency_distance: 0.4m
- target_loss_timeout: 2.0 seconds
- min_confidence: 0.5

Control:
- loop_rate: 20 Hz
- smoothing_factor: 0.2
```

### If Robot Oscillates (moves back and forth):
- Reduce K_p values (try 0.2 for distance, 0.7 for angle)
- Increase dead zones (try 0.15m for distance, 0.15 rad for angle)

### If Robot is Too Slow:
- Increase K_p values (try 0.4 for distance, 1.2 for angle)
- Increase max speeds

### If Motion is Jerky:
- Increase smoothing (try smoothing_factor = 0.3 or higher)
- Decrease control loop rate (try 10 Hz)

### If Robot Doesn't Stay at 3 Feet:
- Check if dead zone is too large
- Verify distance from Team 2 is accurate
- Try increasing K_p_distance

---

## Common Issues and Solutions

**Issue:** Robot drives in circles
- **Solution:** Check angle control sign - might be backwards

**Issue:** Robot doesn't respond to person moving
- **Solution:** Verify you're receiving /target_state messages, check dead zones aren't too large

**Issue:** Robot moves too aggressively
- **Solution:** Reduce K_p gains and max speeds

**Issue:** Robot collides with person
- **Solution:** Check emergency stop distance, increase it if needed

**Issue:** Robot loses target too easily
- **Solution:** Increase target_loss_timeout from 2 to 3-4 seconds

---

## Success Criteria

- Maintains 3ft distance with ±0.3ft tolerance
- Keeps person centered with ±10 degree tolerance
- Smooth motion (no jerky start/stop)
- Safe operation (no collisions, respects emergency stop)
- Recovers from target loss within 3 seconds
- Follows continuously for 2+ minutes without issues
- Works with turns, stops, and direction changes