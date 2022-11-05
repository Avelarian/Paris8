IMAGE_NAME="ros-dev"
CONTAINER_NAME="dev-ros-container"
ROOT_VOLUME="$PWD/src"
CONTAINER_ROOT_PATH="/root"
DOCKER_SCRIPTS="./docker"

docker run --rm -dt --name $CONTAINER_NAME -v "$ROOT_VOLUME:$CONTAINER_ROOT_PATH" $IMAGE_NAME 

CONTAINER_ID=$(docker ps -q -l)

docker exec -it $CONTAINER_ID /bin/bash -c ". opt/ros/kinetic/setup.sh && mkdir -p /root/catkin_ws/src && cd /root/catkin_ws/ && yes | catkin_make && source devel/setup.sh && roscore"

docker container stop $CONTAINER_ID