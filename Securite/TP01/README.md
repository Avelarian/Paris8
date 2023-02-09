# Bonsoir Monsieur Villeneuve 🫡

Voici le projet que vous nous avez demandé... Alors, il faut le faire marcher chez vous non ?

Donc, d'abord, je vous expliquerai ce que j'ai fait :

Comme un bon développeur backend, je ne me suis pas trop investi dans un projet frontend, mais plutôt un projet backend. Alors, en regardant l'arbre du projet, vous allez voir trois fichier qui compose mon interface utilisateur (index.html.css.js) et un dossier backend où la magie est faite ! 🪄

Pour ce projet, j'ai décidé d'utiliser deux technologies principaux : NestJS et Prisma. Je peux justifier ce choix avec mon alternance, je me suis mi à étudier et travailler avec ces deux là et donc, je voulais mettre en pratique me connaissances pour savoir si je sais vraiment mettre en ouvre une application secure avec ces technologies. 🏰

Alors, en gros, NestJS est un framework pour NodeJS (le fameux substitute de Express) et Prisma est tout simplement une ORM.

Pour le lancer chez vous, d'abord il va falloir le old friend : Docker ! 🐳

Vous pouvez ouvrir un terminal et vous mettre dans le folder backend où vous lancerez :

```shell
docker compose up
```

Voilà ! Le service de la base de données est up ! Par contre, ne vous pressez pas, il faut d'abord créer la structure de notre bd. Pour cela, veuillez ouvrir un deuxième terminal, où vous allez lancer d'abord :

```shell
yarn install
```

Et ensuite :

```shell
npx prisma migrate
```

Bravo ! Vous êtes all set pour commencer vos tests ! N'oubliez juste pas de lancer le serveur (evidémment) :

```shell
yarn start:dev
```

Et s'il existe encore le doute, pour accéder la page de l'interface utilisateur, il vous faut juste copier le chemin du fichier index.html et le mettre dans votre navigateur.

Bon, je vous ai donnée toutes les instructions nécessaires. Maintenant, j'espère que vous n'arrivez pas à invahir mon chateau ! 💂🏼‍♂️

En tout cas, bon tests et bonne soirée ! À plus tard !