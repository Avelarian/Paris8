#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "training.cpp"

int main()
{
    pthread_t thread1, thread2, thread3;
    // TODO: Make a list that the user can choose the function that he wants to train;
    char *functionTypes[2] = {"AND", "XOR"};

    pthread_create(&thread1, NULL, training, (void *)functionTypes[0]);
    pthread_create(&thread2, NULL, training, (void *)functionTypes[0]);
    pthread_create(&thread3, NULL, training, (void *)functionTypes[0]);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    return 0;
}