xhost + 127.0.0.1

docker exec -it "dev-ros-container" /bin/bash  -c "export DISPLAY=host.docker.internal:0 && cd ~/catkin_ws/ && source devel/setup.sh && bash"