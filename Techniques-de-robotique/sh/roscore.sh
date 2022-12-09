IMAGE_NAME="ros-dev"
CONTAINER_NAME="dev-ros-container"
ROOT_VOLUME="$PWD/src"
CONTAINER_ROOT_PATH="/root"
DOCKER_SCRIPTS="./docker"

xhost + 127.0.0.1

docker run --rm -dt --name $CONTAINER_NAME -v "$ROOT_VOLUME:$CONTAINER_ROOT_PATH" -e "TURTLEBOT3_MODEL=burger" -e "DISPLAY=host.docker.internal:0" $IMAGE_NAME 

CONTAINER_ID=$(docker ps -q -l)

docker exec -it $CONTAINER_ID /bin/bash -c ". opt/ros/kinetic/setup.sh && mkdir -p /root/catkin_ws/src && cd /root/catkin_ws/ && rosdep update && rosdep check --from-paths . --ignore-src --rosdistro kinetic && rosdep install --from-paths . --ignore-src --rosdistro kinetic -y && yes | catkin_make && source devel/setup.sh && roslaunch gazebo_ros empty_world.launch"

docker container stop $CONTAINER_ID
