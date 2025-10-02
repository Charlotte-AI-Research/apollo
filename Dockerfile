# Apollo Robotics Project - Agilex Scout Mini with ROS2 Humble
FROM ubuntu:22.04

# Prevent interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=America/New_York

# Set locale
RUN apt-get update && apt-get install -y locales \
    && locale-gen en_US.UTF-8 \
    && update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
ENV LANG=en_US.UTF-8
ENV LC_ALL=en_US.UTF-8

# Install essential packages
RUN apt-get update && apt-get install -y \
    curl \
    wget \
    git \
    build-essential \
    cmake \
    python3-pip \
    lsb-release \
    gnupg2 \
    tzdata \
    software-properties-common \
    && rm -rf /var/lib/apt/lists/*

# Add ROS2 apt repository
RUN curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg \
    && echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | tee /etc/apt/sources.list.d/ros2.list > /dev/null

# Update package list after adding ROS2 repo
RUN apt-get update

# Install ROS2 Humble Desktop Full
RUN apt-get install -y \
    ros-humble-desktop-full \
    && rm -rf /var/lib/apt/lists/*

# Install colcon build tools
RUN apt-get update && apt-get install -y \
    python3-colcon-common-extensions \
    python3-rosdep \
    && rm -rf /var/lib/apt/lists/*

# Initialize rosdep
RUN rosdep init || true \
    && rosdep update

# Install Apollo ROS2 dependencies - Navigation & SLAM
RUN apt-get update && apt-get install -y \
    ros-humble-navigation2 \
    ros-humble-nav2-bringup \
    ros-humble-slam-toolbox \
    && rm -rf /var/lib/apt/lists/*

# Install Apollo ROS2 dependencies - Control & Communication
RUN apt-get update && apt-get install -y \
    ros-humble-ros2-control \
    ros-humble-ros2-controllers \
    ros-humble-twist-mux \
    ros-humble-pluginlib \
    ros-humble-realtime-tools \
    ros-humble-can-msgs \
    ros-humble-ros2-socketcan \
    ros-humble-ros2-socketcan-msgs \
    && rm -rf /var/lib/apt/lists/*

# Install Apollo ROS2 dependencies - Visualization & Localization
RUN apt-get update && apt-get install -y \
    ros-humble-urdf \
    ros-humble-xacro \
    ros-humble-rviz2 \
    ros-humble-robot-localization \
    ros-humble-tf2-tools \
    && rm -rf /var/lib/apt/lists/*

# Install Apollo ROS2 dependencies - Sensors
RUN apt-get update && apt-get install -y \
    ros-humble-realsense2-camera \
    ros-humble-vision-opencv \
    && rm -rf /var/lib/apt/lists/*

# Install system dependencies for ugv_sdk and rslidar_sdk
RUN apt-get update && apt-get install -y \
    libasio-dev \
    libpcap-dev \
    && rm -rf /var/lib/apt/lists/*

# Install Python ML dependencies for perception stack
RUN pip3 install --no-cache-dir \
    torch \
    torchvision \
    ultralytics

# Create Apollo workspace
RUN mkdir -p /apollo_ws/src
WORKDIR /apollo_ws

# Setup ROS2 environment in bashrc
RUN echo "source /opt/ros/humble/setup.bash" >> /root/.bashrc \
    && echo "if [ -f /apollo_ws/install/setup.bash ]; then source /apollo_ws/install/setup.bash; fi" >> /root/.bashrc \
    && echo "export ROS_DOMAIN_ID=0" >> /root/.bashrc

# Keep container running
CMD ["/bin/bash"]