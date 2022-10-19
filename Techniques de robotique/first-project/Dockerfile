FROM ros:kinetic-robot

RUN apt-get update && \
    . opt/ros/kinetic/setup.sh && \
    mkdir -p ~/catkin_ws/src && \
    cd ~/catkin_ws/ && \
    yes | catkin_make && \
    . devel/setup.sh && \
    yes | apt-get install ros-kinetic-ros-tutorials && \
    export DISPLAY=host.docker.internal:0
