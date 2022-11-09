# ROS Env 🤖

Bonjour les petits ☀️

Voici une série de commandes pour configurer ce ptn de ROS

D'abord, dans le folder `/Techniques-de-robotique`, on fait le build de l'image docker définit par le Dockerfile:

```shell
$ docker build -t ros-dev .
```

Ensuite, utilise cette commande pour lancer le `roscore` dans le même terminal:

```shell
$ ./sh/roscore.sh
```

Et, finalement, dans un nouveau terminal:

```shell
$ ./sh/ros-env.sh
```

Cette dernière commande va te préparer l'environement ROS configuré (Où on peut lancer la simulation de la tortue, par exemple)

## Robot

### Turtle

Alors, pour lancer la tortue, utilisez la commande dans un terminal créé par `ros-env`:

```shell
$ rosrun turtelsim turtlesim_node
```

### Robot

Donc, pour faire le dernier TP demandé, nous avons créé un package qui s'appelle robot. Dans ce package nous avons placé un script qui la fait bouger en carré.

Afin de le faire, avec un terminal qui exécute la simulation de la tortue, ouvrez un nouveau terminal, créez à nouveau un `ros-env`.

D'abord, faites le script devenir exécutable:

```shell
$ chmod u+x ./src/robot/script/turtlesim_moves_square.py
```

Juste après ça, vous faites un nouveau `catkin_make` afin de builder le projet et, finalement, lancez:

```shell
$ rosrun robot turtlesim_moves_square.py
```

Allez, bonne soirée! La bise! 💃🏼🕺🏽