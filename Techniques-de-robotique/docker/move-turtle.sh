if (( $# < 3 )) || (( $# > 4 )) 
then
    echo "Illegal number of parameters"
    echo "Usage: ./docker/move-turtle.sh \$x \$y \$z \$frequency?"
    exit
fi

args=("$@")

if [ ${args[3]} ]; then
    rostopic pub -r ${args[3]} /turtle1/cmd_vel geometry_msgs/Twist -- "[${args[0]}, ${args[1]}, 0.0]" "[0.0, 0.0, ${args[2]}]"
fi


rostopic pub /turtle1/cmd_vel geometry_msgs/Twist -- "[${args[0]}, ${args[1]}, 0.0]" "[0.0, 0.0, ${args[2]}]"