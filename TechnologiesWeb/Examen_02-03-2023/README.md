### Examen Angular - Ian Avelar Peixoto

## Partie 1

# Question 1: 

Single Page Applications c'est une application développée avec orientation à un système de Routing. Routing c'est une technique utilisé pour changer le code, qui sera affiché dynamiquement en dépendant de l'URL accédé. Et donc, le code changé est toujours mi dans le même fichier (souvent un index.hmtl). Donc, en résumé, c'est une application qui reécrit le code qui sera affiché utilisant un seule fichier à partir de l'URL fourni.

# Question 2: 

Quelques avantages dans l'utilisation de Angular:

- Grosse communauté de développeurs, donc très facile à trouver la solution à un problème rencontré;
- C'est très robuste comme framework, c'est à dire qu'il nous fourni une grande variété d'outils pour gérer la sécurité de l'application, son scalabilité aussi;
- Il utilise Typescript, et donc, dans le groupe de frameworks Javascript pour le frontend, c'est une grosse avantage vu que Typescript nous aide a construir applications plus stables et que sont type-safe;
- Il possède une built-in architecture MVC qui nous aide énormement dans l'organisation du code;
- Il est orienté par ses modules et donc c'est plus simple de comprendre les diverses parties du code;
- Il possède de HTML custom directives qui nous aide au traitement dans les components (par example, `ngFor`, `ngOnInit`, etc.).

# Question 3:

Pour réaliser une interaction de données entre le composant parent et le composant enfant dans Angular il faut utiliser les directives `Input` et `Output`.

Par example:

```typescript
// Dans le composant enfant je déclare des variable

// Pour envoyer du parent envers l'enfant
@Input() first!: Type;

// Pour envoyer de l'enfant envers le parent
@Output() second!: EventEmitter;
```

```html
<!-- Et donc, dans le component parent, j'utilise la tag de l'enfant -->
<app-child-compoenent 
<!-- Pour envoyer la donnée qui l'enfant attend d'après la variable `first` -->
[first]="first"
<!-- Pour recevoir la donnée qui l'enfant envoie d'après la variable 'second' -->
(second)="eventReceiver($event)">
</app-child-component>
```

# Question 4:

```html
<ul>
    <li *ngFor="let item of Items">{{ item }}</li>
</ul>
```

# Question 5:

```html
<!-- Ce ne va montrer que les items plus grands que 5 -->
<ul>
    <li *ngFor="let item of Items" *ngIf="item > 5">{{ item }}</li>
</ul>
```

# Question 6:

Les parties basiques d'une application Angular sont :

- Le root component;
- Le npm_modules qui possèdent tous les dépendences installés de l'application (dictés par package.json);
- Le root component (et les autres si existants) composés par un fichier html, un fichier typescript et un fichier module;
- Un fichier service peut être ajouté soit dans le component soit dans un dossier services dédié (bonne pratique);
- De fichiers de configuration comme le linter, etc.

# Question 7:

`OnInit` est une implémentation possible dans les components d'Angular qui nous offres de divers outils, mais le principal c'est la possibilité d'utiliser la fonction `ngOnInit` qui est une fonction exécutée quand le component a finit de charger dans l'application. Exemple d'implémentation:


```typescript
class AngularClass implements OnInit {
    constructor () {}

    ngOnInit() {
        // Alors, tu peux ajouter ici le code 
        // qui sera exécuté au moment que le component finit de charger
    }
}
```

# Question 8.1:

```typescript
const getUser = function (login) {
    return new Promise((resolve, reject) => {
        // Comme nous n'avons pas une variable response dans cet environment
        // Ça me semble très bizarre, une condition plus croyable serait
        // const isLoginValid = this.userService.verifyLogin(login);
        // Et donc, on utilise la variable isLoginValid
        if (response.status === 200) {
            resolve(login);
        } else {
            reject(new Error('Login is not valid.'))
        }
    })
}

getUser()
  .then(login => console.log(`Login is valid and its value is ${number}`))
  .catch(error => console.error(error));
```

# Question 8.2:

```typescript
// Avec les callBacks :
getUser(login, function (user) {
    if (!user) throw new Error(`User (=${user}) is not valid.`)
    getRights(user, function (rights) {
        if (!rights) throw new Error(`Rights (=${rights}) are not valid.`)
        updateMenu(rights);
    });
});

// Avec les Promises
getUser(login).then((user) => {
    return getRights(user)
}).catch((error) => {
    throw new Error(error)
}).then((rights) => {
    return updateMenu(rights)
}).catch((error) => {
    throw new Error(error)
})
```

# Question 9:

```typescript
getUser(login).then((user) => {
    return getRights(user)
}).then((rights) => {
    return updateMenu(rights)
}).catch((error) => {
    throw new Error(error)
})
```

# Question 10:

```typescript
getUser(login).then((user) => {
    return getRights(user)
}).catch((error) => {
    throw new Error(error)
}).then((rights) => {
    return updateMenu(rights)
}).catch((error) => {
    throw new Error(error)
})
```

## Partie 2

- 1: Angular est un framework JavaScript

- 2: Quelle commande du CLI crée une nouvelle application Angular ? ng new

- 3: Quel décorateur utilise-t-on pour rendre une propriété de
component injectable depuis son parent ? @Input()

- 4: Sur quels éléments DOM ce sélecteur de métadonnées de
composant correspondra-t-il ? Toutes les instances de <app-user-card></app-user-card>

- 5: Avec la classe de composant suivante, quelle syntaxe de modèle
utiliseriez-vous dans le modèle pour afficher la valeur du champ
de classe de titre ?

Dans le typescript :

```typescript
console.log(this.title);
```

Dans le html (Imaginons que nous allons l'afficher dans une balise `h1`):

```html
<div>
    <h1>{{ title }}</h1>
</div>
```

## Partie 3:




