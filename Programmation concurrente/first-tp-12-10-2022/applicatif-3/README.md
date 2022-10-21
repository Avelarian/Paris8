### Aplicatif 3

Afin d'exécuter cet application, on doit lancer la commande:

```shell
$ gcc main.c -lpthread -o monProgramme
```

Obs.: La dernière valeur représente le nom de l'exécutable.

Alors, pour exécuter ce que l'on a compilé, il faut juste lancer:

```shell
$ ./monProgramme
```

Dans cet exercise nous pouvons remarquer:
- Le thread à sa fin fait appel a `pthread_exit` automatiquement
- 