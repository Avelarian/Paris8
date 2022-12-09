FROM jlesage/baseimage-gui:alpine-3.6

RUN add-pkg xterm
RUN add-pkg ros-kinetic-ros-tutorials ros-kinetic-rqt-graph ros-kinetic-turtlebot3 ros-kinetic-gazebo-ros-pkgs ros-kinetic-gazebo-ros-control

COPY startapp.sh /startapp.sh

ENV APP_NAME="Xterm"