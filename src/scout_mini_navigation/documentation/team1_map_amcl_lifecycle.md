# Team 1: Map Server, AMCL, and Lifecycle Management

---

## Team Mission Statement

**"Team 1 provides the navigation foundation - stable localization and coordinated system lifecycle management for the entire Nav2 stack."**

You are the foundation team. Without your stable `/amcl_pose` and reliable `map→odom` transform, Teams 2 and 3 cannot function properly. Your work builds on Phase 2's existing localization and extends it for seamless Nav2 integration.

# Team 1: Map Server, AMCL, and Lifecycle Management

═══════════════════════════════════════════════════════════════════════════════

## TEAM MISSION STATEMENT

**"Team 1 provides the navigation foundation - stable localization and coordinated system lifecycle management for the entire Nav2 stack."**

You are the foundation team. Without your stable `/amcl_pose` and reliable `map→odom` transform, Teams 2 and 3 cannot function properly. Your work builds on Phase 2's existing localization and extends it for seamless Nav2 integration.

**Why Your Work Matters:** Autonomous navigation is impossible without knowing "Where am I?" Your AMCL system tells the robot its exact position on the map, and your lifecycle manager ensures all Nav2 components start up correctly and stay running.

═══════════════════════════════════════════════════════════════════════════════

## CURRENT STATE IN apollo_ws

Your existing `scout_mini_localization/` from Phase 2 contains:

```
scout_mini_localization/
├── config/
│   ├── amcl_params.yaml      # Your current AMCL config (needs Nav2 updates)
│   └── map_server_params.yaml # Your current map config (works as-is)
├── launch/
│   └── localization.launch.py # Your current launch (needs Nav2 integration)
└── maps/
    ├── your_map.pgm          # Your built map image (perfect as-is)
    └── your_map.yaml         # Your map metadata (perfect as-is)
```

**Your Integration Task:** Extend this Phase 2 foundation to work seamlessly with Nav2's lifecycle system while maintaining all existing functionality.

═══════════════════════════════════════════════════════════════════════════════

## STEP-BY-STEP SETUP INSTRUCTIONS

### Step 1: Create Navigation Package Structure

```bash
# Navigate to your workspace
cd ~/apollo_ws/src

# Create the navigation package (if not already done)
ros2 pkg create --build-type ament_cmake scout_mini_navigation
cd scout_mini_navigation

# Create required directories
mkdir -p config launch rviz

# Build to make sure package is recognized
cd ~/apollo_ws
colcon build --packages-select scout_mini_navigation
source install/setup.bash
```

─────────────────────────────────────────────────────────────────────────────

### Step 2: Update AMCL Configuration for Scout Mini Skid-Steer

**What You're About to Implement:**
AMCL (Adaptive Monte Carlo Localization) is like giving your robot thousands of "guesses" about where it thinks it is on the map. These guesses (called particles) get better over time as the robot moves and sees things with its LiDAR.

**How This Works:**

- Robot starts with many possible locations (particles spread across the map)
- As robot moves and sees obstacles, wrong guesses get eliminated
- Correct guesses get reinforced until robot knows exactly where it is
- Scout Mini's skid-steer drive creates more uncertainty in turns, so we need special settings

**Why This Matters:**
Without accurate localization, your robot is essentially blind - it can't plan paths or navigate safely because it doesn't know its position relative to the map.

**What You'll Create:**
An AMCL configuration file tuned specifically for Scout Mini's skid-steer drive characteristics and your RoboSense LiDAR.

---

**Understanding Scout Mini's Motion:** Scout Mini uses skid-steer drive (like a tank). This means:

- It turns by spinning wheels on opposite sides at different speeds
- Turning causes wheel slippage, making odometry less accurate
- AMCL needs higher noise parameters to account for this uncertainty

Create `apollo_ws/src/scout_mini_navigation/config/amcl_params.yaml`:

```yaml
amcl:
  ros__parameters:
    # Basic configuration
    use_sim_time: false

    # Motion model for Scout Mini's skid-steer drive
    robot_model_type: "nav2_amcl::DifferentialMotionModel"

    # Frame configuration (must match your Phase 2 setup)
    base_frame_id: "base_link"
    odom_frame_id: "odom"
    global_frame_id: "map"

    # Motion noise parameters - HIGHER for skid-steer due to wheel slip
    alpha1: 0.3 # Rotation error from rotation (turning causes slip)
    alpha2: 0.3 # Rotation error from translation
    alpha3: 0.3 # Translation error from translation
    alpha4: 0.3 # Translation error from rotation (skid turning)

    # Particle filter parameters
    max_particles: 2000 # More particles = better accuracy, more CPU
    min_particles: 500 # Fewer particles when confident
    pf_err: 0.05 # Particle filter population error
    pf_z: 0.99 # Particle filter population density

    # Update thresholds - prevents excessive computation during small movements
    update_min_d: 0.25 # Don't update filter until robot moves 25cm
    update_min_a: 0.2 # Don't update filter until robot rotates 0.2 rad
    resample_interval: 1 # Resample particles every update

    # Transform publishing - CRITICAL for Nav2 integration
    tf_broadcast: true # Must publish map->odom transform
    transform_tolerance: 1.0 # Allow 1 second latency for CAN bus

    # Initial pose setup (you'll set this manually in RViz)
    set_initial_pose: false
    initial_pose: { x: 0.0, y: 0.0, z: 0.0, yaw: 0.0 }
    initial_cov: { x: 0.25, y: 0.25, yaw: 0.1 }

    # TEAM 1 TODO: Complete sensor model parameters
    # Add laser model configuration for RoboSense LiDAR:
    # - laser_max_range: [your LiDAR's maximum range]
    # - laser_min_range: [your LiDAR's minimum range]
    # - laser_model_type: "likelihood_field" (recommended)
    # - max_beams: [60-180 depending on performance needs]
    # - z_hit, z_short, z_max, z_rand: likelihood field weights
    # - sigma_hit: standard deviation of hit readings

    # HELPFUL LINKS for completing sensor model:
    # Official AMCL Configuration: https://docs.nav2.org/configuration/packages/configuring-amcl.html
    # Sensor Model Tuning: https://automaticaddison.com/ros-2-navigation-tuning-guide-nav2/ * Great Resource to understand the parameters.
```

**Pro Tips for Beginners:**

- **alpha1-alpha4**: Start with 0.3 for all. If robot pose drifts during turns, increase to 0.4-0.5
- **max_particles**: More particles = more accuracy but slower performance. 2000 is a good starting point
- **transform_tolerance**: Scout Mini uses CAN bus which can be slower than USB/Ethernet. 1.0 second is conservative but safe

─────────────────────────────────────────────────────────────────────────────

### Step 3: Set Up Lifecycle Manager for Nav2 Coordination

**What You're About to Implement:**
The lifecycle manager is like a conductor for an orchestra - it makes sure all Nav2 servers start up in the right order and stay coordinated. Without it, servers might try to start before their dependencies are ready.

**How This Works:**

- Nav2 servers don't auto-start - they need to be "configured" then "activated"
- Lifecycle manager sends startup commands to all servers in the correct sequence
- It monitors server health and can restart failed servers automatically
- Like a supervisor making sure all workers show up and do their jobs

**Why This Matters:**
If servers start in wrong order or crash unexpectedly, your navigation system fails. The lifecycle manager prevents these coordination problems.

**What You'll Create:**
A configuration that tells the lifecycle manager which Nav2 servers to manage and how to handle failures.

---

**What is Lifecycle Management?** Nav2 servers don't start automatically - they need to be "configured" and "activated" in the right order. The lifecycle manager handles this coordination.

Create the lifecycle configuration section in your Nav2 parameters:

```yaml
# Add this to apollo_ws/src/scout_mini_navigation/config/nav2_params.yaml

lifecycle_manager:
  ros__parameters:
    use_sim_time: false
    autostart: true

    # All Nav2 servers that need lifecycle management
    node_names: [
        "controller_server", # Team 3: Path following
        "smoother_server", # Team 2: Path smoothing
        "planner_server", # Team 2: Path planning
        "behavior_server", # Team 3: Recovery behaviors
        "bt_navigator", # Team 3: Behavior tree logic
        "waypoint_follower", # Team 3: Multi-goal navigation
      ]

    # Health monitoring configuration
    bond_timeout: 4.0 # Time to wait for node connection
    attempt_respawn_reconnection: true # Try to restart failed nodes
    bond_respawn_max_duration: 10.0 # Give up after 10 seconds

# Separate lifecycle manager for localization components
lifecycle_manager_localization:
  ros__parameters:
    use_sim_time: false
    autostart: true
    node_names: ["map_server", "amcl"]
    bond_timeout: 4.0
```

**Why Two Lifecycle Managers?** Separating localization (map_server, amcl) from navigation (planner, controller, etc.) allows you to restart navigation without losing your map and pose.

─────────────────────────────────────────────────────────────────────────────

### Step 4: Integrate with Existing Phase 2 Localization

**What You're About to Implement:**
You're going to update your existing Phase 2 localization system to work with Nav2's new architecture. Think of it as upgrading your car's engine to work with a more advanced transmission system.

**How This Works:**

- Your existing map files and basic AMCL setup stay the same
- You'll modify the launch file to use Nav2's parameter structure
- Add lifecycle management to coordinate with other Nav2 components
- Keep backward compatibility so Phase 2 still works independently

**Why This Matters:**
This integration allows your proven Phase 2 localization to work seamlessly with the new Nav2 navigation stack while maintaining all existing functionality.

**What You'll Create:**
An updated launch file that bridges your Phase 2 system with Nav2's requirements.

---

**Important:** Don't delete your existing `scout_mini_localization/` - we'll extend it!

Update your existing `apollo_ws/src/scout_mini_localization/launch/localization.launch.py` to be Nav2-compatible:

```python
import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    # Package directories
    scout_loc_dir = FindPackageShare('scout_mini_localization')
    scout_nav_dir = FindPackageShare('scout_mini_navigation')

    # Parameters
    map_file = LaunchConfiguration('map')
    use_sim_time = LaunchConfiguration('use_sim_time', default='false')

    # Use Nav2 parameters if available, otherwise fall back to local params
    nav2_params_file = PathJoinSubstitution([scout_nav_dir, 'config', 'nav2_params.yaml'])

    # Launch arguments
    declare_map_yaml_cmd = DeclareLaunchArgument(
        'map',
        default_value=PathJoinSubstitution([scout_loc_dir, 'maps', 'your_map.yaml']),
        description='Full path to map yaml file'
    )

    declare_use_sim_time_cmd = DeclareLaunchArgument(
        'use_sim_time',
        default_value='false',
        description='Use simulation time'
    )

    # Map server (unchanged from Phase 2)
    map_server_node = Node(
        package='nav2_map_server',
        executable='map_server',
        name='map_server',
        output='screen',
        parameters=[
            {'use_sim_time': use_sim_time},
            {'yaml_filename': map_file}
        ]
    )

    # AMCL node (now uses Nav2 parameters)
    amcl_node = Node(
        package='nav2_amcl',
        executable='amcl',
        name='amcl',
        output='screen',
        parameters=[nav2_params_file]
    )

    # Lifecycle manager for localization components
    localization_lifecycle_manager = Node(
        package='nav2_lifecycle_manager',
        executable='lifecycle_manager',
        name='lifecycle_manager_localization',
        output='screen',
        parameters=[nav2_params_file]
    )

    return LaunchDescription([
        declare_map_yaml_cmd,
        declare_use_sim_time_cmd,
        map_server_node,
        amcl_node,
        localization_lifecycle_manager
    ])
```

**Key Changes from Phase 2:**

- Now uses Nav2 parameter file instead of separate AMCL params
- Includes lifecycle manager for coordinated startup
- Still compatible with your existing map files

─────────────────────────────────────────────────────────────────────────────

### Step 5: Add Your Configuration to nav2_params.yaml

**What You're About to Implement:**
You're creating a unified configuration file that contains all Nav2 settings in one place. Think of it as a master settings file that all teams contribute to, making it easy to manage the entire navigation system.

**How This Works:**

- Each team adds their specific configuration section to this master file
- Nav2 reads this single file to configure all servers (planner, controller, etc.)
- Makes coordination between teams easier and reduces configuration conflicts
- Simplifies launching the complete navigation system

**Why This Matters:**
Having all settings in one file prevents configuration mismatches between teams and makes the entire system easier to debug and maintain.

**What You'll Create:**
Your team's section of the master Nav2 configuration file with AMCL, map server, and lifecycle settings.

---

Add your Team 1 section to `apollo_ws/src/scout_mini_navigation/config/nav2_params.yaml`:

```yaml
#==============================================================================
# TEAM 1: AMCL and Lifecycle Management
#==============================================================================

amcl:
  ros__parameters:
    use_sim_time: false
    robot_model_type: "nav2_amcl::DifferentialMotionModel"
    base_frame_id: "base_link"
    odom_frame_id: "odom"
    global_frame_id: "map"

    # Scout Mini skid-steer motion model
    alpha1: 0.3
    alpha2: 0.3
    alpha3: 0.3
    alpha4: 0.3

    # Particle filter configuration
    max_particles: 2000
    min_particles: 500
    pf_err: 0.05
    pf_z: 0.99

    # Update thresholds
    update_min_d: 0.25
    update_min_a: 0.2
    resample_interval: 1

    # Transform publishing (CRITICAL for Nav2)
    tf_broadcast: true
    transform_tolerance: 1.0

    # Initial pose
    set_initial_pose: false
    initial_pose: { x: 0.0, y: 0.0, z: 0.0, yaw: 0.0 }
    initial_cov: { x: 0.25, y: 0.25, yaw: 0.1 }

    # TEAM 1 TODO: Add sensor model parameters here
    # Complete the RoboSense LiDAR configuration

    # HELPFUL LINKS for sensor model completion:
    # Official AMCL Docs: https://docs.nav2.org/configuration/packages/configuring-amcl.html
    # Parameter Reference: https://navigation.ros.org/configuration/packages/configuring-amcl.html
    # Tuning Guide: https://automaticaddison.com/ros-2-navigation-tuning-guide-nav2/

map_server:
  ros__parameters:
    use_sim_time: false
    # TEAM 1 TODO: Update with your actual map path
    yaml_filename: "/path/to/your/map.yaml"
    topic_name: "map"
    frame_id: "map"

    # HELPFUL LINKS for map server configuration:
    # Map Server Setup: https://docs.nav2.org/configuration/packages/configuring-map-server.html
    # Map File Format: https://wiki.ros.org/map_server#Map_format

# Lifecycle managers
lifecycle_manager:
  ros__parameters:
    use_sim_time: false
    autostart: true
    node_names:
      [
        "controller_server",
        "smoother_server",
        "planner_server",
        "behavior_server",
        "bt_navigator",
        "waypoint_follower",
      ]
    bond_timeout: 4.0
    attempt_respawn_reconnection: true
    bond_respawn_max_duration: 10.0

lifecycle_manager_localization:
  ros__parameters:
    use_sim_time: false
    autostart: true
    node_names: ["map_server", "amcl"]
    bond_timeout: 4.0
```

═══════════════════════════════════════════════════════════════════════════════

Test 1: AMCL Parameter Validation
# Build your updated packages
colcon build --packages-select scout_mini_navigation scout_mini_localization
source install/setup.bash

# Test AMCL configuration syntax (this should not give errors)
ros2 param load /test_node src/scout_mini_navigation/config/nav2_params.yaml

# Launch just localization to test your changes
ros2 launch scout_mini_localization localization.launch.py

# In another terminal, verify AMCL is publishing poses
ros2 topic echo /amcl_pose --once


What You Should See:

- No yellow or red warnings in the terminal (e.g., “no laser scan received”, “extrapolation into the future”, or “transform not available”).
- AMCL pose messages publishing smoothly (5–10 Hz).
- Covariance values stay low (< 0.1) and decrease after initial localization.
- As you teleop or move in Gazebo, the position (x, y) changes smoothly, not with sudden jumps.
- Laser scan data in RViz aligns accurately with walls and obstacles on the map.

If Something Goes Wrong:

- Check YAML indentation (use spaces, not tabs).
- Verify all file paths in your launch and config files.
- Confirm the /scan topic is active and correctly remapped.
- Look at the terminal output for specific error or warning messages.
- Ensure tf_broadcast: true is set in your AMCL parameters.

─────────────────────────────────────────────────────────────────────────────

Test 2: Transform Chain Verification
# Launch robot base (Phase 1) in one terminal
ros2 launch scout_mini_base base.launch.py

# Launch localization (your updated Phase 2/3) in another terminal
ros2 launch scout_mini_localization localization.launch.py

# Check the complete transform tree
ros2 run tf2_tools view_frames
# This creates frames.pdf - open it to see your TF tree

# Test specific transforms
ros2 run tf2_ros tf2_echo odom base_link    # Should work (from Phase 1)
ros2 run tf2_ros tf2_echo map odom          # Should work after setting initial pose
ros2 run tf2_ros tf2_echo map base_link     # Should work after setting initial pose

# Monitor transform timing
ros2 run tf2_ros tf2_monitor map base_link


Expected Results:

Transform tree should show a continuous chain: map → odom → base_link.

Transform latency should remain < 100 ms.

No “transform timeout” or “lookup would require extrapolation into the future” warnings in the terminal.

Timestamps for all TFs update continuously while the robot moves.

Pro Tip:
If map → odom is missing, use the 2D Pose Estimate tool in RViz to set the initial pose. AMCL will start broadcasting the transform immediately after.

─────────────────────────────────────────────────────────────────────────────

Test 3: Particle Filter Behavior
# Launch your localization system
ros2 launch scout_mini_localization localization.launch.py

# Open RViz to visualize
ros2 run rviz2 rviz2

# In RViz, add these displays:
# - Map (/map)
# - Particle Cloud (/particlecloud)
# - Robot Model (set Robot Description to robot_description)
# - Laser Scan (/scan)
# - TF (shows coordinate frames)

# Set Fixed Frame to "map"

# Use 2D Pose Estimate tool to set initial robot position
# Watch particles converge to the estimate

# Test with teleop movement
ros2 run teleop_twist_keyboard teleop_twist_keyboard \
  --ros-args -r /cmd_vel:=/scout_mini/cmd_vel


Success Indicators:

After setting the initial pose, the particle cloud collapses and converges within 5 seconds.

As the robot moves in Gazebo, the particle cloud follows smoothly without scattering.

/amcl_pose updates at a regular rate, and the pose in RViz matches the robot’s actual movement in Gazebo.

Laser scans remain properly aligned with the map as the robot moves.

No sudden pose jumps, teleporting, or erratic particle movement.

Pro Tip:
If particles stay scattered or jump randomly, revisit your AMCL noise parameters (alpha1–alpha4) or verify LiDAR frame alignment.

─────────────────────────────────────────────────────────────────────────────

Test 4: Lifecycle Manager Integration
# Test lifecycle manager functionality
ros2 launch scout_mini_localization localization.launch.py

# Check that lifecycle services are available
ros2 service list | grep lifecycle
# You should see services like:
# /lifecycle_manager_localization/get_state
# /lifecycle_manager_localization/change_state

# Check node states
ros2 service call /lifecycle_manager_localization/get_state \
  nav2_msgs/srv/GetState "{node_name: 'amcl'}"

# All nodes should be in "active" state if autostart worked

# Test manual lifecycle control
ros2 service call /lifecycle_manager_localization/manage_nodes \
  nav2_msgs/srv/ManageLifecycleNodes "{command: 0}"  # Configure
ros2 service call /lifecycle_manager_localization/manage_nodes \
  nav2_msgs/srv/ManageLifecycleNodes "{command: 1}"  # Activate


What This Tests:

Confirms that the lifecycle manager starts and coordinates your localization nodes correctly.

Ensures map_server and amcl transition from unconfigured → inactive → active automatically.

Allows you to manually configure or activate nodes for debugging.

Validates the bond between lifecycle manager and AMCL/map server (no “bond broken” messages).

Expected Results:

Lifecycle services appear in the service list.

Calling /get_state returns “active” for both map_server and amcl.

No “bond timeout” or “failed to transition” warnings appear in the terminal.
═══════════════════════════════════════════════════════════════════════════════

## TROUBLESHOOTING GUIDE

### Problem: "AMCL particles don't converge"

**Symptoms:**

- Particle cloud remains spread out after setting initial pose
- Robot pose jumps around during movement
- High covariance values (> 1.0) in `/amcl_pose`

**Common Causes & Solutions:**

```yaml
# Solution 1: Increase particle count for better convergence
max_particles: 3000
min_particles: 1000

# Solution 2: Reduce motion noise if your odometry is very accurate
alpha1: 0.2
alpha2: 0.2
alpha3: 0.2
alpha4: 0.2

# Solution 3: Adjust update sensitivity
update_min_d: 0.15 # Update more frequently
update_min_a: 0.1
```

**Debugging Steps:**

```bash
# Check if initial pose was set correctly
ros2 topic echo /initialpose

# Monitor particle count
ros2 topic echo /particlecloud | grep "poses:" -A 5

# Check odometry quality
ros2 topic echo /odom | grep "covariance:" -A 10
```

─────────────────────────────────────────────────────────────────────────────

### Problem: "Transform timeout errors"

**Symptoms:**

- "Lookup would require extrapolation into the future" warnings
- Nav2 fails with "No transform available"
- Intermittent `/amcl_pose` publishing

**Solutions:**

```yaml
# Increase transform tolerance
transform_tolerance: 2.0

# Ensure TF broadcasting is enabled
tf_broadcast: true

# Check frame IDs match exactly
base_frame_id: "base_link" # Must match scout_mini_description URDF
odom_frame_id: "odom" # Must match scout_mini_base odometry
global_frame_id: "map" # Standard map frame
```

**Debugging Steps:**

```bash
# Check all active TF publishers
ros2 run tf2_tools view_frames

# Monitor TF timing
ros2 run tf2_ros tf2_monitor

# Verify frame names in your URDF
ros2 param get /robot_state_publisher robot_description
```

─────────────────────────────────────────────────────────────────────────────

### Problem: "Lifecycle manager fails to start nodes"

**Symptoms:**

- Nodes remain in "inactive" state
- "Bond broken" errors in terminal
- Nav2 stack doesn't respond to commands

**Solutions:**

```yaml
# Increase timeouts for slower computers
bond_timeout: 10.0
bond_respawn_max_duration: 20.0

# Check node names match exactly
node_names: ["map_server", "amcl"] # Must match actual node names
```

**Debugging Steps:**

```bash
# Check individual node status
ros2 lifecycle list
ros2 lifecycle get /map_server
ros2 lifecycle get /amcl

# Manually control lifecycle if needed
ros2 lifecycle set /map_server configure
ros2 lifecycle set /map_server activate
```

─────────────────────────────────────────────────────────────────────────────

### Problem: "Map not loading correctly"

**Symptoms:**

- Empty map in RViz
- "Failed to load map" errors
- Robot appears at wrong location

**Solutions:**

```bash
# Verify map file exists and is readable
ls -la ~/apollo_ws/src/scout_mini_localization/maps/
cat ~/apollo_ws/src/scout_mini_localization/maps/your_map.yaml

# Update map path in nav2_params.yaml
yaml_filename: "/home/YOUR_USERNAME/apollo_ws/src/scout_mini_localization/maps/your_map.yaml"

# Test map server independently
ros2 run nav2_map_server map_server \
  --ros-args -p yaml_filename:=/path/to/your_map.yaml
```

═══════════════════════════════════════════════════════════════════════════════

## PARAMETER TUNING GUIDELINES

### For Better Localization Accuracy

```yaml
# More particles for complex environments
max_particles: 3000
min_particles: 1000

# More frequent updates for dynamic scenarios
update_min_d: 0.15
update_min_a: 0.1

# Better sensor utilization (if performance allows)
max_beams: 100
```

─────────────────────────────────────────────────────────────────────────────

### For Better Performance (Lower CPU Usage)

```yaml
# Fewer particles for simpler environments
max_particles: 1500
min_particles: 300

# Less frequent updates for static scenarios
update_min_d: 0.35
update_min_a: 0.3

# Fewer laser beams for faster processing
max_beams: 30
```

─────────────────────────────────────────────────────────────────────────────

### For Scout Mini Skid-Steer Optimization

```yaml
# Higher noise for aggressive turning maneuvers
alpha1: 0.4    # Turning on carpet or rough surfaces
alpha4: 0.4    # Skid steering creates more uncertainty

# Standard noise for smooth surfaces
alpha1: 0.3
alpha4: 0.3

# Lower noise only if you have very good odometry
alpha1: 0.2
alpha4: 0.2
```

**Pro Tip:** Start with conservative values (higher noise) and gradually reduce if performance is good. It's better to be too conservative than have the robot lose track of its position!

**Additional Resources for Parameter Tuning:**

- **Nav2 Tuning Guide**: https://docs.nav2.org/tuning/index.html
- **AMCL Best Practices**: https://navigation.ros.org/tuning/index.html
- **Community Examples**: https://github.com/ros-planning/navigation2_tutorials

═══════════════════════════════════════════════════════════════════════════════

## TEAM 1 HANDOFF CHECKLIST

### Configuration Files (Must Complete Before Other Teams Can Start)

- [ ] `nav2_params.yaml` updated with complete Team 1 section
- [ ] `amcl_params.yaml` configured for Scout Mini skid-steer motion
- [ ] Updated `localization.launch.py` that works with Nav2
- [ ] Verified map server configuration with existing Phase 2 maps

─────────────────────────────────────────────────────────────────────────────

### Integration Verification (Must Pass These Tests)

- [ ] **Stable Localization**: `/amcl_pose` publishes with variance < 0.1m when robot is stationary
- [ ] **Transform Chain**: `map → odom → base_link` transforms available continuously
- [ ] **Lifecycle Management**: All localization nodes start to "active" state automatically
- [ ] **Frame Consistency**: All frame IDs match between localization, base, and description packages

─────────────────────────────────────────────────────────────────────────────

### Performance Validation (Document These Results)

```bash
# Test 1: Pose stability (robot stationary for 30 seconds)
ros2 topic echo /amcl_pose | grep "covariance:" -A 6
# Result: Position variance should be < 0.01, orientation < 0.001

# Test 2: Transform availability (should always succeed)
ros2 run tf2_ros tf2_echo map base_link
# Result: Latency should be < 100ms consistently

# Test 3: Particle convergence (set initial pose, measure convergence time)
# Result: Particles should converge within 5 seconds of setting initial pose
```

─────────────────────────────────────────────────────────────────────────────

### What Teams 2 and 3 Can Expect from You

**Guaranteed Capabilities:**

- Stable robot pose estimates available via `/amcl_pose` topic
- Continuous `map → odom` transform for coordinate conversions
- Map data available via `/map` topic for costmap integration
- Lifecycle management system that coordinates all Nav2 servers

**Quality Standards:**

- Position accuracy: ±10cm under normal conditions
- Orientation accuracy: ±5 degrees under normal conditions
- Transform latency: < 100ms for all coordinate conversions
- System uptime: 99%+ reliability during normal operation

─────────────────────────────────────────────────────────────────────────────

### What You Need from Other Teams

**From Team 2 (Costmaps + Planning):**

- Costmap frame configurations that match your TF settings
- Planning update frequencies that don't overload AMCL
- Coordination on `transform_tolerance` settings

**From Team 3 (Controllers + Behavior Trees):**

- Controller parameters that respect AMCL's update rates
- Velocity profiles that don't cause excessive particle filter resampling
- Recovery behaviors that don't interfere with localization

─────────────────────────────────────────────────────────────────────────────

### Critical Handoff Information

**Frame ID Standards (ALL teams must use these exactly):**

```yaml
map_frame: "map"
odom_frame: "odom"
base_frame: "base_link"
```

**Topic Names (Teams 2&3 will consume these):**

- `/amcl_pose` - Robot position estimates
- `/map` - Static map for planning
- `/particlecloud` - Localization confidence visualization

**Transform Requirements (Teams 2&3 depend on these):**

- `map → odom` must be published continuously after initial pose is set
- Transform tolerance must accommodate Scout Mini's CAN bus latency
- All transforms must use consistent timestamps

**Lifecycle Dependencies (Critical for system integration):**

- Localization lifecycle manager must start before navigation lifecycle manager
- AMCL must be fully active before costmaps can initialize properly
- Map server must be running before any planning can occur

Remember: You're the foundation that everything else builds on. Take time to get your configuration solid before moving to integration testing!

Your existing `scout_mini_localization/` from Phase 2 contains:

```
scout_mini_localization/
├── config/
│   ├── amcl_params.yaml      # Your current AMCL config (needs Nav2 updates)
│   └── map_server_params.yaml # Your current map config (works as-is)
├── launch/
│   └── localization.launch.py # Your current launch (needs Nav2 integration)
└── maps/
    ├── your_map.pgm          # Your built map image (perfect as-is)
    └── your_map.yaml         # Your map metadata (perfect as-is)
```

**Your Integration Task:** Extend this Phase 2 foundation to work seamlessly with Nav2's lifecycle system while maintaining all existing functionality.

## Step-by-Step Setup Instructions

### Step 1: Create Navigation Package Structure

```bash
# Navigate to your workspace
cd ~/apollo_ws/src

# Create the navigation package (if not already done)
ros2 pkg create --build-type ament_cmake scout_mini_navigation
cd scout_mini_navigation

# Create required directories
mkdir -p config launch rviz

# Build to make sure package is recognized
cd ~/apollo_ws
colcon build --packages-select scout_mini_navigation
source install/setup.bash
```

### Step 2: Update AMCL Configuration for Scout Mini Skid-Steer

**Understanding Scout Mini's Motion:** Scout Mini uses skid-steer drive (like a tank). This means:

- It turns by spinning wheels on opposite sides at different speeds
- Turning causes wheel slippage, making odometry less accurate
- AMCL needs higher noise parameters to account for this uncertainty

Create `apollo_ws/src/scout_mini_navigation/config/amcl_params.yaml`:

```yaml
amcl:
  ros__parameters:
    # Basic configuration
    use_sim_time: false

    # Motion model for Scout Mini's skid-steer drive
    robot_model_type: "nav2_amcl::DifferentialMotionModel"

    # Frame configuration (must match your Phase 2 setup)
    base_frame_id: "base_link"
    odom_frame_id: "odom"
    global_frame_id: "map"

    # Motion noise parameters - HIGHER for skid-steer due to wheel slip
    alpha1: 0.3 # Rotation error from rotation (turning causes slip)
    alpha2: 0.3 # Rotation error from translation
    alpha3: 0.3 # Translation error from translation
    alpha4: 0.3 # Translation error from rotation (skid turning)

    # Particle filter parameters
    max_particles: 2000 # More particles = better accuracy, more CPU
    min_particles: 500 # Fewer particles when confident
    pf_err: 0.05 # Particle filter population error
    pf_z: 0.99 # Particle filter population density

    # Update thresholds - prevents excessive computation during small movements
    update_min_d: 0.25 # Don't update filter until robot moves 25cm
    update_min_a: 0.2 # Don't update filter until robot rotates 0.2 rad
    resample_interval: 1 # Resample particles every update

    # Transform publishing - CRITICAL for Nav2 integration
    tf_broadcast: true # Must publish map->odom transform
    transform_tolerance: 1.0 # Allow 1 second latency for CAN bus

    # Initial pose setup (you'll set this manually in RViz)
    set_initial_pose: false
    initial_pose: { x: 0.0, y: 0.0, z: 0.0, yaw: 0.0 }
    initial_cov: { x: 0.25, y: 0.25, yaw: 0.1 }

    # TEAM 1 TODO: Complete sensor model parameters
    # Add laser model configuration for RoboSense LiDAR:
    # - laser_max_range: [your LiDAR's maximum range]
    # - laser_min_range: [your LiDAR's minimum range]
    # - laser_model_type: "likelihood_field" (recommended)
    # - max_beams: [60-180 depending on performance needs]
    # - z_hit, z_short, z_max, z_rand: likelihood field weights
    # - sigma_hit: standard deviation of hit readings
```

**Pro Tips for Beginners:**

- **alpha1-alpha4**: Start with 0.3 for all. If robot pose drifts during turns, increase to 0.4-0.5
- **max_particles**: More particles = more accuracy but slower performance. 2000 is a good starting point
- **transform_tolerance**: Scout Mini uses CAN bus which can be slower than USB/Ethernet. 1.0 second is conservative but safe

### Step 3: Set Up Lifecycle Manager for Nav2 Coordination

**What is Lifecycle Management?** Nav2 servers don't start automatically - they need to be "configured" and "activated" in the right order. The lifecycle manager handles this coordination.

Create the lifecycle configuration section in your Nav2 parameters:

```yaml
# Add this to apollo_ws/src/scout_mini_navigation/config/nav2_params.yaml

lifecycle_manager:
  ros__parameters:
    use_sim_time: false
    autostart: true

    # All Nav2 servers that need lifecycle management
    node_names: [
        "controller_server", # Team 3: Path following
        "smoother_server", # Team 2: Path smoothing
        "planner_server", # Team 2: Path planning
        "behavior_server", # Team 3: Recovery behaviors
        "bt_navigator", # Team 3: Behavior tree logic
        "waypoint_follower", # Team 3: Multi-goal navigation
      ]

    # Health monitoring configuration
    bond_timeout: 4.0 # Time to wait for node connection
    attempt_respawn_reconnection: true # Try to restart failed nodes
    bond_respawn_max_duration: 10.0 # Give up after 10 seconds

# Separate lifecycle manager for localization components
lifecycle_manager_localization:
  ros__parameters:
    use_sim_time: false
    autostart: true
    node_names: ["map_server", "amcl"]
    bond_timeout: 4.0
```

**Why Two Lifecycle Managers?** Separating localization (map_server, amcl) from navigation (planner, controller, etc.) allows you to restart navigation without losing your map and pose.

### Step 4: Integrate with Existing Phase 2 Localization

**Important:** Don't delete your existing `scout_mini_localization/` - we'll extend it!

Update your existing `apollo_ws/src/scout_mini_localization/launch/localization.launch.py` to be Nav2-compatible:

```python
import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    # Package directories
    scout_loc_dir = FindPackageShare('scout_mini_localization')
    scout_nav_dir = FindPackageShare('scout_mini_navigation')

    # Parameters
    map_file = LaunchConfiguration('map')
    use_sim_time = LaunchConfiguration('use_sim_time', default='false')

    # Use Nav2 parameters if available, otherwise fall back to local params
    nav2_params_file = PathJoinSubstitution([scout_nav_dir, 'config', 'nav2_params.yaml'])

    # Launch arguments
    declare_map_yaml_cmd = DeclareLaunchArgument(
        'map',
        default_value=PathJoinSubstitution([scout_loc_dir, 'maps', 'your_map.yaml']),
        description='Full path to map yaml file'
    )

    declare_use_sim_time_cmd = DeclareLaunchArgument(
        'use_sim_time',
        default_value='false',
        description='Use simulation time'
    )

    # Map server (unchanged from Phase 2)
    map_server_node = Node(
        package='nav2_map_server',
        executable='map_server',
        name='map_server',
        output='screen',
        parameters=[
            {'use_sim_time': use_sim_time},
            {'yaml_filename': map_file}
        ]
    )

    # AMCL node (now uses Nav2 parameters)
    amcl_node = Node(
        package='nav2_amcl',
        executable='amcl',
        name='amcl',
        output='screen',
        parameters=[nav2_params_file]
    )

    # Lifecycle manager for localization components
    localization_lifecycle_manager = Node(
        package='nav2_lifecycle_manager',
        executable='lifecycle_manager',
        name='lifecycle_manager_localization',
        output='screen',
        parameters=[nav2_params_file]
    )

    return LaunchDescription([
        declare_map_yaml_cmd,
        declare_use_sim_time_cmd,
        map_server_node,
        amcl_node,
        localization_lifecycle_manager
    ])
```

**Key Changes from Phase 2:**

- Now uses Nav2 parameter file instead of separate AMCL params
- Includes lifecycle manager for coordinated startup
- Still compatible with your existing map files

### Step 5: Add Your Configuration to nav2_params.yaml

Add your Team 1 section to `apollo_ws/src/scout_mini_navigation/config/nav2_params.yaml`:

```yaml
#==============================================================================
# TEAM 1: AMCL and Lifecycle Management
#==============================================================================

amcl:
  ros__parameters:
    use_sim_time: false
    robot_model_type: "nav2_amcl::DifferentialMotionModel"
    base_frame_id: "base_link"
    odom_frame_id: "odom"
    global_frame_id: "map"

    # Scout Mini skid-steer motion model
    alpha1: 0.3
    alpha2: 0.3
    alpha3: 0.3
    alpha4: 0.3

    # Particle filter configuration
    max_particles: 2000
    min_particles: 500
    pf_err: 0.05
    pf_z: 0.99

    # Update thresholds
    update_min_d: 0.25
    update_min_a: 0.2
    resample_interval: 1

    # Transform publishing (CRITICAL for Nav2)
    tf_broadcast: true
    transform_tolerance: 1.0

    # Initial pose
    set_initial_pose: false
    initial_pose: { x: 0.0, y: 0.0, z: 0.0, yaw: 0.0 }
    initial_cov: { x: 0.25, y: 0.25, yaw: 0.1 }

    # TEAM 1 TODO: Add sensor model parameters here
    # Complete the RoboSense LiDAR configuration

map_server:
  ros__parameters:
    use_sim_time: false
    # TEAM 1 TODO: Update with your actual map path
    yaml_filename: "/path/to/your/map.yaml"
    topic_name: "map"
    frame_id: "map"

# Lifecycle managers
lifecycle_manager:
  ros__parameters:
    use_sim_time: false
    autostart: true
    node_names:
      [
        "controller_server",
        "smoother_server",
        "planner_server",
        "behavior_server",
        "bt_navigator",
        "waypoint_follower",
      ]
    bond_timeout: 4.0
    attempt_respawn_reconnection: true
    bond_respawn_max_duration: 10.0

lifecycle_manager_localization:
  ros__parameters:
    use_sim_time: false
    autostart: true
    node_names: ["map_server", "amcl"]
    bond_timeout: 4.0
```

## Testing Procedures

### Test 1: AMCL Parameter Validation

```bash
# Build your updated packages
cd ~/apollo_ws
colcon build --packages-select scout_mini_navigation scout_mini_localization
source install/setup.bash

# Test AMCL configuration syntax (this should not give errors)
ros2 param load /test_node src/scout_mini_navigation/config/nav2_params.yaml

# Launch just localization to test your changes
ros2 launch scout_mini_localization localization.launch.py

# In another terminal, verify AMCL is publishing poses
ros2 topic echo /amcl_pose --once
```

**What You Should See:**

- No error messages about missing parameters
- AMCL pose message with reasonable covariance values
- Map should load in RViz if you have it open
- Covariance values stay low (< 0.1) and decrease after initial localization.
- As you teleop or move in Gazebo, the position (x, y) changes smoothly, not with sudden jumps.
- Laser scan data in RViz aligns accurately with walls and obstacles on the map.

**If Something Goes Wrong:**

- Check YAML indentation (spaces, not tabs!)
- Verify file paths are correct
- Look at terminal output for specific error messages

### Test 2: Transform Chain Verification

```bash
# Launch robot base (Phase 1) in one terminal
ros2 launch scout_mini_base base.launch.py

# Launch localization (your updated Phase 2) in another terminal
ros2 launch scout_mini_localization localization.launch.py

# Check the complete transform tree
ros2 run tf2_tools view_frames
# This creates frames.pdf - open it to see your TF tree

# Test specific transforms
ros2 run tf2_ros tf2_echo odom base_link    # Should work (from Phase 1)
ros2 run tf2_ros tf2_echo map odom          # Should work after setting initial pose
ros2 run tf2_ros tf2_echo map base_link     # Should work after setting initial pose

# Monitor transform timing
ros2 run tf2_ros tf2_monitor map base_link
```

**Expected Results:**

- Transform tree: `map → odom → base_link`
- Transform latency < 100ms consistently
- No "transform timeout" warnings

**Pro Tip:** If `map → odom` transform is missing, you need to set the initial pose in RViz using the 2D Pose Estimate tool.

### Test 3: Particle Filter Behavior

```bash
# Launch your localization system
ros2 launch scout_mini_localization localization.launch.py

# Open RViz to visualize
ros2 run rviz2 rviz2

# In RViz, add these displays:
# - Map (/map)
# - Particle Cloud (/particlecloud)
# - Robot Model (set Robot Description to robot_description)
# - Laser Scan (/scan)
# - TF (shows coordinate frames)

# Set Fixed Frame to "map"

# Use 2D Pose Estimate tool to set initial robot position
# Watch particles converge to the estimate

# Test with teleop movement
ros2 run teleop_twist_keyboard teleop_twist_keyboard \
  --ros-args -r /cmd_vel:=/scout_mini/cmd_vel
```

**Success Indicators:**

- Particles converge within 5 seconds of setting initial pose
- Particle cloud follows robot during movement
- No wild pose jumps or divergence
- Particle density stays reasonable (not spread across entire map)

### Test 4: Lifecycle Manager Integration

```bash
# Test lifecycle manager functionality
ros2 launch scout_mini_localization localization.launch.py

# Check that lifecycle services are available
ros2 service list | grep lifecycle
# You should see services like:
# /lifecycle_manager_localization/get_state
# /lifecycle_manager_localization/change_state

# Check node states
ros2 service call /lifecycle_manager_localization/get_state \
  nav2_msgs/srv/GetState "{node_name: 'amcl'}"

# All nodes should be in "active" state if autostart worked

# Test manual lifecycle control
ros2 service call /lifecycle_manager_localization/manage_nodes \
  nav2_msgs/srv/ManageLifecycleNodes "{command: 0}"  # Configure
ros2 service call /lifecycle_manager_localization/manage_nodes \
  nav2_msgs/srv/ManageLifecycleNodes "{command: 1}"  # Activate
```

**What This Tests:** Your lifecycle manager can coordinate startup and manage node health.

## Troubleshooting Guide

### Problem: "AMCL particles don't converge"

**Symptoms:**

- Particle cloud remains spread out after setting initial pose
- Robot pose jumps around during movement
- High covariance values (> 1.0) in `/amcl_pose`

**Common Causes & Solutions:**

```yaml
# Solution 1: Increase particle count for better convergence
max_particles: 3000
min_particles: 1000

# Solution 2: Reduce motion noise if your odometry is very accurate
alpha1: 0.2
alpha2: 0.2
alpha3: 0.2
alpha4: 0.2

# Solution 3: Adjust update sensitivity
update_min_d: 0.15 # Update more frequently
update_min_a: 0.1
```

**Debugging Steps:**

```bash
# Check if initial pose was set correctly
ros2 topic echo /initialpose

# Monitor particle count
ros2 topic echo /particlecloud | grep "poses:" -A 5

# Check odometry quality
ros2 topic echo /odom | grep "covariance:" -A 10
```

### Problem: "Transform timeout errors"

**Symptoms:**

- "Lookup would require extrapolation into the future" warnings
- Nav2 fails with "No transform available"
- Intermittent `/amcl_pose` publishing

**Solutions:**

```yaml
# Increase transform tolerance
transform_tolerance: 2.0

# Ensure TF broadcasting is enabled
tf_broadcast: true

# Check frame IDs match exactly
base_frame_id: "base_link" # Must match scout_mini_description URDF
odom_frame_id: "odom" # Must match scout_mini_base odometry
global_frame_id: "map" # Standard map frame
```

**Debugging Steps:**

```bash
# Check all active TF publishers
ros2 run tf2_tools view_frames

# Monitor TF timing
ros2 run tf2_ros tf2_monitor

# Verify frame names in your URDF
ros2 param get /robot_state_publisher robot_description
```

### Problem: "Lifecycle manager fails to start nodes"

**Symptoms:**

- Nodes remain in "inactive" state
- "Bond broken" errors in terminal
- Nav2 stack doesn't respond to commands

**Solutions:**

```yaml
# Increase timeouts for slower computers
bond_timeout: 10.0
bond_respawn_max_duration: 20.0

# Check node names match exactly
node_names: ["map_server", "amcl"] # Must match actual node names
```

**Debugging Steps:**

```bash
# Check individual node status
ros2 lifecycle list
ros2 lifecycle get /map_server
ros2 lifecycle get /amcl

# Manually control lifecycle if needed
ros2 lifecycle set /map_server configure
ros2 lifecycle set /map_server activate
```

### Problem: "Map not loading correctly"

**Symptoms:**

- Empty map in RViz
- "Failed to load map" errors
- Robot appears at wrong location

**Solutions:**

```bash
# Verify map file exists and is readable
ls -la ~/apollo_ws/src/scout_mini_localization/maps/
cat ~/apollo_ws/src/scout_mini_localization/maps/your_map.yaml

# Update map path in nav2_params.yaml
yaml_filename: "/home/YOUR_USERNAME/apollo_ws/src/scout_mini_localization/maps/your_map.yaml"

# Test map server independently
ros2 run nav2_map_server map_server \
  --ros-args -p yaml_filename:=/path/to/your_map.yaml
```

## Parameter Tuning Guidelines

### For Better Localization Accuracy

```yaml
# More particles for complex environments
max_particles: 3000
min_particles: 1000

# More frequent updates for dynamic scenarios
update_min_d: 0.15
update_min_a: 0.1

# Better sensor utilization (if performance allows)
max_beams: 100
```

### For Better Performance (Lower CPU Usage)

```yaml
# Fewer particles for simpler environments
max_particles: 1500
min_particles: 300

# Less frequent updates for static scenarios
update_min_d: 0.35
update_min_a: 0.3

# Fewer laser beams for faster processing
max_beams: 30
```

### For Scout Mini Skid-Steer Optimization

```yaml
# Higher noise for aggressive turning maneuvers
alpha1: 0.4    # Turning on carpet or rough surfaces
alpha4: 0.4    # Skid steering creates more uncertainty

# Standard noise for smooth surfaces
alpha1: 0.3
alpha4: 0.3

# Lower noise only if you have very good odometry
alpha1: 0.2
alpha4: 0.2
```

**Pro Tip:** Start with conservative values (higher noise) and gradually reduce if performance is good. It's better to be too conservative than have the robot lose track of its position!

## Team 1 Handoff Checklist

### Configuration Files (Must Complete Before Other Teams Can Start)

- [ ] `nav2_params.yaml` updated with complete Team 1 section
- [ ] `amcl_params.yaml` configured for Scout Mini skid-steer motion
- [ ] Updated `localization.launch.py` that works with Nav2
- [ ] Verified map server configuration with existing Phase 2 maps

### Integration Verification (Must Pass These Tests)

- [ ] **Stable Localization**: `/amcl_pose` publishes with variance < 0.1m when robot is stationary
- [ ] **Transform Chain**: `map → odom → base_link` transforms available continuously
- [ ] **Lifecycle Management**: All localization nodes start to "active" state automatically
- [ ] **Frame Consistency**: All frame IDs match between localization, base, and description packages

### Performance Validation (Document These Results)

```bash
# Test 1: Pose stability (robot stationary for 30 seconds)
ros2 topic echo /amcl_pose | grep "covariance:" -A 6
# Result: Position variance should be < 0.01, orientation < 0.001

# Test 2: Transform availability (should always succeed)
ros2 run tf2_ros tf2_echo map base_link
# Result: Latency should be < 100ms consistently

# Test 3: Particle convergence (set initial pose, measure convergence time)
# Result: Particles should converge within 5 seconds of setting initial pose
```

### What Teams 2 and 3 Can Expect from You

**Guaranteed Capabilities:**

- Stable robot pose estimates available via `/amcl_pose` topic
- Continuous `map → odom` transform for coordinate conversions
- Map data available via `/map` topic for costmap integration
- Lifecycle management system that coordinates all Nav2 servers

**Quality Standards:**

- Position accuracy: ±10cm under normal conditions
- Orientation accuracy: ±5 degrees under normal conditions
- Transform latency: < 100ms for all coordinate conversions
- System uptime: 99%+ reliability during normal operation

### What You Need from Other Teams

**From Team 2 (Costmaps + Planning):**

- Costmap frame configurations that match your TF settings
- Planning update frequencies that don't overload AMCL
- Coordination on `transform_tolerance` settings

**From Team 3 (Controllers + Behavior Trees):**

- Controller parameters that respect AMCL's update rates
- Velocity profiles that don't cause excessive particle filter resampling
- Recovery behaviors that don't interfere with localization

### Critical Handoff Information

**Frame ID Standards (ALL teams must use these exactly):**

```yaml
map_frame: "map"
odom_frame: "odom"
base_frame: "base_link"
```

**Topic Names (Teams 2&3 will consume these):**

- `/amcl_pose` - Robot position estimates
- `/map` - Static map for planning
- `/particlecloud` - Localization confidence visualization

**Transform Requirements (Teams 2&3 depend on these):**

- `map → odom` must be published continuously after initial pose is set
- Transform tolerance must accommodate Scout Mini's CAN bus latency
- All transforms must use consistent timestamps

**Lifecycle Dependencies (Critical for system integration):**

- Localization lifecycle manager must start before navigation lifecycle manager
- AMCL must be fully active before costmaps can initialize properly
- Map server must be running before any planning can occur

Remember: You're the foundation that everything else builds on. Take time to get your configuration solid before moving to integration testing!
