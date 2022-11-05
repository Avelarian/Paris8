xhost + 127.0.0.1

CONTAINER_ID=$(docker ps -q -l)
DOCKER_SCRIPTS="./docker"
CONTAINER_ROOT_PATH="/root/catkin_ws"

docker cp "$DOCKER_SCRIPTS" $CONTAINER_ID:"$CONTAINER_ROOT_PATH"

docker exec -it $CONTAINER_ID /bin/bash  -c "export DISPLAY=host.docker.internal:0 && cd /root/catkin_ws/ && source devel/setup.sh && bash"