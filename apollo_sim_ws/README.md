This branch is concerned with the description of, and implementation of a custom agileX scout mini gazebo model. This is an attempt to get closer to building an autonomous system from scratch while making the showcases as close to our real robot (Scout Mini) as possible. 

The hierarchy necessary to complete this project consists of multiple ROS2 packages that are combined to achieve a given goal. For this implementation specifically I will have one main folder (apollo_sim_ws) and have sub folders created with necessary ROS2 package dependencies using:

Folder apollo_sim_description:
`ros2 pkg create --build-type ament_cmake apollo_sim_description`

Folder apollo_sim_simulation:
`ros2 pkg create --build-type ament_cmake apollo_sim_simulation`

Folder apollo_sim_control:
`ros2 pkg create --build-type ament_python apollo_sim_control`
