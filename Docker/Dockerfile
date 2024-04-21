# This is an example Docker File
#  Command to build it
# docker built -t <image name > .
FROM osrf/ros:humble-desktop-full


RUN apt-get update
RUN apt-get install -y git
RUN apt install -y python3-pip wget lsb-release gnupg curl

RUN sudo apt-get update

# Start ROS2 & Gazebo Installation
RUN sudo apt-get install lsb-release wget gnupg
RUN sudo wget https://packages.osrfoundation.org/gazebo.gpg -O /usr/share/keyrings/pkgs-osrf-archive-keyring.gpg
RUN echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/pkgs-osrf-archive-keyring.gpg] http://packages.osrfoundation.org/gazebo/ubuntu-stable $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/gazebo-stable.list > /dev/null
RUN sudo apt-get update
RUN sudo apt-get install -y ignition-fortress
RUN sudo apt-get install ros-humble-ros-ign-bridge

RUN echo "Gazebo Installed"

RUN mkdir -p ~/catkin_ws/src && \
    cd ~/catkin_ws/src/

RUN  sudo apt-get install ros-humble-ros-gz
RUN sudo apt-get update
# END ROS2 & Gazebo installation


# Intialise Turtle Bot, basis of implementation: https://github.com/gazebosim/gz-omni/blob/main/tutorials/03_ROS_simulation.md
#enables ROS humble to allow compliation


# Set the working directory
RUN mkdir -p /root/turtlebot3_ws/src
WORKDIR /root/turtlebot3_ws/src

# Create directories and clone repositories
RUN git clone https://github.com/ahcorde/turtlebot3_simulations -b ahcorde/ignition_support && \
    git clone https://github.com/ignitionrobotics/ign_ros2_control -b humble

# Install dependencies
RUN rosdep install --from-paths ./ -i -y --rosdistro humble

# Set environment variable
ENV IGNITION_VERSION=fortress

# Build the workspace
RUN . /opt/ros/${ROS_DISTRO}/setup.sh && \
    cd /root/turtlebot3_ws/src && \
    colcon build --merge-install --event-handlers console_direct+

# End of Intialisation of Turtle Bot 3 for ROS


# Auto enable ROS2
COPY ros_setup.sh /root/
RUN chmod +x /root/ros_setup.sh
RUN echo "source /root/ros_setup.sh" >> /root/.bashrc
# End of Auto enable Ros2

# Auto enable Turtlebot 3
COPY turtlebot_setup.sh /root/
RUN chmod +x /root/turtlebot_setup.sh
RUN echo "source /root/turtlebot_setup.sh" >> /root/.bashrc
# End of Auto enable Turtlebot

RUN echo "\n Ensure Xlaunch with the following config Display_number = 0, and multiple window is running"