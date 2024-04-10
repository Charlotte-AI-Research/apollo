
# Environment Settup

Below is the procedure for Windows 10 on how to settup the ROS Humble Desktop, Gazebo (Ignition), & RVIZ working on a docker container for uniform devolopment experiences

  

System Requirements:

- [Docker Desktop](https://www.docker.com/products/docker-desktop/)
- [X Launch](https://sourceforge.net/projects/vcxsrv/) (VCXSRV) **WINDOWS**
- [WSL]() **WINDOWS**
- [X Quartz](https://www.xquartz.org/) **MAC**

  

Run the following command in your terminal:

## Building established Docker image

```
docker build -t ros_dev_image https://raw.githubusercontent.com/Charlotte-AI-Research/apollo/environment/Docker/Dockerfile
```
  

## Starting the Docker Container(Windows 10/11)

If you are running the docker container for the **First time** use the following command

```
docker run  --rm --gpus=all --name ros_dev_container -e DISPLAY=host.docker.internal:0.0 -it ros_dev_image
```

## Starting the Docker Container (Linux & Mac)
Please follow the [tutorial](https://gist.github.com/sorny/969fe55d85c9b0035b0109a31cbcb088) up until step 9 use `xhost +localhost`
```
docker run --gpus=all --rm --name ros_dev_container -e DISPLAY=docker.for.mac.host.internal:0 -it ros_dev_image
```

*Side note -it = interactive container meaning we can update the contents inside, --name is an argument to add a name to it, Display environment variables allows us windows to talk to the virtual machine display*

## Resuming the container
  

Congratulations, you have made the ros_dev_container now to leave the container with the container stopping run in the ubuntu kernal `exit`or to leave the container with it running in the background, `CTRL+P` then `CTRL+Q` 

To start the container again run:
```docker start ros_dev_container --interactive ```


Once run you will see the ubuntu kernal once again:
  

## Opening multiple instances of a Container:

Run the following command to list all running docker instances
```
docker exec -it ros_dev_container bash
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
docker build -t ros_dev_image
```


# Important (Windows)

Launch `XLaunch` using Xlaunch **set display_number** -1 to `0`

  
  
  

https://www.youtube.com/watch?v=qWuudNxFGOQ
