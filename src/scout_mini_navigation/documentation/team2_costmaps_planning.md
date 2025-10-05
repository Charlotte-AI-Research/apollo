# Team 2: Costmaps and Planning

═══════════════════════════════════════════════════════════════════════════════

## TEAM MISSION STATEMENT

**"Team 2 answers 'What's around me?' and 'How do I get there?' through environmental perception and intelligent path planning."**

You are the intelligence team. You transform raw sensor data into understanding (costmaps) and create safe paths to navigation goals (planning). Your work bridges the gap between knowing where you are (Team 1) and actually moving there (Team 3).

**Why Your Work Matters:** Even with perfect localization, a robot is useless if it can't understand obstacles or plan paths around them. You make the robot spatially aware and enable it to think ahead.

═══════════════════════════════════════════════════════════════════════════════

## YOUR ROLE IN THE NAVIGATION PIPELINE

```
Team 1 (Where am I?)  →  Team 2 (YOU - What's around me? How do I get there?)  →  Team 3 (How do I get there safely?)
- /amcl_pose         →  - Global costmap (map + obstacles)                    →  - Path following
- map→odom transform →  - Local costmap (real-time obstacles)                 →  - Obstacle avoidance
- /map topic         →  - /plan topic (paths to goals)                       →  - Recovery behaviors
```

═══════════════════════════════════════════════════════════════════════════════

## DEPENDENCIES AND PARALLEL WORK STRATEGY

### What You Need from Other Teams (Dependencies)

**From Team 1 (Critical Dependencies):**

- **Stable `/amcl_pose`** - Without good localization, costmaps will be misaligned
- **Continuous `map→odom` transform** - Needed to convert between coordinate frames
- **`/map` topic** - Your global costmap's static layer needs the map data
- **Lifecycle management** - Ensures costmap servers start up correctly

**From Existing Phase 2 Systems (Already Available):**

- **`/scan` topic** - From `rslidar_laserscan_converter` package, provides real-time LiDAR data
- **Transform chain** - `odom→base_link` from Phase 1, `map→odom` from Team 1

─────────────────────────────────────────────────────────────────────────────

### What You Can Do While Team 1 Works (Parallel Work)

**Normal Phase 3 Workflow (Recommended):**
Since `/scan` is already available from Phase 2, you can use **real LiDAR data** for most of your testing:

```bash
# 1. Draft costmap configurations using Scout Mini specifications
# 2. Test obstacle layer with REAL scan data (normal workflow)
ros2 topic echo /scan --once  # Verify LiDAR data is available

# Test costmap with real sensor data
ros2 run nav2_costmap_2d nav2_costmap_2d \
  --ros-args -p use_sim_time:=false \
  -r __node:=test_costmap \
  --params-file your_draft_config.yaml

# The obstacle layer will process real LiDAR data automatically
```

**Fallback Option (Only if Team 1 Offline):**
If Team 1's localization isn't ready yet, you can test with simulated data:

```bash
# OPTIONAL: Test obstacle layer with fake scan data (fallback only)
ros2 topic pub /scan sensor_msgs/msg/LaserScan \
  '{header: {frame_id: "base_link"}, ranges: [1.0, 1.0, 0.5, 2.0],
    angle_min: -1.57, angle_max: 1.57, angle_increment: 0.52}'
```

**Research Tasks (Independent Work):**

- Study Nav2 costmap documentation and examples
- Understand the difference between global and local costmaps
- Research Smac Hybrid-A\* vs NavFn planners for skid-steer robots
- Define Scout Mini footprint polygon and inflation parameters

═══════════════════════════════════════════════════════════════════════════════

## SCOUT MINI PHYSICAL SPECIFICATIONS

**Critical for Your Work:**

```yaml
# Robot footprint - USE THIS EXACT POLYGON IN ALL CONFIGS
footprint: "[[-0.356, -0.340], [0.356, -0.340], [0.356, 0.340], [-0.356, 0.340]]"
# Physical constraints
# Length: 612mm (0.612m) - extends ±0.306m from center
# Width: 580mm (0.580m) - extends ±0.290m from center
# Height: 285mm - not critical for 2D costmaps
# Safety padding: 50mm (0.05m) added to all sides

# Drive constraints (affects planning)
# Drive type: Skid-steer (no lateral movement)
# Min turning radius: ~0.40m (due to skid-steer mechanics)
# Max safe speed: 0.5 m/s indoors
```

**Pro Tip:** The footprint coordinates are relative to the robot's center (`base_link`). The values above include 5cm safety padding beyond the physical robot edges.

═══════════════════════════════════════════════════════════════════════════════

## STEP-BY-STEP SETUP INSTRUCTIONS

### Step 1: Configure Scout Mini Footprint (Shared by Both Costmaps)

**What You're About to Implement:**
The robot footprint is like drawing an outline of your robot's shape on the costmap. This tells the navigation system exactly how much space Scout Mini occupies, so it can plan paths that won't cause collisions.

**How This Works:**

- Define Scout Mini's physical dimensions as a polygon (rectangle with corners)
- Add safety padding around the edges for uncertainty in localization
- Both global and local costmaps use this same footprint for consistency
- Planning algorithms use this to ensure paths are safe for your robot's size

**Why This Matters:**
Without an accurate footprint, your robot might try to squeeze through spaces too small for it, or be overly conservative and avoid spaces it could safely navigate.

**What You'll Create:**
A common configuration file with Scout Mini's exact dimensions plus safety margins.

---

Create `apollo_ws/src/scout_mini_navigation/config/costmap_common_params.yaml`:

```yaml
# Common parameters shared by global and local costmaps
costmap_common:
  # Scout Mini footprint with safety padding
  footprint: "[[-0.356, -0.340], [0.356, -0.340], [0.356, 0.340], [-0.356, 0.340]]"
  footprint_padding: 0.05

  # Grid resolution (5cm cells - good balance of accuracy vs performance)
  resolution: 0.05

  # Transform tolerance (must match Team 1's AMCL settings)
  transform_tolerance: 1.0

  # Obstacle detection parameters from /scan topic (rslidar_laserscan_converter)
  obstacle_max_range: 2.5 # Mark obstacles within 2.5m of robot
  obstacle_min_range: 0.0 # No minimum range limit
  raytrace_max_range: 3.0 # Clear free space up to 3.0m
  raytrace_min_range: 0.0 # No minimum raytrace limit


  # TEAM 2 TODO: Tune these inflation parameters based on testing
  # inflation_radius: [how far to inflate obstacles - start with 0.55m]
  # cost_scaling_factor: [how quickly cost decreases - start with 1.0]

  # HELPFUL LINKS for completing inflation tuning:
  # Costmap Configuration: https://docs.nav2.org/configuration/packages/configuring-costmaps.html
  # Inflation Layer Guide: https://docs.nav2.org/configuration/packages/costmap-plugins/inflation.html
  # Tuning Tutorial: https://automaticaddison.com/ros-2-navigation-tuning-guide-nav2/
```

─────────────────────────────────────────────────────────────────────────────

### Step 2: Configure Global Costmap (Map-Based Planning Environment)

**What You're About to Implement:**
The global costmap is like creating a "smart version" of your Phase 2 map that combines your pre-built floor plan with real-time obstacle detection and safety zones. Think of it as overlaying live traffic data onto Google Maps.

**How This Works:**

- Static Layer: Takes your existing map and makes it available for planning
- Obstacle Layer: Processes live LiDAR data to detect new obstacles (people, chairs, etc.)
- Inflation Layer: Creates graduated "safety bubbles" around all obstacles
- Updates slowly (1 Hz) since the overall environment doesn't change quickly

**Why This Matters:**
Without this, your robot would only see the original static map and would drive straight into moveable obstacles or get too close to walls.

**What You'll Create:**
A configuration that builds an intelligent map combining static environment knowledge with real-time safety awareness.

---

Create `apollo_ws/src/scout_mini_navigation/config/global_costmap_params.yaml`:

```yaml
global_costmap:
  global_costmap:
    ros__parameters:
      # Basic configuration
      update_frequency: 1.0 # Update 1 Hz (static environment changes slowly)
      publish_frequency: 1.0 # Publish for RViz visualization
      global_frame: map # Use map frame from Team 1
      robot_base_frame: base_link
      use_sim_time: false

      # Costmap will auto-size to match the map from Team 1
      resolution: 0.05 # 5cm grid cells
      track_unknown_space: false # Don't worry about unexplored areas
      use_maximum: false # Use standard cost blending

      # Scout Mini footprint
      footprint: "[[-0.356, -0.340], [0.356, -0.340], [0.356, 0.340], [-0.356, 0.340]]"

      # Layer plugins (ORDER MATTERS - processed in sequence)
      plugins: ["static_layer", "obstacle_layer", "inflation_layer"]

      # Static layer - incorporates Team 1's pre-built map
      static_layer:
        plugin: "nav2_costmap_2d::StaticLayer"
        map_subscribe_transient_local: true # Reliable map subscription
        enabled: true
        subscribe_to_updates: true # Listen for map changes
        transform_tolerance: 1.0

      # Obstacle layer - processes real-time LiDAR data from /scan
      obstacle_layer:
        plugin: "nav2_costmap_2d::ObstacleLayer"
        enabled: true
        observation_sources: scan # Data source name
        footprint_clearing_enabled: true # Clear obstacles under robot
        max_obstacle_height: 2.0 # Ignore ceiling (Scout Mini is 0.285m)
        combination_method: 1 # Use maximum cost method

        # Configure the 'scan' observation source
        scan:
          topic: /scan # From rslidar_laserscan_converter
          obstacle_max_range: 2.5
          obstacle_min_range: 0.0
          raytrace_max_range: 3.0
          raytrace_min_range: 0.0
          clearing: true # Clear previously detected obstacles
          marking: true # Mark new obstacles
          data_type: "LaserScan"
          min_obstacle_height: 0.0 # Ground level
          max_obstacle_height: 2.0 # Below ceiling

      # Inflation layer - creates safety buffer around obstacles
      inflation_layer:
        plugin: "nav2_costmap_2d::InflationLayer"
        enabled: true
        # TEAM 2 TODO: Tune these parameters through testing
        # inflation_radius: [start with 0.55 - robot radius + safety margin]
        # cost_scaling_factor: [start with 1.0 - linear cost decay]
        # inflate_unknown: false
        # inflate_around_unknown: true

        # HELPFUL LINKS for inflation layer tuning:
        # Inflation Layer Docs: https://docs.nav2.org/configuration/packages/costmap-plugins/inflation.html
        # Costmap Concepts: https://docs.nav2.org/concepts/index.html#costmap-2d
```

─────────────────────────────────────────────────────────────────────────────

### Step 3: Configure Local Costmap (Real-Time Obstacle Avoidance)

**What You're About to Implement:**
The local costmap is like having a 3×3 meter "safety bubble" that follows your robot around, constantly updating with real-time obstacle information. It's focused on immediate navigation safety rather than long-term planning.

**How This Works:**

- Rolling window that moves with the robot (always centered on Scout Mini)
- Updates quickly (5 Hz) to catch dynamic obstacles like people walking by
- Only processes real-time sensor data (no static map layer needed)
- Uses odom frame since it's focused on local robot movement

**Why This Matters:**
While global costmap handles big-picture planning, local costmap handles immediate safety - avoiding people, furniture, or other dynamic obstacles that appear suddenly.

**What You'll Create:**
A fast-updating safety system that provides real-time obstacle awareness for dynamic navigation.

---

Create `apollo_ws/src/scout_mini_navigation/config/local_costmap_params.yaml`:

```yaml
local_costmap:
  local_costmap:
    ros__parameters:
      # Rolling window configuration (follows robot with fixed size)
      update_frequency: 5.0 # Update 5 Hz for dynamic obstacles
      publish_frequency: 2.0 # Publish for visualization
      global_frame: odom # Use odom frame (local planning)
      robot_base_frame: base_link
      use_sim_time: false

      # Rolling window size (3m x 3m around robot)
      rolling_window: true
      width: 3 # 3 meters wide
      height: 3 # 3 meters tall
      resolution: 0.05 # Same resolution as global

      # Scout Mini footprint
      footprint: "[[-0.356, -0.340], [0.356, -0.340], [0.356, 0.340], [-0.356, 0.340]]"

      # Local costmap layers (NO static layer - only dynamic obstacles)
      plugins: ["obstacle_layer", "inflation_layer"]

      # Obstacle layer (same config as global but higher update rate)
      obstacle_layer:
        plugin: "nav2_costmap_2d::ObstacleLayer"
        enabled: true
        observation_sources: scan
        footprint_clearing_enabled: true
        max_obstacle_height: 2.0
        combination_method: 1

        scan:
          topic: /scan
          obstacle_max_range: 2.5
          obstacle_min_range: 0.0
          raytrace_max_range: 3.0
          raytrace_min_range: 0.0
          clearing: true
          marking: true
          data_type: "LaserScan"
          expected_update_rate: 0.0 # No timeout (depends on LiDAR)
          observation_persistence: 0.0 # Don't keep old observations
          inf_is_valid: false # Ignore infinite laser readings
          clear_after_reading: true # Clear old data after processing
          min_obstacle_height: 0.0
          max_obstacle_height: 2.0

      # Inflation layer (same as global costmap)
      inflation_layer:
        plugin: "nav2_costmap_2d::InflationLayer"
        enabled: true
        # TEAM 2 TODO: Use same inflation settings as global costmap
        # inflation_radius: [match global costmap value]
        # cost_scaling_factor: [match global costmap value]

        # HELPFUL LINKS for local costmap configuration:
        # Local Costmap Setup: https://docs.nav2.org/configuration/packages/configuring-costmaps.html
        # Obstacle Layer: https://docs.nav2.org/configuration/packages/costmap-plugins/obstacle.html
```

**Key Differences Between Global and Local Costmaps:**

- **Global**: Uses `map` frame, covers entire map, includes static layer, updates slowly (1 Hz)
- **Local**: Uses `odom` frame, 3×3m rolling window, no static layer, updates quickly (5 Hz)

─────────────────────────────────────────────────────────────────────────────

### Step 4: Configure Path Planner for Scout Mini

**What You're About to Implement:**
The path planner is like a GPS navigation system that creates safe routes from your robot's current position to its goal. But unlike car GPS, it must consider Scout Mini's skid-steer limitations and create paths the robot can actually follow.

**How This Works:**

- Smac Hybrid-A\* planner understands non-holonomic constraints (can't move sideways)
- Uses Dubin's car model to respect minimum turning radius
- Plans around obstacles while considering robot's actual movement capabilities
- Generates waypoints that form a kinematically feasible path

**Why This Matters:**
A regular grid planner might create paths with impossible 90-degree turns or movements Scout Mini can't execute. This planner creates realistic paths for skid-steer robots.

**What You'll Create:**
A path planning configuration optimized for Scout Mini's specific movement constraints and performance requirements.

---

Create `apollo_ws/src/scout_mini_navigation/config/planner_params.yaml`:

```yaml
planner_server:
  ros__parameters:
    # Basic planner configuration
    expected_planner_frequency: 20.0 # Plan up to 20 Hz when needed
    planner_plugins: ["GridBased"] # Plugin name for configuration
    use_sim_time: false

    # Smac Hybrid-A* planner (RECOMMENDED for Scout Mini)
    GridBased:
      plugin: "nav2_smac_planner::SmacPlannerHybrid"

      # Costmap processing
      downsample_costmap: false # Use full resolution (important for accuracy)
      downsampling_factor: 1 # No downsampling

      # Planning parameters
      tolerance: 0.25 # Goal tolerance (25cm is reasonable)
      allow_unknown: true # Can plan through unknown areas if needed
      max_planning_time: 5.0 # Give up after 5 seconds

      # Motion model for Scout Mini's skid-steer constraints
      motion_model_for_search: "DUBIN" # Dubin's car (non-holonomic)
      angle_quantization_bins: 72 # 5-degree angle resolution (360/72=5°)

      # Analytic expansion (tries direct path to goal when close)
      analytic_expansion_ratio: 3.5 # Try direct path when within 3.5× heuristic distance
      analytic_expansion_max_length: 3.0 # Maximum direct path length (meters)

      # Vehicle-specific constraints
      minimum_turning_radius: 0.40 # Scout Mini's minimum turn radius


      # TEAM 2 TODO: Tune these penalties through testing
      # reverse_penalty: [higher value discourages backing up - start with 2.0]
      # change_penalty: [penalty for direction changes - start with 0.1]
      # non_straight_penalty: [prefer straight paths - start with 1.2]
      # cost_penalty: [avoid high-cost areas - start with 2.0]
      # retrospective_penalty: [discourage backtracking - start with 0.015]

      # Performance settings
      # max_iterations: [maximum search iterations - start with 1000000]
      # cache_obstacle_heuristic: false  # Disable for dynamic environments
      # lookup_table_size: 20.0         # Lookup table size in meters
      # smooth_path: true                # Post-process path for smoothness

      # HELPFUL LINKS for planner configuration:
      # Smac Hybrid-A* Planner: https://docs.nav2.org/configuration/packages/configuring-smac-planner.html
      # Planning Concepts: https://docs.nav2.org/concepts/index.html#planners
      # Alternative NavFn Planner: https://docs.nav2.org/configuration/packages/configuring-navfn.html
```

─────────────────────────────────────────────────────────────────────────────

### Step 5: Add Team 2 Configuration to nav2_params.yaml

**What You're About to Implement:**
You're adding your team's costmap and planning configurations to the master Nav2 settings file. This creates a unified configuration that all Nav2 servers will use, ensuring consistency across the entire navigation system.

**How This Works:**

- Your costmap configurations become part of the central Nav2 parameter file
- Planning server settings get integrated with other team configurations
- Single file makes it easy to launch and debug the complete navigation system
- Prevents parameter conflicts between teams

**Why This Matters:**
Having scattered configuration files makes debugging difficult and can cause conflicts. A unified approach ensures all teams' settings work together harmoniously.

**What You'll Create:**
Your team's section of the master configuration with all costmap and planning parameters properly integrated.

---

Add your section to `apollo_ws/src/scout_mini_navigation/config/nav2_params.yaml`:

```yaml
#==============================================================================
# TEAM 2: Costmaps and Planning
#==============================================================================

global_costmap:
  global_costmap:
    ros__parameters:
      update_frequency: 1.0
      publish_frequency: 1.0
      global_frame: map
      robot_base_frame: base_link
      use_sim_time: false
      resolution: 0.05
      track_unknown_space: false
      use_maximum: false

      # Scout Mini footprint (612mm × 580mm with 5cm padding)
      footprint: "[[-0.356, -0.340], [0.356, -0.340], [0.356, 0.340], [-0.356, 0.340]]"

      plugins: ["static_layer", "obstacle_layer", "inflation_layer"]

      static_layer:
        plugin: "nav2_costmap_2d::StaticLayer"
        map_subscribe_transient_local: true
        enabled: true
        subscribe_to_updates: true
        transform_tolerance: 1.0

      obstacle_layer:
        plugin: "nav2_costmap_2d::ObstacleLayer"
        enabled: true
        observation_sources: scan
        footprint_clearing_enabled: true
        max_obstacle_height: 2.0
        combination_method: 1

        scan:
          topic: /scan
          obstacle_max_range: 2.5
          obstacle_min_range: 0.0
          raytrace_max_range: 3.0
          raytrace_min_range: 0.0
          clearing: true
          marking: true
          data_type: "LaserScan"
          min_obstacle_height: 0.0
          max_obstacle_height: 2.0

      inflation_layer:
        plugin: "nav2_costmap_2d::InflationLayer"
        enabled: true
        # TEAM 2 TODO: Complete inflation parameters
        # inflation_radius:
        # cost_scaling_factor:
        # inflate_unknown: false
        # inflate_around_unknown: true

        # HELPFUL LINKS for completing these parameters:
        # Inflation Layer Reference: https://docs.nav2.org/configuration/packages/costmap-plugins/inflation.html

local_costmap:
  local_costmap:
    ros__parameters:
      update_frequency: 5.0
      publish_frequency: 2.0
      global_frame: odom
      robot_base_frame: base_link
      use_sim_time: false
      rolling_window: true
      width: 3
      height: 3
      resolution: 0.05

      footprint: "[[-0.356, -0.340], [0.356, -0.340], [0.356, 0.340], [-0.356, 0.340]]"

      plugins: ["obstacle_layer", "inflation_layer"]

      obstacle_layer:
        plugin: "nav2_costmap_2d::ObstacleLayer"
        enabled: true
        observation_sources: scan
        footprint_clearing_enabled: true
        max_obstacle_height: 2.0
        combination_method: 1

        scan:
          topic: /scan
          obstacle_max_range: 2.5
          obstacle_min_range: 0.0
          raytrace_max_range: 3.0
          raytrace_min_range: 0.0
          clearing: true
          marking: true
          data_type: "LaserScan"
          expected_update_rate: 0.0
          observation_persistence: 0.0
          inf_is_valid: false
          clear_after_reading: true
          min_obstacle_height: 0.0
          max_obstacle_height: 2.0

      inflation_layer:
        plugin: "nav2_costmap_2d::InflationLayer"
        enabled: true
        # TEAM 2 TODO: Match global costmap inflation settings

        # HELPFUL LINKS for local costmap completion:
        # Local Costmap Guide: https://docs.nav2.org/configuration/packages/configuring-costmaps.html

planner_server:
  ros__parameters:
    expected_planner_frequency: 20.0
    planner_plugins: ["GridBased"]
    use_sim_time: false

    GridBased:
      plugin: "nav2_smac_planner::SmacPlannerHybrid"
      tolerance: 0.25
      downsample_costmap: false
      allow_unknown: true
      max_planning_time: 5.0
      motion_model_for_search: "DUBIN"
      angle_quantization_bins: 72
      analytic_expansion_ratio: 3.5
      analytic_expansion_max_length: 3.0
      minimum_turning_radius: 0.40
      # TEAM 2 TODO: Complete planner penalty parameters

      # HELPFUL LINKS for completing planner configuration:
      # Smac Planner Parameters: https://docs.nav2.org/configuration/packages/configuring-smac-planner.html
      # Planning Tuning Guide: https://docs.nav2.org/tuning/index.html

smoother_server:
  ros__parameters:
    use_sim_time: false
    smoother_plugins: ["simple_smoother"]

    simple_smoother:
      plugin: "nav2_smoother::SimpleSmoother"
      tolerance: 1.0e-10
      max_its: 1000
      do_refinement: true
```

═══════════════════════════════════════════════════════════════════════════════

## TESTING PROCEDURES

### Test 1: Individual Costmap Layer Testing

**Normal Phase 3 Workflow (Using Real Sensor Data):**

```bash
# Test with real LiDAR data from rslidar_laserscan_converter
# Verify /scan topic is available (should be from Phase 2)
ros2 topic echo /scan --once
ros2 topic hz /scan

# Test global costmap with real sensor data
ros2 run nav2_costmap_2d nav2_costmap_2d \
  --ros-args -p use_sim_time:=false \
  -r __node:=test_global_costmap \
  --params-file config/global_costmap_params.yaml

# Test local costmap with real sensor data
ros2 run nav2_costmap_2d nav2_costmap_2d \
  --ros-args -p use_sim_time:=false \
  -r __node:=test_local_costmap \
  --params-file config/local_costmap_params.yaml
```

**Fallback Testing (Only When Team 1 is Offline):**

```bash
# OPTIONAL: Test static layer with any existing map (if Team 1 not ready)
ros2 run nav2_map_server map_server \
  --ros-args -p yaml_filename:=/path/to/any/map.yaml &

# OPTIONAL: Publish fake scan data for obstacle layer testing (fallback only)
ros2 topic pub /scan sensor_msgs/msg/LaserScan \
  '{header: {frame_id: "base_link", stamp: {sec: 0, nanosec: 0}},
    angle_min: -3.14159, angle_max: 3.14159, angle_increment: 0.087,
    range_min: 0.1, range_max: 10.0,
    ranges: [2.0, 1.5, 1.0, 0.5, 1.0, 1.5, 2.0, 2.0, 2.0]}'
```

**What You Should See (Normal Workflow):**

- Costmap publishes to `/test_global_costmap/costmap` or `/test_local_costmap/costmap`
- Obstacle layer responds to **real** LiDAR data from `/scan`
- Static layer shows map data (once Team 1's map server is running)
- Real obstacles in your environment appear in costmaps

─────────────────────────────────────────────────────────────────────────────

### Test 2: Costmap Integration Testing (Requires Team 1)

```bash
# Launch Team 1's localization first
ros2 launch scout_mini_localization localization.launch.py

# Launch costmap servers
ros2 run nav2_costmap_2d nav2_costmap_2d \
  --ros-args -p use_sim_time:=false \
  -r __node:=global_costmap \
  --params-file config/nav2_params.yaml &

ros2 run nav2_costmap_2d nav2_costmap_2d \
  --ros-args -p use_sim_time:=false \
  -r __node:=local_costmap \
  --params-file config/nav2_params.yaml &

# Open RViz for visualization
ros2 run rviz2 rviz2
```

**RViz Setup for Team 2 Testing:**

1. Set **Fixed Frame** to `map`
2. Add **Map** display (`/map`)
3. Add **Costmap** display (`/global_costmap/costmap`)
4. Add **Costmap** display (`/local_costmap/costmap`)
5. Add **LaserScan** display (`/scan`)
6. Add **RobotModel** display
7. Add **TF** display to see coordinate frames

**Success Indicators:**

- Global costmap shows your map with inflated obstacles
- Local costmap shows 3×3m rolling window around robot
- Obstacles appear/disappear in real-time as LiDAR detects them
- Robot footprint is visible and properly sized

─────────────────────────────────────────────────────────────────────────────

### Test 3: Path Planning Service Testing

```bash
# Launch costmaps (from Test 2) plus planner server
ros2 run nav2_planner planner_server \
  --ros-args --params-file config/nav2_params.yaml &

# Test planning service directly
ros2 service call /compute_path_to_pose nav2_msgs/srv/ComputePathToPose \
  "{
    goal: {
      header: {frame_id: 'map', stamp: {sec: 0, nanosec: 0}},
      pose: {
        position: {x: 2.0, y: 1.0, z: 0.0},
        orientation: {x: 0.0, y: 0.0, z: 0.0, w: 1.0}
      }
    },
    planner_id: 'GridBased',
    use_start: false
  }"

# Monitor the generated path
ros2 topic echo /plan
```

**Expected Results:**

- Service returns `SUCCESS` status
- `/plan` topic publishes a valid path
- Path avoids obstacles and inflated areas
- Path respects Scout Mini's minimum turning radius
- Path waypoints are reasonably spaced (not too dense/sparse)

─────────────────────────────────────────────────────────────────────────────

### Test 4: Dynamic Obstacle Testing

```bash
# With all Team 2 components running (costmaps + planner)

# Place cardboard box or obstacle in front of robot
# Watch local costmap update to show the obstacle

# Send planning goal that would go through the obstacle area
# Verify planner creates path around the obstacle

# Remove obstacle
# Verify costmap clears the obstacle within 1-2 seconds
# Send same planning goal - path should be more direct
```

**Pro Tip:** Use a large cardboard box or chair as a test obstacle. It should be tall enough for the LiDAR to detect (> 5cm high) and wide enough to create a clear costmap signature.

═══════════════════════════════════════════════════════════════════════════════

## TROUBLESHOOTING GUIDE

### Problem: "Global costmap is empty or shows no map data"

**Symptoms:**

- Costmap appears blank in RViz
- Planning fails with "start or goal in lethal space"
- No static obstacles visible despite having a map

**Diagnosis Steps:**

```bash
# Check if map server is running and publishing
ros2 topic echo /map --once
ros2 topic hz /map

# Verify costmap is subscribing to map
ros2 node info /global_costmap
# Look for subscriptions to /map topic

# Check static layer configuration
ros2 param get /global_costmap/global_costmap static_layer.enabled
```

**Common Solutions:**

```yaml
# Ensure static layer is properly configured
static_layer:
  plugin: "nav2_costmap_2d::StaticLayer"
  map_subscribe_transient_local: true # CRITICAL for reliable subscription
  enabled: true
  subscribe_to_updates: true

# Check coordinate frame consistency
global_frame: map # Must match Team 1's map frame
robot_base_frame: base_link # Must match URDF
```

─────────────────────────────────────────────────────────────────────────────

### Problem: "Local costmap not updating with obstacles"

**Symptoms:**

- No obstacles appear in local costmap despite LiDAR detecting them
- Robot plans through clearly visible obstacles
- Costmap remains empty except for robot footprint

**Diagnosis Steps:**

```bash
# Verify LiDAR data is available
ros2 topic echo /scan --once
ros2 topic hz /scan

# Check coordinate frame of laser data
ros2 topic echo /scan | grep frame_id

# Verify transforms from laser frame to base_link
ros2 run tf2_ros tf2_echo base_link laser_frame
```

**Common Solutions:**

```bash
# Check that rslidar_laserscan_converter is running
ros2 node list | grep lidar

# Verify scan topic name matches configuration
scan:
  topic: /scan  # Must match actual topic name
  data_type: "LaserScan"

# Ensure laser frame transforms to base_link
# Check your URDF has the correct laser frame defined
```

─────────────────────────────────────────────────────────────────────────────

### Problem: "Planner fails with 'No valid path found'"

**Symptoms:**

- Planning service returns `FAILED` status
- Plans work in open areas but fail near obstacles
- Very slow planning performance (> 5 seconds)

**Diagnosis Steps:**

```bash
# Check if goal is in valid space
# In RViz, examine costmap at the goal location
# Goal should be in free space (white/gray), not inflated (blue) or lethal (black)

# Test with closer, simpler goals first
ros2 service call /compute_path_to_pose nav2_msgs/srv/ComputePathToPose \
  # Try goal only 1 meter away in clear space

# Check planner performance
ros2 param get /planner_server GridBased.max_planning_time
```

**Common Solutions:**

```yaml
# Increase planning timeout for complex environments
max_planning_time: 10.0

# Reduce goal tolerance if it's too strict
tolerance: 0.5

# For initial testing, try simpler NavFn planner
GridBased:
  plugin: "nav2_navfn_planner::NavfnPlanner"
  tolerance: 0.25
  use_astar: true
  allow_unknown: true
```

─────────────────────────────────────────────────────────────────────────────

### Problem: "Inflation creates too much or too little safety margin"

**Symptoms:**

- Robot won't plan through clearly passable spaces (over-inflated)
- Robot plans too close to obstacles (under-inflated)
- Costmap takes very long to compute (over-inflated)

**Tuning Guidelines:**

```yaml
# Conservative settings (safer, but may limit navigation)
inflation_radius: 0.8        # Robot radius (0.4m) + extra safety (0.4m)
cost_scaling_factor: 1.0     # Linear cost decay

# Aggressive settings (more navigation options, less safety margin)
inflation_radius: 0.45       # Robot radius (0.4m) + minimal safety (0.05m)
cost_scaling_factor: 2.0     # Faster cost decay (cheaper to get close)

# Balanced settings (recommended starting point)
inflation_radius: 0.55       # Robot radius + moderate safety
cost_scaling_factor: 1.0     # Linear decay
```

**Visual Tuning in RViz:**

- Blue areas = inflated (expensive but passable)
- Black areas = lethal (impassable)
- White/gray areas = free space
- Adjust inflation until blue zones look reasonable for Scout Mini

**Additional Resources for Inflation Tuning:**

- **Costmap Concepts**: https://docs.nav2.org/concepts/index.html#costmap-2d
- **Parameter Reference**: https://docs.nav2.org/configuration/packages/costmap-plugins/inflation.html
- **Visual Tuning Guide**: https://automaticaddison.com/ros-2-navigation-tuning-guide-nav2/

═══════════════════════════════════════════════════════════════════════════════

## PARAMETER TUNING GUIDELINES

### Inflation Layer Tuning (Critical for Safety vs Mobility)

```yaml
# Start with these values and adjust based on testing
inflation_layer:
  inflation_radius: 0.55 # Robot radius (0.4m) + safety margin (0.15m)
  cost_scaling_factor: 1.0 # Linear cost decay from obstacles
  inflate_unknown: false # Don't inflate unknown space
  inflate_around_unknown: true # Inflate boundaries with unknown areas
```

**Tuning Strategy:**

1. **Too Conservative**: Robot won't navigate through doorways or narrow passages

   - Reduce `inflation_radius` by 0.05m increments
   - Increase `cost_scaling_factor` to make approach less expensive

2. **Too Aggressive**: Robot plans too close to obstacles for comfort

   - Increase `inflation_radius` by 0.05m increments
   - Keep `cost_scaling_factor` at 1.0 for linear decay

3. **Performance Issues**: Costmap updates too slowly
   - Reduce `inflation_radius` to decrease computation
   - Consider coarser resolution (0.1m instead of 0.05m)

**Reference Links for Advanced Tuning:**

- **Nav2 Tuning Guide**: https://docs.nav2.org/tuning/index.html
- **Costmap Plugin Tuning**: https://navigation.ros.org/tuning/index.html

─────────────────────────────────────────────────────────────────────────────

### Obstacle Layer Tuning

```yaml
# Recommended starting values
obstacle_layer:
  obstacle_max_range: 2.5 # Mark obstacles within 2.5m
  raytrace_max_range: 3.0 # Clear free space to 3.0m
  clearing: true # Clear old obstacles
  marking: true # Mark new obstacles


  # Advanced tuning options:
  # obstacle_min_range: 0.1   # Ignore very close readings (sensor noise)
  # max_obstacle_height: 1.5  # Ignore overhead obstacles
  # expected_update_rate: 10.0  # Expected sensor update rate (Hz)
```

**Obstacle Detection Problems:**

- **False Positives**: Reduce `obstacle_max_range`, increase `obstacle_min_range`
- **Missing Obstacles**: Increase `obstacle_max_range`, check LiDAR data quality
- **Persistent Ghost Obstacles**: Ensure `clearing: true` and check transform accuracy

**Reference Links:**

- **Obstacle Layer Configuration**: https://docs.nav2.org/configuration/packages/costmap-plugins/obstacle.html
- **Sensor Integration**: https://docs.nav2.org/setup_guides/sensors/mapping_localization.html

─────────────────────────────────────────────────────────────────────────────

### Planner Tuning for Scout Mini

```yaml
# Recommended penalties for Scout Mini skid-steer
GridBased:
  reverse_penalty: 3.0 # Strongly discourage backing up
  change_penalty: 0.2 # Small penalty for direction changes
  non_straight_penalty: 1.5 # Prefer straight paths when possible
  cost_penalty: 2.0 # Avoid high-cost (near obstacle) areas
  retrospective_penalty: 0.02 # Discourage backtracking in search

  # Performance vs accuracy trade-offs
  max_iterations: 1000000 # Higher = more thorough search, slower
  analytic_expansion_ratio: 3.5 # Lower = try shortcuts sooner, faster
  smooth_path: true # Post-process for smoother curves
```

**Performance Tuning:**

- **Too Slow**: Reduce `max_iterations`, increase `analytic_expansion_ratio`
- **Poor Paths**: Increase `max_iterations`, enable `smooth_path`
- **Doesn't Respect Kinematics**: Ensure `motion_model_for_search: "DUBIN"`

**Reference Links:**

- **Smac Planner Tuning**: https://docs.nav2.org/configuration/packages/configuring-smac-planner.html
- **Planning Performance**: https://docs.nav2.org/tuning/index.html

═══════════════════════════════════════════════════════════════════════════════

## TEAM 2 HANDOFF CHECKLIST

### Configuration Files (Must Complete)

- [ ] `costmap_common_params.yaml` with Scout Mini footprint and shared settings
- [ ] `global_costmap_params.yaml` with complete layer configuration
- [ ] `local_costmap_params.yaml` with rolling window and obstacle processing
- [ ] `planner_params.yaml` with Smac Hybrid-A\* configuration for Scout Mini
- [ ] Updated `nav2_params.yaml` with complete Team 2 section

─────────────────────────────────────────────────────────────────────────────

### Integration Verification (Must Pass These Tests)

- [ ] **Global Costmap Integration**: Shows Team 1's map data with proper obstacle inflation
- [ ] **Local Costmap Function**: 3×3m rolling window updates with real-time LiDAR data
- [ ] **Obstacle Detection**: Objects appear in costmaps within 1 second of LiDAR detection
- [ ] **Obstacle Clearing**: Removed objects clear from costmaps within 2 seconds
- [ ] **Path Planning**: `/plan` topic publishes valid paths to reachable goals

─────────────────────────────────────────────────────────────────────────────

### Performance Validation (Document Results)

```bash
# Test 1: Costmap update rate
ros2 topic hz /global_costmap/costmap  # Should be ~1 Hz
ros2 topic hz /local_costmap/costmap   # Should be ~2 Hz

# Test 2: Planning response time
time ros2 service call /compute_path_to_pose [goal_parameters]
# Result: Should complete within 2 seconds for typical goals

# Test 3: Obstacle response time
# Place obstacle, measure time to appear in costmap
# Remove obstacle, measure time to clear from costmap
# Both should be < 2 seconds
```

─────────────────────────────────────────────────────────────────────────────

### What Team 3 Can Expect from You

**Guaranteed Outputs:**

- Global costmap available via `/global_costmap/costmap` topic
- Local costmap available via `/local_costmap/costmap` topic
- Valid paths published to `/plan` topic when goals are sent
- Scout Mini footprint properly configured in all costmap layers

**Quality Standards:**

- **Obstacle Detection Latency**: < 1 second from LiDAR detection to costmap
- **Obstacle Clearing Time**: < 2 seconds from removal to costmap clearing
- **Planning Success Rate**: > 95% for goals in reachable free space
- **Planning Response Time**: < 2 seconds for goals within 10 meters

**Coordinate Frame Guarantees:**

- Global costmap uses `map` frame (matches Team 1's localization)
- Local costmap uses `odom` frame (for dynamic planning)
- All paths in `/plan` use `map` frame coordinates

─────────────────────────────────────────────────────────────────────────────

### What You Need from Team 3

**From Team 3 (Controllers + Behavior Trees):**

- Controller configurations that respect your costmap resolution (0.05m)
- Path-following algorithms that work with Smac Hybrid-A\* waypoint spacing
- Recovery behaviors that don't interfere with costmap updates

─────────────────────────────────────────────────────────────────────────────

### Critical Handoff Information

**Topic Names (Team 3 will consume):**

```bash
/global_costmap/costmap         # Global environment representation
/local_costmap/costmap          # Local obstacle avoidance data
/plan                           # Global paths to navigation goals
/global_costmap/published_footprint  # Robot footprint for visualization
```

**Service Names (Team 3 may use):**

```bash
/compute_path_to_pose           # Planning service
/global_costmap/clear_entirely_global_costmap  # Emergency costmap clearing
/local_costmap/clear_entirely_local_costmap    # Emergency costmap clearing
```

**Parameter Coordination (Share with Team 3):**

```yaml
# Robot footprint - Team 3 must use same values
footprint: "[[-0.356, -0.340], [0.356, -0.340], [0.356, 0.340], [-0.356, 0.340]]"

# Planning/control coordination
goal_tolerance: 0.25 # Team 3 controller must match or be tighter
max_vel_x: 0.5 # Team 3 must respect this velocity limit
min_turning_radius: 0.40 # Team 3 controller must respect kinematic limits
```

**Additional Resources for Team Coordination:**

- **Nav2 Architecture**: https://docs.nav2.org/concepts/index.html
- **Integration Examples**: https://github.com/ros-planning/navigation2_tutorials
- **Community Support**: https://robotics.stackexchange.com/questions/tagged/nav2

Remember: Your costmaps are the "eyes" of the navigation system, and your planner is its "brain." Take time to tune them properly - Team 3's controller can only be as good as the paths you provide!

═══════════════════════════════════════════════════════════════════════════════
