# Config Folder Structure

Each team is responsible for creating their own configuration files here.

- Team 1 → `amcl_params.yaml`, updates the Team 1 section in `nav2_params.yaml`
- Team 2 → `costmap_*` and `planner_params.yaml`, updates the Team 2 section in `nav2_params.yaml`
- Team 3 → `controller_params.yaml`, `bt_navigator_params.yaml`, `recovery_params.yaml`, updates the Team 3 section in `nav2_params.yaml`

`nav2_params.yaml` is shared and should contain all three teams’ sections once integrated.
