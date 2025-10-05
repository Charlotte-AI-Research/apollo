# Team 3: Controllers and Behavior Trees

═══════════════════════════════════════════════════════════════════════════════

## TEAM MISSION STATEMENT

**"Team 3 handles 'How do I follow the path?' and 'What do I do when stuck?' through precise trajectory tracking and intelligent recovery behaviors."**

You are the execution team. You take the brilliant paths from Team 2 and make them reality through smooth, safe robot motion. When things go wrong (and they will), your recovery behaviors get the robot unstuck and back on track.

**Why Your Work Matters:** Perfect planning is useless if the robot can't follow the path smoothly or recover from unexpected situations. You turn navigation plans into real robot movement and handle all the edge cases that make autonomous navigation reliable in the real world.

═══════════════════════════════════════════════════════════════════════════════

## YOUR ROLE IN THE NAVIGATION PIPELINE

```
Team 1 (Where am I?)  →  Team 2 (How do I get there?)  →  Team 3 (YOU - Execute the plan!)
- /amcl_pose         →  - Global/local costmaps       →  - Path following (/cmd_vel)
- Stable localization →  - /plan (path to goal)       →  - Obstacle avoidance
- Transform chain    →  - Obstacle detection         →  - Recovery behaviors
                                                      →  - Goal achievement
```

═══════════════════════════════════════════════════════════════════════════════

## DEPENDENCIES AND PARALLEL WORK STRATEGY

### What You Need from Other Teams (Dependencies)

**From Team 1 (Critical Dependencies):**

- **Stable `/amcl_pose`** - Controller needs to know where robot is for coordinate conversions
- **Continuous transforms** - Essential for converting between map, odom, and base_link frames
- **Lifecycle coordination** - Your servers need proper startup sequencing in the right order

**From Team 2 (Critical Dependencies):**

- **Valid `/plan` topic** - You can't follow a path that doesn't exist or is invalid
- **Accurate costmaps** - Needed for local obstacle avoidance during path execution
- **Proper robot footprint** - Controller must know robot dimensions for safe navigation

─────────────────────────────────────────────────────────────────────────────

### What You Can Do While Other Teams Work (Parallel Work)

**What You Can Do While Waiting (Independent Tasks):**

```bash
# 1. Research and draft controller configurations
# Study Nav2 controller documentation and examples

# 2. Test basic controllers with fake data (before Team 2 is ready)
ros2 run nav2_controller controller_server \
  --ros-args --params-file your_draft_config.yaml

# Publish fake path for controller testing
ros2 topic pub /plan nav_msgs/msg/Path \
  '{header: {frame_id: "map"}, poses: [
    {header: {frame_id: "map"}, pose: {position: {x: 0.0, y: 0.0, z: 0.0}, orientation: {w: 1.0}}},
    {header: {frame_id: "map"}, pose: {position: {x: 1.0, y: 0.0, z: 0.0}, orientation: {w: 1.0}}},
    {header: {frame_id: "map"}, pose: {position: {x: 2.0, y: 1.0, z: 0.0}, orientation: {w: 1.0}}}
  ]}'

# 3. Tune velocity/acceleration parameters offline
# Test different controller parameters using fake paths and odometry

# 4. Draft Behavior Tree XML files
# Study Nav2 behavior tree concepts and prepare custom XML modifications
```

**Research and Preparation Tasks:**

- Compare Regulated Pure Pursuit vs DWB controllers for Scout Mini
- Study Nav2 behavior tree documentation and default navigation trees
- Research recovery behavior strategies (backup, spin, wait, clear costmaps)
- Draft controller parameter files using Scout Mini's physical constraints

═══════════════════════════════════════════════════════════════════════════════

## SCOUT MINI CONTROL CONSTRAINTS

**Critical for Your Work:**

```yaml
# Physical velocity limits (ENFORCE THESE in your controller)
max_vel_x: 0.5 # 0.5 m/s max forward speed (safe for indoors)
min_vel_x: -0.2 # Limited reverse capability
max_vel_y: 0.0 # No lateral movement (skid-steer)
min_vel_y: 0.0
max_vel_theta: 1.0 # 1.0 rad/s max rotation speed

# Acceleration limits
max_accel_x: 2.5 # Forward/reverse acceleration
max_accel_theta: 3.2 # Rotational acceleration

# Physical constraints
min_turning_radius: 0.40 # Minimum turn radius due to skid-steer
robot_radius: 0.40 # For obstacle avoidance calculations

# Goal tolerances
xy_goal_tolerance: 0.25 # 25cm position tolerance
yaw_goal_tolerance: 0.25 # ~14 degree orientation tolerance
```

**Pro Tip:** Scout Mini's skid-steer drive means it can't move sideways and has a minimum turning radius. Your controller must respect these kinematic constraints!

═══════════════════════════════════════════════════════════════════════════════

## STEP-BY-STEP SETUP INSTRUCTIONS

### Step 1: Choose and Configure Path Following Controller

**What You're About to Implement:**
The path following controller is like a skilled driver that takes the planned route from Team 2 and actually steers the robot along it. It constantly adjusts wheel speeds to follow the path while respecting Scout Mini's physical limitations and avoiding obstacles.

**How This Works:**

- Receives planned path from Team 2's planner as a series of waypoints
- Calculates steering commands to follow the path smoothly
- Monitors for obstacles and adjusts trajectory in real-time
- Enforces Scout Mini's velocity limits and kinematic constraints
- Outputs velocity commands that scout_mini_base can execute

**Why This Matters:**
Having a perfect path is useless if you can't follow it smoothly. The controller translates high-level plans into low-level motor commands while handling real-world uncertainties.

**What You'll Create:**
A controller configuration that enables smooth, safe path following optimized for Scout Mini's skid-steer characteristics.

---

**Option A: Regulated Pure Pursuit (Recommended for Beginners)**

Create `apollo_ws/src/scout_mini_navigation/config/controller_params.yaml`:

```yaml
controller_server:
  ros__parameters:
    use_sim_time: false
    controller_frequency: 20.0 # Control loop at 20 Hz
    min_x_velocity_threshold: 0.001 # Minimum velocity to be considered moving
    min_y_velocity_threshold: 0.5 # Not used for Scout Mini (no lateral)
    min_theta_velocity_threshold: 0.001 # Minimum rotation to be considered turning
    failure_tolerance: 0.3 # Time to wait before declaring failure

    # Progress and goal checking
    progress_checker_plugins: ["progress_checker"]
    goal_checker_plugins: ["goal_checker"]
    controller_plugins: ["FollowPath"]

    # Progress checker - detects if robot is making progress toward goal
    progress_checker:
      plugin: "nav2_controller::SimpleProgressChecker"
      required_movement_radius: 0.5 # Must move 0.5m in time window
      movement_time_allowance: 10.0 # 10 second window for movement

    # Goal checker - determines when goal is reached
    goal_checker:
      plugin: "nav2_controller::SimpleGoalChecker"
      xy_goal_tolerance: 0.25 # 25cm position tolerance
      yaw_goal_tolerance: 0.25 # ~14 degree orientation tolerance
      stateful: true # Remember goal achievement

    # Regulated Pure Pursuit Controller
    FollowPath:
      plugin: "nav2_regulated_pure_pursuit_controller::RegulatedPurePursuitController"

      # Scout Mini velocity limits
      desired_linear_vel: 0.5 # Preferred cruising speed
      max_linear_accel: 2.5 # Forward acceleration limit
      max_linear_decel: 2.5 # Braking deceleration limit
      max_angular_accel: 3.2 # Rotational acceleration limit
      max_angular_vel: 1.0 # Maximum rotation speed

      # Pure pursuit algorithm parameters
      lookahead_dist: 0.6 # Distance to look ahead on path
      min_lookahead_dist: 0.3 # Minimum lookahead distance
      max_lookahead_dist: 0.9 # Maximum lookahead distance
      lookahead_time: 1.5 # Time-based lookahead (alternative)

      # TEAM 3 TODO: Tune these regulation features through testing
      # use_velocity_scaled_lookahead_dist: [true/false - adjust lookahead based on speed]
      # min_approach_linear_velocity: [slow down when approaching goal - try 0.05]
      # approach_velocity_scaling_dist: [distance to start slowing - try 0.6]
      # use_collision_detection: [enable obstacle avoidance - try true]
      # use_regulated_linear_velocity_scaling: [slow down for tight turns - try true]
      # regulated_linear_scaling_min_radius: [radius to start slowing - try 0.90]
      # regulated_linear_scaling_min_speed: [minimum speed in turns - try 0.25]

      # Rotate to heading behavior (turn toward goal orientation)
      # use_rotate_to_heading: [true to align with goal orientation]
      # rotate_to_heading_angular_vel: [speed for final orientation - try 1.8]
      # max_allowed_time_to_collision: [safety margin - try 1.0]
      # use_interpolation: [smooth path following - try true]

      # Transform and goal handling
      transform_tolerance: 0.1 # Transform lookup tolerance
      allow_reversing: false # Don't allow backing up


      # HELPFUL LINKS for completing Pure Pursuit configuration:
      # Regulated Pure Pursuit Docs: https://docs.nav2.org/configuration/packages/configuring-regulated-pp.html
      # Controller Concepts: https://docs.nav2.org/concepts/index.html#controller
      # Tuning Guide: https://automaticaddison.com/ros-2-navigation-tuning-guide-nav2/
```

─────────────────────────────────────────────────────────────────────────────

**Option B: DWB Controller (Advanced - Better Obstacle Avoidance)**

```yaml
# Alternative controller configuration for advanced users
controller_server:
  ros__parameters:
    use_sim_time: false
    controller_frequency: 20.0
    controller_plugins: ["FollowPath"]

    FollowPath:
      plugin: "dwb_core::DWBLocalPlanner"
      debug_trajectory_details: false

      # Scout Mini velocity limits
      min_vel_x: 0.0
      min_vel_y: 0.0
      max_vel_x: 0.5
      max_vel_y: 0.0 # No lateral movement for skid-steer
      max_vel_theta: 1.0
      min_speed_xy: 0.0
      max_speed_xy: 0.5

      # Acceleration limits
      acc_lim_x: 2.5
      acc_lim_y: 0.0 # No lateral acceleration
      acc_lim_theta: 3.2
      decel_lim_x: -2.5
      decel_lim_y: 0.0
      decel_lim_theta: -3.2

      # TEAM 3 TODO: Tune these DWB parameters through testing
      # vx_samples: [number of forward velocity samples - try 20]
      # vy_samples: [lateral velocity samples - try 5 for skid-steer]
      # vtheta_samples: [rotation velocity samples - try 20]
      # sim_time: [trajectory simulation time - try 1.7]

      # Trajectory scoring critics (these determine path selection)
      # critics: ["RotateToGoal", "Oscillation", "BaseObstacle", "GoalAlign", "PathAlign", "PathDist", "GoalDist"]
      # BaseObstacle.scale: [obstacle avoidance weight - try 0.02]
      # PathAlign.scale: [path following weight - try 32.0]
      # GoalAlign.scale: [goal alignment weight - try 24.0]
      # PathDist.scale: [distance to path weight - try 32.0]
      # GoalDist.scale: [distance to goal weight - try 24.0]

      # HELPFUL LINKS for completing DWB configuration:
      # DWB Controller Docs: https://docs.nav2.org/configuration/packages/configuring-dwb-controller.html
      # DWB Critics Guide: https://docs.nav2.org/configuration/packages/dwb-plugins/index.html
```

─────────────────────────────────────────────────────────────────────────────

### Step 2: Configure Behavior Tree Navigator

**What You're About to Implement:**
The behavior tree navigator is like the "mission commander" that orchestrates the entire navigation process. It decides when to plan, when to follow paths, when to give up, and when to try recovery behaviors if things go wrong.

**How This Works:**

- Coordinates all navigation actions in a logical sequence
- Monitors progress toward goals and detects when robot gets stuck
- Triggers replanning when paths become invalid
- Initiates recovery behaviors when normal navigation fails
- Manages timeouts and failure conditions

**Why This Matters:**
Without this coordination, navigation components would work independently and couldn't handle complex scenarios like dynamic obstacles, unreachable goals, or recovery from stuck situations.

**What You'll Create:**
A behavior tree configuration that provides intelligent navigation coordination and robust failure handling.

---

Create `apollo_ws/src/scout_mini_navigation/config/bt_navigator_params.yaml`:

```yaml
bt_navigator:
  ros__parameters:
    use_sim_time: false
    global_frame: map # Planning frame (from Team 1)
    robot_base_frame: base_link # Robot frame
    odom_topic: /odom # Odometry topic (from scout_mini_base)
    bt_loop_duration: 10 # Behavior tree execution frequency (10 Hz)
    default_server_timeout: 20 # Default action timeout (seconds)
    wait_for_service_timeout: 1000 # Service connection timeout (ms)
    action_server_result_timeout: 900.0 # Action result timeout

    # Available navigator types
    navigators: ["navigate_to_pose", "navigate_through_poses"]

    # Use Nav2's default behavior trees (or specify custom ones)
    default_nav_to_pose_bt_xml: "" # Empty = use default
    default_nav_through_poses_bt_xml: "" # Empty = use default

    # Behavior tree plugin libraries (required for BT nodes)
    plugin_lib_names:
      - nav2_compute_path_to_pose_action_bt_node
      - nav2_compute_path_through_poses_action_bt_node
      - nav2_smooth_path_action_bt_node
      - nav2_follow_path_action_bt_node
      - nav2_spin_action_bt_node
      - nav2_wait_action_bt_node
      - nav2_back_up_action_bt_node
      - nav2_clear_costmap_service_bt_node
      - nav2_is_stuck_condition_bt_node
      - nav2_goal_reached_condition_bt_node
      - nav2_goal_updated_condition_bt_node
      - nav2_is_path_valid_condition_bt_node
      - nav2_initial_pose_received_condition_bt_node
      - nav2_reinitialize_global_localization_service_bt_node
      - nav2_rate_controller_bt_node
      - nav2_distance_controller_bt_node
      - nav2_recovery_node_bt_node
      - nav2_pipeline_sequence_bt_node
      - nav2_round_robin_node_bt_node
      - nav2_transform_available_condition_bt_node
      - nav2_time_expired_condition_bt_node
      - nav2_distance_traveled_condition_bt_node
      - nav2_single_trigger_bt_node
      - nav2_navigate_to_pose_action_bt_node
      - nav2_navigate_through_poses_action_bt_node

      # HELPFUL LINKS for behavior tree configuration:
      # Behavior Tree Concepts: https://docs.nav2.org/behavior_trees/index.html
      # BT Navigator Configuration: https://docs.nav2.org/configuration/packages/configuring-bt-xml.html
      # Default Behavior Trees: https://docs.nav2.org/behavior_trees/trees/nav_to_pose_and_pause_near_goal_obstacle.html
```

─────────────────────────────────────────────────────────────────────────────

### Step 3: Configure Recovery Behaviors

**What You're About to Implement:**
Recovery behaviors are like "emergency procedures" that help your robot get unstuck when normal navigation fails. Think of them as the robot's problem-solving toolkit for common navigation challenges.

**How This Works:**

- Spin: Rotates robot to clear sensor confusion or reorient
- Backup: Reverses robot away from obstacles it's stuck against
- Drive on Heading: Moves robot in specific direction to escape tight spaces
- Wait: Pauses to let dynamic obstacles (people) move away
- Each behavior has safety limits and timeouts

**Why This Matters:**
Real-world navigation inevitably encounters situations where robots get stuck. Without recovery behaviors, your robot would give up on perfectly achievable goals.

**What You'll Create:**
A set of recovery behavior configurations that help Scout Mini escape common stuck situations safely.

---

Create `apollo_ws/src/scout_mini_navigation/config/recovery_params.yaml`:

```yaml
behavior_server:
  ros__parameters:
    use_sim_time: false
    behavior_plugins: ["spin", "backup", "drive_on_heading", "wait"]

    # Spin recovery - rotate in place to clear confusion
    spin:
      plugin: "nav2_behaviors::Spin"
      simulate_ahead_time: 2.0 # Look ahead time for safety
      max_rotational_vel: 1.0 # Maximum spin speed
      min_rotational_vel: 0.4 # Minimum spin speed
      rotational_acc_lim: 3.2 # Rotation acceleration limit

    # Backup recovery - back up to get unstuck
    backup:
      plugin: "nav2_behaviors::BackUp"
      simulate_ahead_time: 2.0 # Safety lookahead
      # TEAM 3 TODO: Tune backup behavior parameters
      # backup_speed: [how fast to back up - try 0.025 m/s]
      # time_allowance: [how long to try backing up - try 10 seconds]

    # Drive on heading - move in specific direction
    drive_on_heading:
      plugin: "nav2_behaviors::DriveOnHeading"
      simulate_ahead_time: 2.0
      # TEAM 3 TODO: Configure drive on heading parameters
      # speed: [forward driving speed - try 0.025 m/s]
      # time_allowance: [how long to drive - try 10 seconds]

    # Wait recovery - pause and let dynamic obstacles clear
    wait:
      plugin: "nav2_behaviors::Wait"
      # No additional parameters needed - just waits for specified duration

      # HELPFUL LINKS for completing recovery behavior configuration:
      # Recovery Behavior Docs: https://docs.nav2.org/configuration/packages/configuring-behavior-server.html
      # Behavior Server Concepts: https://docs.nav2.org/concepts/index.html#behavior-server
      # Recovery Strategies: https://docs.nav2.org/behavior_trees/index.html
```

**Recovery Behavior Strategy:**

- **Spin**: Used when robot is confused about its orientation
- **Backup**: Used when robot is stuck against an obstacle
- **Drive on Heading**: Used to escape from confined spaces
- **Wait**: Used when temporary obstacles (people) are blocking the path

─────────────────────────────────────────────────────────────────────────────

### Step 4: Add Team 3 Configuration to nav2_params.yaml

**What You're About to Implement:**
You're integrating your controller and behavior tree configurations into the master Nav2 parameter file. This ensures all your settings work harmoniously with Teams 1 and 2's configurations in a unified system.

**How This Works:**

- Your controller settings become part of the central configuration
- Behavior tree and recovery parameters get integrated with the navigation stack
- Single unified file makes launching and debugging much easier
- Ensures parameter consistency across all navigation components

**Why This Matters:**
Scattered configuration files create integration nightmares and debugging difficulties. A unified approach ensures smooth coordination between all team configurations.

**What You'll Create:**
Your team's section of the master Nav2 configuration with all controller, behavior tree, and recovery parameters.

---

Add your section to `apollo_ws/src/scout_mini_navigation/config/nav2_params.yaml`:

```yaml
#==============================================================================
# TEAM 3: Controllers and Behavior Trees
#==============================================================================

controller_server:
  ros__parameters:
    use_sim_time: false
    controller_frequency: 20.0
    min_x_velocity_threshold: 0.001
    min_theta_velocity_threshold: 0.001
    failure_tolerance: 0.3

    progress_checker_plugins: ["progress_checker"]
    goal_checker_plugins: ["goal_checker"]
    controller_plugins: ["FollowPath"]

    progress_checker:
      plugin: "nav2_controller::SimpleProgressChecker"
      required_movement_radius: 0.5
      movement_time_allowance: 10.0

    goal_checker:
      plugin: "nav2_controller::SimpleGoalChecker"
      xy_goal_tolerance: 0.25
      yaw_goal_tolerance: 0.25
      stateful: true

    FollowPath:
      plugin: "nav2_regulated_pure_pursuit_controller::RegulatedPurePursuitController"
      # TEAM 3 TODO: Complete Regulated Pure Pursuit configuration
      # Add velocity limits, lookahead parameters, regulation features

      # HELPFUL LINKS for completing controller configuration:
      # Regulated Pure Pursuit: https://docs.nav2.org/configuration/packages/configuring-regulated-pp.html

bt_navigator:
  ros__parameters:
    use_sim_time: false
    global_frame: map
    robot_base_frame: base_link
    odom_topic: /odom
    bt_loop_duration: 10
    default_server_timeout: 20
    navigators: ["navigate_to_pose", "navigate_through_poses"]
    default_nav_to_pose_bt_xml: ""
    # TEAM 3 TODO: Add complete plugin library list

    # HELPFUL LINKS for BT navigator completion:
    # BT Navigator Configuration: https://docs.nav2.org/configuration/packages/configuring-bt-xml.html

behavior_server:
  ros__parameters:
    use_sim_time: false
    behavior_plugins: ["spin", "backup", "drive_on_heading", "wait"]
    # TEAM 3 TODO: Configure all recovery behaviors with appropriate parameters

    # HELPFUL LINKS for behavior server completion:
    # Behavior Server Configuration: https://docs.nav2.org/configuration/packages/configuring-behavior-server.html

waypoint_follower:
  ros__parameters:
    use_sim_time: false
    loop_rate: 20
    stop_on_failure: false
    waypoint_task_executor_plugin: "wait_at_waypoint"

    wait_at_waypoint:
      plugin: "nav2_waypoint_follower::WaitAtWaypoint"
      enabled: true
      waypoint_pause_duration: 200
```

═══════════════════════════════════════════════════════════════════════════════

## STEP-BY-STEP BEHAVIOR TREE CONFIGURATION

**Understanding Behavior Trees:** Behavior trees orchestrate the complete navigation logic, deciding when to plan, when to follow paths, and when to use recovery behaviors.

### Step 1: Start with Default Nav2 Behavior Tree

Begin with Nav2's proven default behavior tree, then customize it step by step:

```yaml
bt_navigator:
  ros__parameters:
    # Use Nav2's default behavior tree initially
    default_nav_to_pose_bt_xml: "" # Empty = use Nav2 default
    default_nav_through_poses_bt_xml: "" # Empty = use Nav2 default
```

**Default Nav2 Behavior Tree Flow:**

1. **Check Prerequisites**: Is localization working? Are costmaps available?
2. **Plan Path**: Request global path from Team 2's planner
3. **Follow Path**: Use your controller to execute the path
4. **Monitor Progress**: Check if robot is making progress toward goal
5. **Handle Failures**: If stuck or path becomes invalid, try recovery behaviors
6. **Retry or Fail**: After recovery, retry navigation or declare failure

**Test the Default Setup:**

```bash
# Launch behavior tree navigator with default XML
ros2 run nav2_bt_navigator bt_navigator \
  --ros-args --params-file config/nav2_params.yaml

# Send a simple navigation goal and observe behavior
ros2 action send_goal /navigate_to_pose nav2_msgs/action/NavigateToPose \
  "{pose: {header: {frame_id: map}, pose: {position: {x: 1.0, y: 0.0, z: 0.0}, orientation: {w: 1.0}}}}"
```

**Reference Links for Understanding Default Behavior:**

- **Default Behavior Trees**: https://docs.nav2.org/behavior_trees/trees/nav_to_pose_and_pause_near_goal_obstacle.html
- **Behavior Tree Concepts**: https://docs.nav2.org/behavior_trees/index.html

─────────────────────────────────────────────────────────────────────────────

### Step 2: Add Spin Recovery and Test

Create a custom behavior tree that includes spin recovery:

```xml
<!-- Save as: src/scout_mini_navigation/behavior_trees/nav_with_spin_recovery.xml -->
<root main_tree_to_execute="MainTree">
  <BehaviorTree ID="MainTree">
    <RecoveryNode number_of_retries="6" name="NavigateRecovery">
      <PipelineSequence name="NavigateWithReplanning">
        <RateController hz="1">
          <RecoveryNode number_of_retries="1" name="ComputePathToPose">
            <ComputePathToPose goal="{goal}" path="{path}" planner_id="GridBased"/>
            <ClearEntireCostmap name="ClearGlobalCostmap-Context" service_name="global_costmap/clear_entirely_global_costmap"/>
          </RecoveryNode>
        </RateController>
        <RecoveryNode number_of_retries="1" name="FollowPath">
          <FollowPath path="{path}" controller_id="FollowPath"/>
          <ClearEntireCostmap name="ClearLocalCostmap-Context" service_name="local_costmap/clear_entirely_local_costmap"/>
        </RecoveryNode>
      </PipelineSequence>
      <ReactiveFallback name="RecoveryFallback">
        <GoalUpdated/>
        <RoundRobin name="RecoveryActions">
          <Sequence name="ClearingActions">
            <ClearEntireCostmap name="ClearLocalCostmap-Subtree" service_name="local_costmap/clear_entirely_local_costmap"/>
            <ClearEntireCostmap name="ClearGlobalCostmap-Subtree" service_name="global_costmap/clear_entirely_global_costmap"/>
          </Sequence>
          <Spin spin_dist="1.57" time_allowance="10"/>
        </RoundRobin>
      </ReactiveFallback>
    </RecoveryNode>
  </BehaviorTree>
</root>
```

**Update nav2_params.yaml to use custom tree:**

```yaml
bt_navigator:
  ros__parameters:
    default_nav_to_pose_bt_xml: "src/scout_mini_navigation/behavior_trees/nav_with_spin_recovery.xml"
```

**Test Spin Recovery:**

```bash
# Launch with custom behavior tree
ros2 launch scout_mini_navigation nav2.launch.py

# Create a situation where robot needs to spin (confuse its orientation)
# Send navigation goal and manually rotate robot to test spin recovery
```

**Reference Links for Custom Behavior Trees:**

- **Behavior Tree XML Format**: https://docs.nav2.org/configuration/packages/configuring-bt-xml.html
- **Custom Recovery Sequences**: https://docs.nav2.org/behavior_trees/trees/follow_point.html

─────────────────────────────────────────────────────────────────────────────

### Step 3: Add Backup Recovery and Test

Enhance the behavior tree with backup recovery:

```xml
<!-- Update the RoundRobin section in your behavior tree -->
<RoundRobin name="RecoveryActions">
  <Sequence name="ClearingActions">
    <ClearEntireCostmap name="ClearLocalCostmap-Subtree" service_name="local_costmap/clear_entirely_local_costmap"/>
    <ClearEntireCostmap name="ClearGlobalCostmap-Subtree" service_name="global_costmap/clear_entirely_global_costmap"/>
  </Sequence>
  <Spin spin_dist="1.57" time_allowance="10"/>
  <BackUp backup_dist="0.15" backup_speed="0.025" time_allowance="10"/>
</RoundRobin>
```

**Test Backup Recovery:**

```bash
# Create a stuck situation by blocking robot's forward path
# Place obstacle directly in front of robot
# Send navigation goal and verify backup recovery activates
```

─────────────────────────────────────────────────────────────────────────────

### Step 4: Add Clear Costmaps Recovery and Test

Add costmap clearing as a recovery strategy:

```xml
<!-- Enhanced recovery sequence -->
<RoundRobin name="RecoveryActions">
  <Sequence name="ClearingActions">
    <ClearEntireCostmap name="ClearLocalCostmap-Subtree" service_name="local_costmap/clear_entirely_local_costmap"/>
    <ClearEntireCostmap name="ClearGlobalCostmap-Subtree" service_name="global_costmap/clear_entirely_global_costmap"/>
  </Sequence>
  <Spin spin_dist="1.57" time_allowance="10"/>
  <BackUp backup_dist="0.15" backup_speed="0.025" time_allowance="10"/>
  <Wait wait_duration="5"/>
  <Sequence name="AggressiveClearing">
    <ClearEntireCostmap name="ClearLocalCostmap-Aggressive" service_name="local_costmap/clear_entirely_local_costmap"/>
    <Wait wait_duration="2"/>
    <ClearEntireCostmap name="ClearGlobalCostmap-Aggressive" service_name="global_costmap/clear_entirely_global_costmap"/>
  </Sequence>
</RoundRobin>
```

**Test Each Addition:**
After adding each recovery behavior, test it individually:

```bash
# Test costmap clearing recovery
# Create false obstacles (move objects in/out of view quickly)
# Verify costmap clearing removes ghost obstacles

# Test wait recovery
# Block path temporarily with moving obstacle (person walking by)
# Verify wait allows obstacle to clear naturally
```

─────────────────────────────────────────────────────────────────────────────

### Step 5: Final Integration Testing

Test the complete behavior tree with all recovery strategies:

```bash
# Create complex navigation scenarios:
# 1. Send goal through narrow passage (tests normal navigation)
# 2. Block path temporarily (tests replanning)
# 3. Rotate robot manually (tests spin recovery)
# 4. Push robot against wall (tests backup recovery)
# 5. Create ghost obstacles (tests costmap clearing)

# Monitor behavior tree execution
ros2 topic echo /behavior_tree# Team 3: Controllers and Behavior Trees

## Team Mission Statement

**"Team 3 handles 'How do I follow the path?' and 'What do I do when stuck?' through precise trajectory tracking and intelligent recovery behaviors."**

You are the execution team. You take the brilliant paths from Team 2 and make them reality through smooth, safe robot motion. When things go wrong (and they will), your recovery behaviors get the robot unstuck and back on track.

**Why Your Work Matters:** Perfect planning is useless if the robot can't follow the path smoothly or recover from unexpected situations. You turn navigation plans into real robot movement and handle all the edge cases that make autonomous navigation reliable in the real world.

## Your Role in the Navigation Pipeline

```

Team 1 (Where am I?) → Team 2 (How do I get there?) → Team 3 (YOU - Execute the plan!)

- /amcl_pose → - Global/local costmaps → - Path following (/cmd_vel)
- Stable localization → - /plan (path to goal) → - Obstacle avoidance
- Transform chain → - Obstacle detection → - Recovery behaviors
  → - Goal achievement

````

## Dependencies and Parallel Work Strategy

### What You Need from Other Teams (Dependencies)

**From Team 1 (Critical Dependencies):**
- **Stable `/amcl_pose`** - Controller needs to know where robot is
- **Continuous transforms** - Essential for coordinate conversions
- **Lifecycle coordination** - Your servers need proper startup sequencing

**From Team 2 (Critical Dependencies):**
- **Valid `/plan` topic** - You can't follow a path that doesn't exist
- **Accurate costmaps** - Needed for local obstacle avoidance
- **Proper robot footprint** - Controller must know robot dimensions

### What You Need from Other Teams (Dependencies)

**From Team 1 (Critical Dependencies):**
- **Stable `/amcl_pose`** - Controller needs to know where robot is for coordinate conversions
- **Continuous transforms** - Essential for converting between map, odom, and base_link frames
- **Lifecycle coordination** - Your servers need proper startup sequencing in the right order

**From Team 2 (Critical Dependencies):**
- **Valid `/plan` topic** - You can't follow a path that doesn't exist or is invalid
- **Accurate costmaps** - Needed for local obstacle avoidance during path execution
- **Proper robot footprint** - Controller must know robot dimensions for safe navigation

### What You Can Do While Other Teams Work (Parallel Work)

**What You Can Do While Waiting (Independent Tasks):**

```bash
# 1. Research and draft controller configurations
# Study Nav2 controller documentation and examples

# 2. Test basic controllers with fake data (before Team 2 is ready)
ros2 run nav2_controller controller_server \
  --ros-args --params-file your_draft_config.yaml

# Publish fake path for controller testing
ros2 topic pub /plan nav_msgs/msg/Path \
  '{header: {frame_id: "map"}, poses: [
    {header: {frame_id: "map"}, pose: {position: {x: 0.0, y: 0.0, z: 0.0}, orientation: {w: 1.0}}},
    {header: {frame_id: "map"}, pose: {position: {x: 1.0, y: 0.0, z: 0.0}, orientation: {w: 1.0}}},
    {header: {frame_id: "map"}, pose: {position: {x: 2.0, y: 1.0, z: 0.0}, orientation: {w: 1.0}}}
  ]}'

# 3. Tune velocity/acceleration parameters offline
# Test different controller parameters using fake paths and odometry

# 4. Draft Behavior Tree XML files
# Study Nav2 behavior tree concepts and prepare custom XML modifications
````

**Research and Preparation Tasks:**

- Compare Regulated Pure Pursuit vs DWB controllers for Scout Mini
- Study Nav2 behavior tree documentation and default navigation trees
- Research recovery behavior strategies (backup, spin, wait, clear costmaps)
- Draft controller parameter files using Scout Mini's physical constraints

## Scout Mini Control Constraints (Critical for Your Work)

```yaml
# Physical velocity limits (ENFORCE THESE in your controller)
max_vel_x: 0.5 # 0.5 m/s max forward speed (safe for indoors)
min_vel_x: -0.2 # Limited reverse capability
max_vel_y: 0.0 # No lateral movement (skid-steer)
min_vel_y: 0.0
max_vel_theta: 1.0 # 1.0 rad/s max rotation speed

# Acceleration limits
max_accel_x: 2.5 # Forward/reverse acceleration
max_accel_theta: 3.2 # Rotational acceleration

# Physical constraints
min_turning_radius: 0.40 # Minimum turn radius due to skid-steer
robot_radius: 0.40 # For obstacle avoidance calculations

# Goal tolerances
xy_goal_tolerance: 0.25 # 25cm position tolerance
yaw_goal_tolerance: 0.25 # ~14 degree orientation tolerance
```

**Pro Tip:** Scout Mini's skid-steer drive means it can't move sideways and has a minimum turning radius. Your controller must respect these kinematic constraints!

## Step-by-Step Setup Instructions

### Step 1: Choose and Configure Path Following Controller

**Option A: Regulated Pure Pursuit (Recommended for Beginners)**

Create `apollo_ws/src/scout_mini_navigation/config/controller_params.yaml`:

```yaml
controller_server:
  ros__parameters:
    use_sim_time: false
    controller_frequency: 20.0 # Control loop at 20 Hz
    min_x_velocity_threshold: 0.001 # Minimum velocity to be considered moving
    min_y_velocity_threshold: 0.5 # Not used for Scout Mini (no lateral)
    min_theta_velocity_threshold: 0.001 # Minimum rotation to be considered turning
    failure_tolerance: 0.3 # Time to wait before declaring failure

    # Progress and goal checking
    progress_checker_plugins: ["progress_checker"]
    goal_checker_plugins: ["goal_checker"]
    controller_plugins: ["FollowPath"]

    # Progress checker - detects if robot is making progress toward goal
    progress_checker:
      plugin: "nav2_controller::SimpleProgressChecker"
      required_movement_radius: 0.5 # Must move 0.5m in time window
      movement_time_allowance: 10.0 # 10 second window for movement

    # Goal checker - determines when goal is reached
    goal_checker:
      plugin: "nav2_controller::SimpleGoalChecker"
      xy_goal_tolerance: 0.25 # 25cm position tolerance
      yaw_goal_tolerance: 0.25 # ~14 degree orientation tolerance
      stateful: true # Remember goal achievement

    # Regulated Pure Pursuit Controller
    FollowPath:
      plugin: "nav2_regulated_pure_pursuit_controller::RegulatedPurePursuitController"

      # Scout Mini velocity limits
      min_vel_x: 0.0
      min_vel_y: 0.0
      max_vel_x: 0.5
      max_vel_y: 0.0 # No lateral movement for skid-steer
      max_vel_theta: 1.0
      min_speed_xy: 0.0
      max_speed_xy: 0.5

      # Acceleration limits
      acc_lim_x: 2.5
      acc_lim_y: 0.0 # No lateral acceleration
      acc_lim_theta: 3.2
      decel_lim_x: -2.5
      decel_lim_y: 0.0
      decel_lim_theta: -3.2

      # TEAM 3 TODO: Tune these DWB parameters through testing
      # vx_samples: [number of forward velocity samples - try 20]
      # vy_samples: [lateral velocity samples - try 5 for skid-steer]
      # vtheta_samples: [rotation velocity samples - try 20]
      # sim_time: [trajectory simulation time - try 1.7]

      # Trajectory scoring critics (these determine path selection)
      # critics: ["RotateToGoal", "Oscillation", "BaseObstacle", "GoalAlign", "PathAlign", "PathDist", "GoalDist"]
      # BaseObstacle.scale: [obstacle avoidance weight - try 0.02]
      # PathAlign.scale: [path following weight - try 32.0]
      # GoalAlign.scale: [goal alignment weight - try 24.0]
      # PathDist.scale: [distance to path weight - try 32.0]
      # GoalDist.scale: [distance to goal weight - try 24.0]
```

### Step 2: Configure Behavior Tree Navigator

Create `apollo_ws/src/scout_mini_navigation/config/bt_navigator_params.yaml`:

```yaml
bt_navigator:
  ros__parameters:
    use_sim_time: false
    global_frame: map # Planning frame (from Team 1)
    robot_base_frame: base_link # Robot frame
    odom_topic: /odom # Odometry topic (from scout_mini_base)
    bt_loop_duration: 10 # Behavior tree execution frequency (10 Hz)
    default_server_timeout: 20 # Default action timeout (seconds)
    wait_for_service_timeout: 1000 # Service connection timeout (ms)
    action_server_result_timeout: 900.0 # Action result timeout

    # Available navigator types
    navigators: ["navigate_to_pose", "navigate_through_poses"]

    # Use Nav2's default behavior trees (or specify custom ones)
    default_nav_to_pose_bt_xml: "" # Empty = use default
    default_nav_through_poses_bt_xml: "" # Empty = use default

    # Behavior tree plugin libraries (required for BT nodes)
    plugin_lib_names:
      - nav2_compute_path_to_pose_action_bt_node
      - nav2_compute_path_through_poses_action_bt_node
      - nav2_smooth_path_action_bt_node
      - nav2_follow_path_action_bt_node
      - nav2_spin_action_bt_node
      - nav2_wait_action_bt_node
      - nav2_back_up_action_bt_node
      - nav2_clear_costmap_service_bt_node
      - nav2_is_stuck_condition_bt_node
      - nav2_goal_reached_condition_bt_node
      - nav2_goal_updated_condition_bt_node
      - nav2_is_path_valid_condition_bt_node
      - nav2_initial_pose_received_condition_bt_node
      - nav2_reinitialize_global_localization_service_bt_node
      - nav2_rate_controller_bt_node
      - nav2_distance_controller_bt_node
      - nav2_recovery_node_bt_node
      - nav2_pipeline_sequence_bt_node
      - nav2_round_robin_node_bt_node
      - nav2_transform_available_condition_bt_node
      - nav2_time_expired_condition_bt_node
      - nav2_distance_traveled_condition_bt_node
      - nav2_single_trigger_bt_node
      - nav2_navigate_to_pose_action_bt_node
      - nav2_navigate_through_poses_action_bt_node
```

**Understanding Behavior Trees:** The default Nav2 behavior tree handles the complete navigation logic:

1. **Plan Path**: Request path from Team 2's planner
2. **Follow Path**: Execute path using your controller
3. **Recovery**: If stuck, try backup/spin/wait behaviors
4. **Replanning**: If path becomes invalid, replan around new obstacles

### Step 3: Configure Recovery Behaviors

Create `apollo_ws/src/scout_mini_navigation/config/recovery_params.yaml`:

```yaml
behavior_server:
  ros__parameters:
    use_sim_time: false
    behavior_plugins: ["spin", "backup", "drive_on_heading", "wait"]

    # Spin recovery - rotate in place to clear confusion
    spin:
      plugin: "nav2_behaviors::Spin"
      simulate_ahead_time: 2.0 # Look ahead time for safety
      max_rotational_vel: 1.0 # Maximum spin speed
      min_rotational_vel: 0.4 # Minimum spin speed
      rotational_acc_lim: 3.2 # Rotation acceleration limit

    # Backup recovery - back up to get unstuck
    backup:
      plugin: "nav2_behaviors::BackUp"
      simulate_ahead_time: 2.0 # Safety lookahead
      # TEAM 3 TODO: Tune backup behavior parameters
      # backup_speed: [how fast to back up - try 0.025 m/s]
      # time_allowance: [how long to try backing up - try 10 seconds]

    # Drive on heading - move in specific direction
    drive_on_heading:
      plugin: "nav2_behaviors::DriveOnHeading"
      simulate_ahead_time: 2.0
      # TEAM 3 TODO: Configure drive on heading parameters
      # speed: [forward driving speed - try 0.025 m/s]
      # time_allowance: [how long to drive - try 10 seconds]

    # Wait recovery - pause and let dynamic obstacles clear
    wait:
      plugin: "nav2_behaviors::Wait"
      # No additional parameters needed - just waits for specified duration
```

**Recovery Behavior Strategy:**

- **Spin**: Used when robot is confused about its orientation
- **Backup**: Used when robot is stuck against an obstacle
- **Drive on Heading**: Used to escape from confined spaces
- **Wait**: Used when temporary obstacles (people) are blocking the path

### Step 4: Add Team 3 Configuration to nav2_params.yaml

Add your section to `apollo_ws/src/scout_mini_navigation/config/nav2_params.yaml`:

```yaml
#==============================================================================
# TEAM 3: Controllers and Behavior Trees
#==============================================================================

controller_server:
  ros__parameters:
    use_sim_time: false
    controller_frequency: 20.0
    min_x_velocity_threshold: 0.001
    min_theta_velocity_threshold: 0.001
    failure_tolerance: 0.3

    progress_checker_plugins: ["progress_checker"]
    goal_checker_plugins: ["goal_checker"]
    controller_plugins: ["FollowPath"]

    progress_checker:
      plugin: "nav2_controller::SimpleProgressChecker"
      required_movement_radius: 0.5
      movement_time_allowance: 10.0

    goal_checker:
      plugin: "nav2_controller::SimpleGoalChecker"
      xy_goal_tolerance: 0.25
      yaw_goal_tolerance: 0.25
      stateful: true

    FollowPath:
      plugin: "nav2_regulated_pure_pursuit_controller::RegulatedPurePursuitController"
      # TEAM 3 TODO: Complete Regulated Pure Pursuit configuration
      # Add velocity limits, lookahead parameters, regulation features

bt_navigator:
  ros__parameters:
    use_sim_time: false
    global_frame: map
    robot_base_frame: base_link
    odom_topic: /odom
    bt_loop_duration: 10
    default_server_timeout: 20
    navigators: ["navigate_to_pose", "navigate_through_poses"]
    default_nav_to_pose_bt_xml: ""
    # TEAM 3 TODO: Add complete plugin library list

behavior_server:
  ros__parameters:
    use_sim_time: false
    behavior_plugins: ["spin", "backup", "drive_on_heading", "wait"]
    # TEAM 3 TODO: Configure all recovery behaviors with appropriate parameters

waypoint_follower:
  ros__parameters:
    use_sim_time: false
    loop_rate: 20
    stop_on_failure: false
    waypoint_task_executor_plugin: "wait_at_waypoint"

    wait_at_waypoint:
      plugin: "nav2_waypoint_follower::WaitAtWaypoint"
      enabled: true
      waypoint_pause_duration: 200
```

## Testing Procedures

### Test 1: Controller Testing with Fake Paths (Parallel Work)

**Before Teams 1&2 are Ready (Independent Testing):**

```bash
# Launch just the controller server
ros2 run nav2_controller controller_server \
  --ros-args --params-file config/nav2_params.yaml

# Publish fake odometry (if scout_mini_base isn't running)
ros2 topic pub /odom nav_msgs/msg/Odometry \
  '{header: {frame_id: "odom"}, child_frame_id: "base_link",
    pose: {pose: {position: {x: 0.0, y: 0.0, z: 0.0},
                  orientation: {x: 0.0, y: 0.0, z: 0.0, w: 1.0}}},
    twist: {twist: {linear: {x: 0.0, y: 0.0, z: 0.0},
                    angular: {x: 0.0, y: 0.0, z: 0.0}}}}'

# Publish a simple test path
ros2 topic pub /plan nav_msgs/msg/Path \
  '{header: {frame_id: "odom", stamp: {sec: 0, nanosec: 0}}, poses: [
    {header: {frame_id: "odom"}, pose: {position: {x: 0.0, y: 0.0, z: 0.0}, orientation: {w: 1.0}}},
    {header: {frame_id: "odom"}, pose: {position: {x: 1.0, y: 0.0, z: 0.0}, orientation: {w: 1.0}}},
    {header: {frame_id: "odom"}, pose: {position: {x: 2.0, y: 0.0, z: 0.0}, orientation: {w: 1.0}}}
  ]}'

# Monitor velocity commands
ros2 topic echo /cmd_vel
```

**Note for Parallel Work:** You can test with fake `/plan` inputs before Team 2 finishes. Once Team 2 is active, switch to real `/plan` data from their planner.

**What You Should See:**

- Controller publishes `/cmd_vel` messages
- Linear velocity increases toward `desired_linear_vel`
- Angular velocity adjusts to follow the path curvature

### Test 2: Recovery Behavior Testing

```bash
# Launch behavior server
ros2 run nav2_behaviors behavior_server \
  --ros-args --params-file config/nav2_params.yaml

# Test individual recovery behaviors
ros2 action send_goal /spin nav2_msgs/action/Spin \
  "{target_yaw: 1.57}"  # Spin 90 degrees

ros2 action send_goal /backup nav2_msgs/action/BackUp \
  "{target: {x: -0.15, y: 0.0, z: 0.0}}"  # Back up 15cm

ros2 action send_goal /wait nav2_msgs/action/Wait \
  "{time: {sec: 5, nanosec: 0}}"  # Wait 5 seconds

# Monitor robot movement during each behavior
ros2 topic echo /cmd_vel
```

### Test 3: Integrated Navigation Testing (Requires Teams 1&2)

```bash
# Launch complete navigation system
ros2 launch scout_mini_navigation nav2.launch.py

# Open RViz for visualization and control
ros2 run rviz2 rviz2 -d src/scout_mini_navigation/rviz/navigation.rviz

# Set initial pose using 2D Pose Estimate tool in RViz
# Send navigation goal using 2D Nav Goal tool in RViz

# Monitor navigation progress
ros2 topic echo /navigate_to_pose/_action/feedback
ros2 topic echo /cmd_vel
```

**Success Indicators:**

- Robot starts following the global path from Team 2
- Local obstacle avoidance works when obstacles are detected
- Recovery behaviors activate when robot gets stuck
- Robot reaches navigation goal within tolerance

### Test 4: Edge Case and Recovery Testing

```bash
# Test stuck situation recovery
# 1. Send navigation goal
# 2. Manually block robot path with obstacle
# 3. Observe recovery behavior activation
# 4. Remove obstacle and verify normal navigation resumes

# Test goal tolerance
# Send goal very close to current position and verify achievement

# Test unreachable goal handling
# Send goal in obstacle space and verify appropriate failure response
```

## Step-by-Step Behavior Tree Configuration

**Understanding Behavior Trees:** Behavior trees orchestrate the complete navigation logic, deciding when to plan, when to follow paths, and when to use recovery behaviors.

### Step 1: Start with Default Nav2 Behavior Tree

Begin with Nav2's proven default behavior tree, then customize it step by step:

```yaml
bt_navigator:
  ros__parameters:
    # Use Nav2's default behavior tree initially
    default_nav_to_pose_bt_xml: "" # Empty = use Nav2 default
    default_nav_through_poses_bt_xml: "" # Empty = use Nav2 default
```

**Default Nav2 Behavior Tree Flow:**

1. **Check Prerequisites**: Is localization working? Are costmaps available?
2. **Plan Path**: Request global path from Team 2's planner
3. **Follow Path**: Use your controller to execute the path
4. **Monitor Progress**: Check if robot is making progress toward goal
5. **Handle Failures**: If stuck or path becomes invalid, try recovery behaviors
6. **Retry or Fail**: After recovery, retry navigation or declare failure

**Test the Default Setup:**

```bash
# Launch behavior tree navigator with default XML
ros2 run nav2_bt_navigator bt_navigator \
  --ros-args --params-file config/nav2_params.yaml

# Send a simple navigation goal and observe behavior
ros2 action send_goal /navigate_to_pose nav2_msgs/action/NavigateToPose \
  "{pose: {header: {frame_id: map}, pose: {position: {x: 1.0, y: 0.0, z: 0.0}, orientation: {w: 1.0}}}}"
```

### Step 2: Add Spin Recovery and Test

Create a custom behavior tree that includes spin recovery:

```xml
<!-- Save as: src/scout_mini_navigation/behavior_trees/nav_with_spin_recovery.xml -->
<root main_tree_to_execute="MainTree">
  <BehaviorTree ID="MainTree">
    <RecoveryNode number_of_retries="6" name="NavigateRecovery">
      <PipelineSequence name="NavigateWithReplanning">
        <RateController hz="1">
          <RecoveryNode number_of_retries="1" name="ComputePathToPose">
            <ComputePathToPose goal="{goal}" path="{path}" planner_id="GridBased"/>
            <ClearEntireCostmap name="ClearGlobalCostmap-Context" service_name="global_costmap/clear_entirely_global_costmap"/>
          </RecoveryNode>
        </RateController>
        <RecoveryNode number_of_retries="1" name="FollowPath">
          <FollowPath path="{path}" controller_id="FollowPath"/>
          <ClearEntireCostmap name="ClearLocalCostmap-Context" service_name="local_costmap/clear_entirely_local_costmap"/>
        </RecoveryNode>
      </PipelineSequence>
      <ReactiveFallback name="RecoveryFallback">
        <GoalUpdated/>
        <RoundRobin name="RecoveryActions">
          <Sequence name="ClearingActions">
            <ClearEntireCostmap name="ClearLocalCostmap-Subtree" service_name="local_costmap/clear_entirely_local_costmap"/>
            <ClearEntireCostmap name="ClearGlobalCostmap-Subtree" service_name="global_costmap/clear_entirely_global_costmap"/>
          </Sequence>
          <Spin spin_dist="1.57" time_allowance="10"/>
        </RoundRobin>
      </ReactiveFallback>
    </RecoveryNode>
  </BehaviorTree>
</root>
```

**Update nav2_params.yaml to use custom tree:**

```yaml
bt_navigator:
  ros__parameters:
    default_nav_to_pose_bt_xml: "src/scout_mini_navigation/behavior_trees/nav_with_spin_recovery.xml"
```

**Test Spin Recovery:**

```bash
# Launch with custom behavior tree
ros2 launch scout_mini_navigation nav2.launch.py

# Create a situation where robot needs to spin (confuse its orientation)
# Send navigation goal and manually rotate robot to test spin recovery
```

### Step 3: Add Backup Recovery and Test

Enhance the behavior tree with backup recovery:

```xml
<!-- Update the RoundRobin section in your behavior tree -->
<RoundRobin name="RecoveryActions">
  <Sequence name="ClearingActions">
    <ClearEntireCostmap name="ClearLocalCostmap-Subtree" service_name="local_costmap/clear_entirely_local_costmap"/>
    <ClearEntireCostmap name="ClearGlobalCostmap-Subtree" service_name="global_costmap/clear_entirely_global_costmap"/>
  </Sequence>
  <Spin spin_dist="1.57" time_allowance="10"/>
  <BackUp backup_dist="0.15" backup_speed="0.025" time_allowance="10"/>
</RoundRobin>
```

**Test Backup Recovery:**

```bash
# Create a stuck situation by blocking robot's forward path
# Place obstacle directly in front of robot
# Send navigation goal and verify backup recovery activates
```

### Step 4: Add Clear Costmaps Recovery and Test

Add costmap clearing as a recovery strategy:

```xml
<!-- Enhanced recovery sequence -->
<RoundRobin name="RecoveryActions">
  <Sequence name="ClearingActions">
    <ClearEntireCostmap name="ClearLocalCostmap-Subtree" service_name="local_costmap/clear_entirely_local_costmap"/>
    <ClearEntireCostmap name="ClearGlobalCostmap-Subtree" service_name="global_costmap/clear_entirely_global_costmap"/>
  </Sequence>
  <Spin spin_dist="1.57" time_allowance="10"/>
  <BackUp backup_dist="0.15" backup_speed="0.025" time_allowance="10"/>
  <Wait wait_duration="5"/>
  <Sequence name="AggressiveClearing">
    <ClearEntireCostmap name="ClearLocalCostmap-Aggressive" service_name="local_costmap/clear_entirely_local_costmap"/>
    <Wait wait_duration="2"/>
    <ClearEntireCostmap name="ClearGlobalCostmap-Aggressive" service_name="global_costmap/clear_entirely_global_costmap"/>
  </Sequence>
</RoundRobin>
```

**Test Each Addition:**
After adding each recovery behavior, test it individually:

```bash
# Test costmap clearing recovery
# Create false obstacles (move objects in/out of view quickly)
# Verify costmap clearing removes ghost obstacles

# Test wait recovery
# Block path temporarily with moving obstacle (person walking by)
# Verify wait allows obstacle to clear naturally
```

### Step 5: Final Integration Testing

Test the complete behavior tree with all recovery strategies:

```bash
# Create complex navigation scenarios:
# 1. Send goal through narrow passage (tests normal navigation)
# 2. Block path temporarily (tests replanning)
# 3. Rotate robot manually (tests spin recovery)
# 4. Push robot against wall (tests backup recovery)
# 5. Create ghost obstacles (tests costmap clearing)

# Monitor behavior tree execution
ros2 topic echo /behavior_tree_log
```

**Behavior Tree Tuning Parameters:**

```xml
<!-- Adjust these values based on testing results -->
<Spin spin_dist="1.57" time_allowance="10"/>        <!-- 90 degrees, 10 second limit -->
<BackUp backup_dist="0.15" backup_speed="0.025"/>   <!-- 15cm backup at 2.5cm/s -->
<Wait wait_duration="5"/>                           <!-- 5 second wait for dynamic obstacles -->
```

**Advanced Behavior Tree Resources:**

- **Behavior Tree Nodes Reference**: https://docs.nav2.org/behavior_trees/nodes/index.html
- **Custom BT Creation**: https://docs.nav2.org/tutorials/docs/adding_a_nav2_task_server.html
- **BT XML Examples**: https://github.com/ros-planning/navigation2/tree/main/nav2_bt_navigator/behavior_trees

═══════════════════════════════════════════════════════════════════════════════

## TESTING PROCEDURES

### Test 1: Controller Testing with Fake Paths (Parallel Work)

**Before Teams 1&2 are Ready (Independent Testing):**

```bash
# Launch just the controller server
ros2 run nav2_controller controller_server \
  --ros-args --params-file config/nav2_params.yaml

# Publish fake odometry (if scout_mini_base isn't running)
ros2 topic pub /odom nav_msgs/msg/Odometry \
  '{header: {frame_id: "odom"}, child_frame_id: "base_link",
    pose: {pose: {position: {x: 0.0, y: 0.0, z: 0.0},
                  orientation: {x: 0.0, y: 0.0, z: 0.0, w: 1.0}}},
    twist: {twist: {linear: {x: 0.0, y: 0.0, z: 0.0},
                    angular: {x: 0.0, y: 0.0, z: 0.0}}}}'

# Publish a simple test path
ros2 topic pub /plan nav_msgs/msg/Path \
  '{header: {frame_id: "odom", stamp: {sec: 0, nanosec: 0}}, poses: [
    {header: {frame_id: "odom"}, pose: {position: {x: 0.0, y: 0.0, z: 0.0}, orientation: {w: 1.0}}},
    {header: {frame_id: "odom"}, pose: {position: {x: 1.0, y: 0.0, z: 0.0}, orientation: {w: 1.0}}},
    {header: {frame_id: "odom"}, pose: {position: {x: 2.0, y: 0.0, z: 0.0}, orientation: {w: 1.0}}}
  ]}'

# Monitor velocity commands
ros2 topic echo /cmd_vel
```

**Note for Parallel Work:** You can test with fake `/plan` inputs before Team 2 finishes. Once Team 2 is active, switch to real `/plan` data from their planner.

**What You Should See:**

- Controller publishes `/cmd_vel` messages
- Linear velocity increases toward `desired_linear_vel`
- Angular velocity adjusts to follow the path curvature

─────────────────────────────────────────────────────────────────────────────

### Test 2: Recovery Behavior Testing

```bash
# Launch behavior server
ros2 run nav2_behaviors behavior_server \
  --ros-args --params-file config/nav2_params.yaml

# Test individual recovery behaviors
ros2 action send_goal /spin nav2_msgs/action/Spin \
  "{target_yaw: 1.57}"  # Spin 90 degrees

ros2 action send_goal /backup nav2_msgs/action/BackUp \
  "{target: {x: -0.15, y: 0.0, z: 0.0}}"  # Back up 15cm

ros2 action send_goal /wait nav2_msgs/action/Wait \
  "{time: {sec: 5, nanosec: 0}}"  # Wait 5 seconds

# Monitor robot movement during each behavior
ros2 topic echo /cmd_vel
```

─────────────────────────────────────────────────────────────────────────────

### Test 3: Integrated Navigation Testing (Requires Teams 1&2)

```bash
# Launch complete navigation system
ros2 launch scout_mini_navigation nav2.launch.py

# Open RViz for visualization and control
ros2 run rviz2 rviz2 -d src/scout_mini_navigation/rviz/navigation.rviz

# Set initial pose using 2D Pose Estimate tool in RViz
# Send navigation goal using 2D Nav Goal tool in RViz

# Monitor navigation progress
ros2 topic echo /navigate_to_pose/_action/feedback
ros2 topic echo /cmd_vel
```

**Success Indicators:**

- Robot starts following the global path from Team 2
- Local obstacle avoidance works when obstacles are detected
- Recovery behaviors activate when robot gets stuck
- Robot reaches navigation goal within tolerance

─────────────────────────────────────────────────────────────────────────────

### Test 4: Edge Case and Recovery Testing

```bash
# Test stuck situation recovery
# 1. Send navigation goal
# 2. Manually block robot path with obstacle
# 3. Observe recovery behavior activation
# 4. Remove obstacle and verify normal navigation resumes

# Test goal tolerance
# Send goal very close to current position and verify achievement

# Test unreachable goal handling
# Send goal in obstacle space and verify appropriate failure response
```

═══════════════════════════════════════════════════════════════════════════════

## RVIZ NAVIGATION SETUP (DESCRIPTION ONLY)

**Essential Displays for Team 3 Testing:**

1. **Robot Model** - Shows Scout Mini moving in real-time
2. **Global Plan** (`/plan`) - Path from Team 2's planner (blue line)
3. **Local Plan** (`/local_plan`) - Controller's immediate trajectory (green/red)
4. **Velocity Display** - Visualizes `/cmd_vel` commands as arrows
5. **Goal Pose** - Shows active navigation goal
6. **Costmaps** - Global and local costmaps for context

**Interactive Tools:**

- **2D Nav Goal** - Primary tool for sending navigation goals
- **2D Pose Estimate** - Set initial pose (Team 1 responsibility)

**What You Should Observe During Navigation:**

- **Global Plan**: Blue line from robot to goal, updated when replanning occurs
- **Local Plan**: Green trajectory showing immediate robot path, red when blocked
- **Robot Model**: Smooth movement following the local trajectory
- **Velocity Arrows**: Show current `/cmd_vel` commands being sent to motors

**Signs of Good Controller Performance:**

- Smooth, non-oscillating robot movement
- Local plan closely follows global plan when possible
- Appropriate slowing for turns and goal approach
- Quick replanning when obstacles appear

**Signs of Controller Problems:**

- Robot oscillates or wobbles excessively
- Robot moves too fast through turns (violates kinematic constraints)
- Robot gets stuck in local minima (trapped by obstacles)
- Poor goal approaching (overshoots or stops too far away)

═══════════════════════════════════════════════════════════════════════════════

## TROUBLESHOOTING GUIDE

### Problem: "Controller publishes zero velocities"

**Symptoms:**

- Robot receives navigation goals but doesn't move
- `/cmd_vel` shows all zero values
- No error messages in controller logs

**Diagnosis Steps:**

```bash
# Check if controller is receiving paths
ros2 topic echo /plan --once

# Verify goal is set and reachable
ros2 topic echo /goal_pose --once

# Check controller server status
ros2 node info /controller_server

# Verify transform availability
ros2 run tf2_ros tf2_echo map base_link
```

**Common Solutions:**

```yaml
# Check goal tolerance isn't already satisfied
xy_goal_tolerance: 0.25 # Maybe goal is already within tolerance
yaw_goal_tolerance: 0.25

# Verify velocity limits aren't too restrictive
desired_linear_vel: 0.5 # Should be > 0
max_linear_accel: 2.5 # Should be > 0

# Ensure path is valid and non-empty
# Check that Team 2's planner is generating valid paths
```

─────────────────────────────────────────────────────────────────────────────

### Problem: "Robot oscillates or moves erratically"

**Symptoms:**

- Robot wobbles left and right while following path
- Jerky acceleration/deceleration
- Robot overshoots goal or circles around it

**For Regulated Pure Pursuit:**

```yaml
# Increase lookahead distance for smoother motion
lookahead_dist: 0.8 # Was 0.6, try larger
min_lookahead_dist: 0.4 # Was 0.3

# Enable velocity regulation for turns
use_regulated_linear_velocity_scaling: true
regulated_linear_scaling_min_radius: 1.2 # Slow down in turns
regulated_linear_scaling_min_speed: 0.1 # Don't stop completely

# Reduce desired speed for stability
desired_linear_vel: 0.3 # Was 0.5, slower is more stable
```

**For DWB Controller:**

```yaml
# Reduce trajectory sampling for smoother motion
vtheta_samples: 10 # Was 20, fewer samples
sim_time: 2.5 # Was 1.7, longer prediction

# Increase path following weight
PathAlign.scale: 48.0 # Was 32.0, follow path more closely
PathDist.scale: 48.0 # Was 32.0
```

─────────────────────────────────────────────────────────────────────────────

### Problem: "Robot gets stuck and recovery behaviors don't work"

**Symptoms:**

- Robot stops moving when encountering obstacles
- Recovery behaviors activate but don't help
- Navigation fails after multiple recovery attempts

**Diagnosis:**

```bash
# Check if costmaps show the obstacle correctly
ros2 topic echo /local_costmap/costmap

# Monitor recovery behavior execution
ros2 action list | grep -E "(spin|backup|wait)"

# Check recovery behavior parameters
ros2 param get /behavior_server spin.max_rotational_vel
```

**Recovery Tuning:**

```yaml
# Make backup more aggressive
backup:
  backup_speed: 0.05 # Was 0.025, back up faster
  time_allowance: 15.0 # Was 10.0, try longer

# Make spin more effective
spin:
  max_rotational_vel: 1.5 # Was 1.0, spin faster
  # Try spinning longer or in smaller increments

# Add wait time for dynamic obstacles
wait:
  # Increase wait duration if obstacles are temporary (people, etc.)
```

─────────────────────────────────────────────────────────────────────────────

### Problem: "Robot doesn't reach goal accurately"

**Symptoms:**

- Robot stops short of goal or overshoots
- Goal tolerance seems wrong
- Robot doesn't align with goal orientation

**Goal Tolerance Tuning:**

```yaml
goal_checker:
  xy_goal_tolerance: 0.15 # Tighter position tolerance
  yaw_goal_tolerance: 0.1 # Tighter orientation tolerance

# For Pure Pursuit - enable final orientation alignment
FollowPath:
  use_rotate_to_heading: true
  rotate_to_heading_angular_vel: 0.5 # Slower final rotation
  max_allowed_time_to_collision: 2.0 # More safety margin
```

**Approach Behavior Tuning:**

```yaml
# Slow down when approaching goal
min_approach_linear_velocity: 0.02 # Very slow final approach
approach_velocity_scaling_dist: 1.0 # Start slowing 1m from goal
use_approach_vel_scaling: true
```

═══════════════════════════════════════════════════════════════════════════════

## PARAMETER TUNING GUIDELINES

### Regulated Pure Pursuit Tuning Strategy

**Step 1: Basic Motion (Start Here)**

```yaml
# Conservative starting values
desired_linear_vel: 0.3 # Slow and steady
lookahead_dist: 0.8 # Smooth following
max_linear_accel: 1.5 # Gentle acceleration
max_angular_vel: 0.5 # Slow turns
```

**Step 2: Add Regulation Features**

```yaml
# Enable safety features once basic motion works
use_velocity_scaled_lookahead_dist: true # Adapt lookahead to speed
use_regulated_linear_velocity_scaling: true # Slow down for tight turns
use_collision_detection: true # Enable obstacle avoidance
```

**Step 3: Performance Optimization**

```yaml
# Increase performance once stable
desired_linear_vel: 0.5 # Back to full speed
max_angular_vel: 1.0 # Full turning speed
lookahead_dist: 0.6 # Responsive following
```

─────────────────────────────────────────────────────────────────────────────

### Recovery Behavior Tuning

**Backup Behavior:**

```yaml
# Gentle backup for delicate situations
backup_speed: 0.02          # 2 cm/s - very slow
time_allowance: 8.0         # Don't back up too long

# Aggressive backup for stuck situations
backup_speed: 0.1           # 10 cm/s - faster escape
time_allowance: 15.0        # Keep trying longer
```

**Spin Behavior:**

```yaml
# Gentle spin for orientation correction
max_rotational_vel: 0.5     # Slow spin
min_rotational_vel: 0.2     # Don't stop spinning

# Aggressive spin for clearing confusion
max_rotational_vel: 1.5     # Fast spin to clear obstacles
min_rotational_vel: 0.8     # Maintain momentum
```

═══════════════════════════════════════════════════════════════════════════════

## TEAM 3 HANDOFF AND INTEGRATION CHECKLIST

### Configuration Files (Must Complete)

- [ ] `controller_params.yaml` with complete Regulated Pure Pursuit OR DWB configuration
- [ ] `bt_navigator_params.yaml` with behavior tree and plugin configuration
- [ ] `recovery_params.yaml` with all recovery behavior parameters
- [ ] Updated `nav2_params.yaml` with complete Team 3 section
- [ ] Verified compatibility with Teams 1&2 parameter choices

─────────────────────────────────────────────────────────────────────────────

### Integration Verification (Must Pass These Tests)

- [ ] **Path Following**: Robot smoothly follows paths from Team 2's planner
- [ ] **Goal Achievement**: Robot reaches navigation goals within specified tolerance
- [ ] **Obstacle Avoidance**: Robot avoids obstacles detected in Team 2's costmaps
- [ ] **Recovery Behaviors**: Robot successfully recovers from stuck situations
- [ ] **System Integration**: Navigation works end-to-end with all teams' components

─────────────────────────────────────────────────────────────────────────────

### Performance Validation (Document Results)

```bash
# Test 1: Path following accuracy
# Send navigation goal, measure deviation from planned path
# Result: Average deviation should be < 0.1m from global plan

# Test 2: Goal achievement rate
# Send 10 navigation goals to different locations
# Result: Should achieve 9/10 goals within tolerance

# Test 3: Recovery success rate
# Create 5 different stuck situations, test recovery
# Result: Should successfully recover from 4/5 situations

# Test 4: Navigation timing
# Measure time to complete typical 4th floor navigation
# Result: Should complete within 60 seconds for 10m goals
```

─────────────────────────────────────────────────────────────────────────────

### What Integration Teams Can Expect

**Guaranteed Capabilities:**

- Smooth path following with Scout Mini kinematic constraints
- Goal achievement within ±0.25m position and ±0.25 radian orientation
- Automated recovery from common stuck situations
- Integration with Nav2 lifecycle and behavior tree system

**Quality Standards:**

- **Path Following Accuracy**: < 0.1m average deviation from planned path
- **Goal Achievement Rate**: > 90% success rate for reachable goals
- **Recovery Success**: > 80% recovery rate from stuck situations
- **Motion Smoothness**: No excessive oscillation or jerky movements

**Safety Guarantees:**

- Velocity limits strictly enforced (max 0.5 m/s linear, 1.0 rad/s angular)
- Kinematic constraints respected (minimum turning radius 0.4m)
- Collision avoidance active during path following
- Emergency stop capability through behavior tree system

─────────────────────────────────────────────────────────────────────────────

### Critical Integration Information

**Topic Names (Output to Robot Base):**

```bash
/cmd_vel                    # Primary robot control commands
/navigate_to_pose/_action/feedback    # Navigation progress updates
/controller_server/transition_event   # Lifecycle state changes
```

**Action Servers (Used by Behavior Tree):**

```bash
/follow_path                # Path following action
/spin                      # Spin recovery action
/backup                    # Backup recovery action
/wait                      # Wait recovery action
/drive_on_heading          # Directional driving action
```

**Parameter Coordination (Must Match Other Teams):**

```yaml
# Frame consistency
global_frame: "map" # Must match Team 1&2
robot_base_frame: "base_link" # Must match URDF
odom_topic: "/odom" # Must match scout_mini_base

# Physical constraints
footprint: "[[-0.356, -0.340], [0.356, -0.340], [0.356, 0.340], [-0.356, 0.340]]" # From Team 2
xy_goal_tolerance: 0.25 # Should match or be tighter than Team 2 planner
transform_tolerance: 1.0 # Should match Team 1 AMCL settings
```

**Performance Requirements for Teams 1&2:**

- **Team 1**: Transform latency must be < 100ms for smooth control
- **Team 2**: Path updates must be available within 2 seconds for replanning
- **Both Teams**: Frame IDs must be consistent across all components

Remember: You're the final link in the navigation chain - everything the user sees depends on your smooth, reliable execution of the navigation plan. Take time to tune your parameters properly for Scout Mini's specific characteristics!

## RViz Navigation Setup (Description Only)

**Essential Displays for Team 3 Testing:**

1. **Robot Model** - Shows Scout Mini moving in real-time
2. **Global Plan** (`/plan`) - Path from Team 2's planner (blue line)
3. **Local Plan** (`/local_plan`) - Controller's immediate trajectory (green/red)
4. **Velocity Display** - Visualizes `/cmd_vel` commands as arrows
5. **Goal Pose** - Shows active navigation goal
6. **Costmaps** - Global and local costmaps for context

**Interactive Tools:**

- **2D Nav Goal** - Primary tool for sending navigation goals
- **2D Pose Estimate** - Set initial pose (Team 1 responsibility)

**What You Should Observe During Navigation:**

- **Global Plan**: Blue line from robot to goal, updated when replanning occurs
- **Local Plan**: Green trajectory showing immediate robot path, red when blocked
- **Robot Model**: Smooth movement following the local trajectory
- **Velocity Arrows**: Show current `/cmd_vel` commands being sent to motors

**Signs of Good Controller Performance:**

- Smooth, non-oscillating robot movement
- Local plan closely follows global plan when possible
- Appropriate slowing for turns and goal approach
- Quick replanning when obstacles appear

**Signs of Controller Problems:**

- Robot oscillates or wobbles excessively
- Robot moves too fast through turns (violates kinematic constraints)
- Robot gets stuck in local minima (trapped by obstacles)
- Poor goal approaching (overshoots or stops too far away)

## Troubleshooting Guide

### Problem: "Controller publishes zero velocities"

**Symptoms:**

- Robot receives navigation goals but doesn't move
- `/cmd_vel` shows all zero values
- No error messages in controller logs

**Diagnosis Steps:**

```bash
# Check if controller is receiving paths
ros2 topic echo /plan --once

# Verify goal is set and reachable
ros2 topic echo /goal_pose --once

# Check controller server status
ros2 node info /controller_server

# Verify transform availability
ros2 run tf2_ros tf2_echo map base_link
```

**Common Solutions:**

```yaml
# Check goal tolerance isn't already satisfied
xy_goal_tolerance: 0.25 # Maybe goal is already within tolerance
yaw_goal_tolerance: 0.25

# Verify velocity limits aren't too restrictive
desired_linear_vel: 0.5 # Should be > 0
max_linear_accel: 2.5 # Should be > 0

# Ensure path is valid and non-empty
# Check that Team 2's planner is generating valid paths
```

### Problem: "Robot oscillates or moves erratically"

**Symptoms:**

- Robot wobbles left and right while following path
- Jerky acceleration/deceleration
- Robot overshoots goal or circles around it

**For Regulated Pure Pursuit:**

```yaml
# Increase lookahead distance for smoother motion
lookahead_dist: 0.8 # Was 0.6, try larger
min_lookahead_dist: 0.4 # Was 0.3

# Enable velocity regulation for turns
use_regulated_linear_velocity_scaling: true
regulated_linear_scaling_min_radius: 1.2 # Slow down in turns
regulated_linear_scaling_min_speed: 0.1 # Don't stop completely

# Reduce desired speed for stability
desired_linear_vel: 0.3 # Was 0.5, slower is more stable
```

**For DWB Controller:**

```yaml
# Reduce trajectory sampling for smoother motion
vtheta_samples: 10 # Was 20, fewer samples
sim_time: 2.5 # Was 1.7, longer prediction

# Increase path following weight
PathAlign.scale: 48.0 # Was 32.0, follow path more closely
PathDist.scale: 48.0 # Was 32.0
```

### Problem: "Robot gets stuck and recovery behaviors don't work"

**Symptoms:**

- Robot stops moving when encountering obstacles
- Recovery behaviors activate but don't help
- Navigation fails after multiple recovery attempts

**Diagnosis:**

```bash
# Check if costmaps show the obstacle correctly
ros2 topic echo /local_costmap/costmap

# Monitor recovery behavior execution
ros2 action list | grep -E "(spin|backup|wait)"

# Check recovery behavior parameters
ros2 param get /behavior_server spin.max_rotational_vel
```

**Recovery Tuning:**

```yaml
# Make backup more aggressive
backup:
  backup_speed: 0.05 # Was 0.025, back up faster
  time_allowance: 15.0 # Was 10.0, try longer

# Make spin more effective
spin:
  max_rotational_vel: 1.5 # Was 1.0, spin faster
  # Try spinning longer or in smaller increments

# Add wait time for dynamic obstacles
wait:
  # Increase wait duration if obstacles are temporary (people, etc.)
```

### Problem: "Robot doesn't reach goal accurately"

**Symptoms:**

- Robot stops short of goal or overshoots
- Goal tolerance seems wrong
- Robot doesn't align with goal orientation

**Goal Tolerance Tuning:**

```yaml
goal_checker:
  xy_goal_tolerance: 0.15 # Tighter position tolerance
  yaw_goal_tolerance: 0.1 # Tighter orientation tolerance

# For Pure Pursuit - enable final orientation alignment
FollowPath:
  use_rotate_to_heading: true
  rotate_to_heading_angular_vel: 0.5 # Slower final rotation
  max_allowed_time_to_collision: 2.0 # More safety margin
```

**Approach Behavior Tuning:**

```yaml
# Slow down when approaching goal
min_approach_linear_velocity: 0.02 # Very slow final approach
approach_velocity_scaling_dist: 1.0 # Start slowing 1m from goal
use_approach_vel_scaling: true
```

## Parameter Tuning Guidelines

### Regulated Pure Pursuit Tuning Strategy

**Step 1: Basic Motion (Start Here)**

```yaml
# Conservative starting values
desired_linear_vel: 0.3 # Slow and steady
lookahead_dist: 0.8 # Smooth following
max_linear_accel: 1.5 # Gentle acceleration
max_angular_vel: 0.5 # Slow turns
```

**Step 2: Add Regulation Features**

```yaml
# Enable safety features once basic motion works
use_velocity_scaled_lookahead_dist: true # Adapt lookahead to speed
use_regulated_linear_velocity_scaling: true # Slow down for tight turns
use_collision_detection: true # Enable obstacle avoidance
```

**Step 3: Performance Optimization**

```yaml
# Increase performance once stable
desired_linear_vel: 0.5 # Back to full speed
max_angular_vel: 1.0 # Full turning speed
lookahead_dist: 0.6 # Responsive following
```

### Recovery Behavior Tuning

**Backup Behavior:**

```yaml
# Gentle backup for delicate situations
backup_speed: 0.02          # 2 cm/s - very slow
time_allowance: 8.0         # Don't back up too long

# Aggressive backup for stuck situations
backup_speed: 0.1           # 10 cm/s - faster escape
time_allowance: 15.0        # Keep trying longer
```

**Spin Behavior:**

```yaml
# Gentle spin for orientation correction
max_rotational_vel: 0.5     # Slow spin
min_rotational_vel: 0.2     # Don't stop spinning

# Aggressive spin for clearing confusion
max_rotational_vel: 1.5     # Fast spin to clear obstacles
min_rotational_vel: 0.8     # Maintain momentum
```

## Team 3 Handoff and Integration Checklist

### Configuration Files (Must Complete)

- [ ] `controller_params.yaml` with complete Regulated Pure Pursuit OR DWB configuration
- [ ] `bt_navigator_params.yaml` with behavior tree and plugin configuration
- [ ] `recovery_params.yaml` with all recovery behavior parameters
- [ ] Updated `nav2_params.yaml` with complete Team 3 section
- [ ] Verified compatibility with Teams 1&2 parameter choices

### Integration Verification (Must Pass These Tests)

- [ ] **Path Following**: Robot smoothly follows paths from Team 2's planner
- [ ] **Goal Achievement**: Robot reaches navigation goals within specified tolerance
- [ ] **Obstacle Avoidance**: Robot avoids obstacles detected in Team 2's costmaps
- [ ] **Recovery Behaviors**: Robot successfully recovers from stuck situations
- [ ] **System Integration**: Navigation works end-to-end with all teams' components

### Performance Validation (Document Results)

```bash
# Test 1: Path following accuracy
# Send navigation goal, measure deviation from planned path
# Result: Average deviation should be < 0.1m from global plan

# Test 2: Goal achievement rate
# Send 10 navigation goals to different locations
# Result: Should achieve 9/10 goals within tolerance

# Test 3: Recovery success rate
# Create 5 different stuck situations, test recovery
# Result: Should successfully recover from 4/5 situations

# Test 4: Navigation timing
# Measure time to complete typical 4th floor navigation
# Result: Should complete within 60 seconds for 10m goals
```

### What Integration Teams Can Expect

**Guaranteed Capabilities:**

- Smooth path following with Scout Mini kinematic constraints
- Goal achievement within ±0.25m position and ±0.25 radian orientation
- Automated recovery from common stuck situations
- Integration with Nav2 lifecycle and behavior tree system

**Quality Standards:**

- **Path Following Accuracy**: < 0.1m average deviation from planned path
- **Goal Achievement Rate**: > 90% success rate for reachable goals
- **Recovery Success**: > 80% recovery rate from stuck situations
- **Motion Smoothness**: No excessive oscillation or jerky movements

**Safety Guarantees:**

- Velocity limits strictly enforced (max 0.5 m/s linear, 1.0 rad/s angular)
- Kinematic constraints respected (minimum turning radius 0.4m)
- Collision avoidance active during path following
- Emergency stop capability through behavior tree system

### Critical Integration Information

**Topic Names (Output to Robot Base):**

```bash
/cmd_vel                    # Primary robot control commands
/navigate_to_pose/_action/feedback    # Navigation progress updates
/controller_server/transition_event   # Lifecycle state changes
```

**Action Servers (Used by Behavior Tree):**

```bash
/follow_path                # Path following action
/spin                      # Spin recovery action
/backup                    # Backup recovery action
/wait                      # Wait recovery action
/drive_on_heading          # Directional driving action
```

**Parameter Coordination (Must Match Other Teams):**

```yaml
# Frame consistency
global_frame: "map" # Must match Team 1&2
robot_base_frame: "base_link" # Must match URDF
odom_topic: "/odom" # Must match scout_mini_base

# Physical constraints
footprint: "[[-0.356, -0.340], [0.356, -0.340], [0.356, 0.340], [-0.356, 0.340]]" # From Team 2
xy_goal_tolerance: 0.25 # Should match or be tighter than Team 2 planner
transform_tolerance: 1.0 # Should match Team 1 AMCL settings
```

**Performance Requirements for Teams 1&2:**

- **Team 1**: Transform latency must be < 100ms for smooth control
- **Team 2**: Path updates must be available within 2 seconds for replanning
- **Both Teams**: Frame IDs must be consistent across all components

Remember: You're the final link in the navigation chain - everything the user sees depends on your smooth, reliable execution of the navigation plan. Take time to tune your parameters properly for Scout Mini's specific characteristics! Mini velocity limits
desired_linear_vel: 0.5 # Preferred cruising speed
max_linear_accel: 2.5 # Forward acceleration limit
max_linear_decel: 2.5 # Braking deceleration limit  
 max_angular_accel: 3.2 # Rotational acceleration limit
max_angular_vel: 1.0 # Maximum rotation speed

      # Pure pursuit algorithm parameters
      lookahead_dist: 0.6                   # Distance to look ahead on path
      min_lookahead_dist: 0.3               # Minimum lookahead distance
      max_lookahead_dist: 0.9               # Maximum lookahead distance
      lookahead_time: 1.5                   # Time-based lookahead (alternative)

      # TEAM 3 TODO: Tune these regulation features through testing
      # use_velocity_scaled_lookahead_dist: [true/false - adjust lookahead based on speed]
      # min_approach_linear_velocity: [slow down when approaching goal - try 0.05]
      # approach_velocity_scaling_dist: [distance to start slowing - try 0.6]
      # use_collision_detection: [enable obstacle avoidance - try true]
      # use_regulated_linear_velocity_scaling: [slow down for tight turns - try true]
      # regulated_linear_scaling_min_radius: [radius to start slowing - try 0.90]
      # regulated_linear_scaling_min_speed: [minimum speed in turns - try 0.25]

      # Rotate to heading behavior (turn toward goal orientation)
      # use_rotate_to_heading: [true to align with goal orientation]
      # rotate_to_heading_angular_vel: [speed for final orientation - try 1.8]
      # max_allowed_time_to_collision: [safety margin - try 1.0]
      # use_interpolation: [smooth path following - try true]

      # Transform and goal handling
      transform_tolerance: 0.1               # Transform lookup tolerance
      allow_reversing: false                 # Don't allow backing up

````

**Option B: DWB Controller (Advanced - Better Obstacle Avoidance)**

```yaml
# Alternative controller configuration for advanced users
controller_server:
  ros__parameters:
    use_sim_time: false
    controller_frequency: 20.0
    controller_plugins: ["FollowPath"]

    FollowPath:
      plugin: "dwb_core::DWBLocalPlanner"
      debug_trajectory_details: false

      # Scout
````
