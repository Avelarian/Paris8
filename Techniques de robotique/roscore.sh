docker run --rm -dt \
--name "dev-ros-container" ros-dev

docker exec -it "dev-ros-container" /bin/bash -c "cd ~/catkin_ws/ && source devel/setup.sh && roscore"

docker container stop "dev-ros-container"