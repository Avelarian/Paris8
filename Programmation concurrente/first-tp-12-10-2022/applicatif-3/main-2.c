#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *fsomme(void *arg);
void *fproduit(void *arg);

int main(int argc, char *argv []) {
    int index;
    pthread_t fils[2];
    char * temp;

    temp = (char *) malloc (sizeof (int) + sizeof (char));
    sprintf(temp, "%d ", 10);
    if (pthread_create(&fils[0], NULL, fsomme, (void *) temp)) {
        perror("pthread_create somme");
    }

    if (pthread_create(&fils[1], NULL, fproduit, (void *) temp)) {
        perror("pthread_create produit");
    }

    for (index = 0; index < 2; index++) {
        if (pthread_join(fils[index], NULL) == -1) {
            perror("pthread_join");
        }
    }

    printf ("Sortie du main \n");
    pthread_exit(0);
}

void * fsomme(void * arg) {
    int i, somme = 0;
    int n = atoi((char *) arg);
    for (i = 0; i <= n; i ++) somme = somme + i;
    printf("Somme = % d\n" , somme);
    pthread_exit(0);
}

void * fproduit(void * arg) {
    int i, produit = 1;
    int n = atoi((char *) arg);
    for (i = 1; i <= n; i ++) produit = produit * i;
    printf("Produit = %d\n", produit);
    pthread_exit(0);
}