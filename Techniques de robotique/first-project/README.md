# ROS Env 🤖

Bonjour les petits ☀️

Voici une série de commandes pour configurer ce ptn de ROS

D'abord, dans le folder `/Techniques de robotique/first-project`, on fait le build de l'image docker définit par le Dockerfile:

```shell
$ docker build -t ros-dev .
```

Ensuite, utilise cette commande pour lancer le `roscore`:

```shell
$ ./roscore.sh
```

Et, finalement, dans un nouveau terminal:

```shell
$ ./ros-env.sh
```

Cette dernière commande va te préparer l'environement ROS configuré (Où on peut lancer la simulation de la tortue, par exemple)

Allez, bonne soirée! La bise! 💃🏼🕺🏽