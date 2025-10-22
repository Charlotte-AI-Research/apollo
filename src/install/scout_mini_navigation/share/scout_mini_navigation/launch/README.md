# Launch Folder Overview

This folder contains all launch files for the `scout_mini_navigation` package.
Each team is responsible for creating and updating specific launch files
based on their assigned components of the Nav2 stack.

---

## Launch File Responsibilities

### Team 1 – Localization & Lifecycle Management
- **File:** `localization.launch.py`
- **Purpose:** Launches the map server, AMCL node, and the lifecycle manager for localization.
- **Notes:**
  - Should reference parameters from `config/amcl_params.yaml` or `nav2_params.yaml`.
  - Must start **before** any costmap or planner nodes.
  - Provides the `map→odom` transform required by Team 2.

---

### Team 2 – Costmaps & Planning
- **File:** Will extend `nav2.launch.py`
- **Purpose:** Adds costmap servers and planner nodes (global + local costmaps, Smac planner).
- **Notes:**
  - Requires `/amcl_pose` and `map→odom` transform from Team 1.
  - Uses configuration files from `config/costmap_*` and `planner_params.yaml`.
  - Should be verified with RViz visualization of costmaps and `/plan` topic.

---

### Team 3 – Controllers & Behaviors
- **File:** Also extends `nav2.launch.py`
- **Purpose:** Adds controller servers, recovery behaviors, and BT navigator.
- **Notes:**
  - Requires costmaps and planner nodes from Team 2.
  - Uses configuration files from `config/controller_params.yaml`, `bt_navigator_params.yaml`, and `recovery_params.yaml`.

---

## Integration Order

When all three teams have finished their components, the launch order should look like this:

1. **Team 1:** `localization.launch.py`
2. **Team 2:** Costmap and planner nodes (added to `nav2.launch.py`)
3. **Team 3:** Controller, BT navigator, and behavior servers (added to `nav2.launch.py`)

