# Environment Settup
Below is the procedure for Windows 10 on how to settup the ROS Humble Desktop, Gazebo (Ignition), & RVIZ working on a docker container for uniform devolopment experiences

System Requirements:
- [Docker Desktop](https://www.docker.com/products/docker-desktop/)
- [X Launch](https://sourceforge.net/projects/vcxsrv/) (VCXSRV)

Run the following command in your terminal: 
## Building established Docker image
```
docker build -t ros_dev_image https://github.com/Charlotte-AI-Research/apollo#environment:Docker/
```

## Building Docker image locally
Run the following command in your terminal: 
```
git clone https://github.com/Charlotte-AI-Research/apollo.git
```

```
cd ./apollo/Docker
```

```
docker build -t ros_dev_image https://github.com/ .
```

## Running the Docker Image
```
docker run --gpus=all --name ros_dev_environment -e DISPLAY=host.docker.internal:0.0 -it ros_dev_image 
```
*Side note -it = interactive container meaning we can update the contents inside, --name is an argument to add a name to it, Display environment variables allows us windows to talk to the virtual machine display*

This will start your ROS virtual container, allowing you to start the development cycle

This can be confirmed by seeing something similar to below, this means you are inside the docker container
```
root@487ygdkh3823:/#
```

## Opening multiple instances of a Container:
Run the following command to list all running docker instances
```
docker ps
```
The output will resembles the results below
```
CONTAINER ID   IMAGE           COMMAND                  CREATED          STATUS          PORTS     NAMES
c72361011d19   ros_dev_image   "/ros_entrypoint.sh …"   28 seconds ago   Up 26 seconds             ros_dev_environment
```

```
docker exec -it {CONTAINER ID} bash
```

```
docker exec -it c72361011d19 bash
```

# Important 
Launch `XLaunch` using Xlaunch **set display_number** -1 to `0`



https://www.youtube.com/watch?v=qWuudNxFGOQ


