# This is an example Docker File
#  Command to build it
# docker built -t <image name > .
FROM osrf/ros:humble-desktop-full

RUN apt-get update
RUN apt-get install -y git
RUN apt install -y python3-pip wget lsb-release gnupg curl

RUN sudo apt-get update

# Gazebo installation process
RUN sudo apt-get install lsb-release wget gnupg
RUN sudo wget https://packages.osrfoundation.org/gazebo.gpg -O /usr/share/keyrings/pkgs-osrf-archive-keyring.gpg
RUN echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/pkgs-osrf-archive-keyring.gpg] http://packages.osrfoundation.org/gazebo/ubuntu-stable $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/gazebo-stable.list > /dev/null
RUN sudo apt-get update
RUN sudo apt-get install -y ignition-fortress

RUN echo "Gazebo Installed"

RUN mkdir -p ~/catkin_ws/src && \
    cd ~/catkin_ws/src/

RUN  sudo apt-get install ros-humble-ros-gz

# Todo enable github building and repo sync-ing

Run echo "Complete!"
Run echo "To run gazebo run ign gazebo"
RUN echo "Ensure Xlaunch with the following config Display_number = 0, and multiple window is running"