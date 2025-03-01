FROM osrf/ros:humble-desktop

# Add user with the same UID and GID as the host system (if needed)
ARG USERNAME=ubuntu
ARG USER_UID=1000
ARG USER_GID=$USER_UID
RUN if ! getent passwd $USER_UID >/dev/null; then \
        groupadd --gid $USER_GID $USERNAME && \
        useradd -s /bin/bash --uid $USER_UID --gid $USER_GID -m $USERNAME; \
    fi

# Add sudo support for the non-root user
RUN apt-get update && \
    apt-get install -y --no-install-recommends sudo && \
    echo "$USERNAME ALL=(root) NOPASSWD:ALL" > /etc/sudoers.d/$USERNAME && \
    chmod 0440 /etc/sudoers.d/$USERNAME

# Add user to video group to allow access to webcam
RUN usermod --append --groups video $USERNAME

# Switch from root to user
USER $USERNAME

# Install necessary packages in a single step to optimize caching
RUN sudo apt update && sudo apt install -y --no-install-recommends \
    git \
    ros-humble-rosidl-typesupport-c \
    ros-humble-rosidl-default-generators \
    ros-humble-robot-state-publisher \
    ros-humble-builtin-interfaces \
    python3-colcon-common-extensions \
    build-essential \
    ros-humble-xacro \
    ros-humble-joint-state-publisher-gui \
    ros-humble-ros2-control \
    ros-humble-ros2-controllers \
    ros-humble-can-msgs \
    ros-humble-ros2-socketcan \
    ros-humble-twist-mux \
    ros-humble-gazebo-ros-pkgs \
    && sudo rm -rf /var/lib/apt/lists/*

# Update package sources and upgrade existing packages
RUN sudo apt update && sudo apt upgrade -y

# Rosdep update
RUN rosdep update

# Source the ROS setup file automatically in every new shell session
RUN echo "source /opt/ros/${ROS_DISTRO}/setup.bash" >> ~/.bashrc

################################
## ADD ANY CUSTOM SETUP BELOW ##
################################
