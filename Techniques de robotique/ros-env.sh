xhost + 127.0.0.1

CONTAINER_ID=$(docker ps -q -l)
SRC_PATH="./TP01/"
DEST_PATH="~/catkin_ws/"

docker cp $SRC_PATH $CONTAINER_ID:$DEST_PATH

docker exec -it "dev-ros-container" /bin/bash  -c "export DISPLAY=host.docker.internal:0 && cd ~/catkin_ws/ && source devel/setup.sh && bash"