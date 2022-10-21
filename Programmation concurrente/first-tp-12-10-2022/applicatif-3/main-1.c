#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t lock;

void *printMessageFunction(void *messagePointer) {
    pthread_mutex_lock(&lock);

    char * message;
    message = (char *) messagePointer;

    printf("%s started\n", message);
    sleep(3);
    printf("%s finished\n", message);

    pthread_mutex_unlock(&lock);
}

int main() {
    pthread_t firstThread, secondThread;

    char *firstThreadMessage = "First thread";
    char *secondThreadMessage = "Second thread";
    int index;

    if (pthread_mutex_init(&lock, NULL) == -1) {
        printf("\n Mutex init has failed\n");
        return 1;
    }

    // Simulate the error of thread synchronization with and without mutex
    for (index = 0; index < 100; index++) {
        if (pthread_create(&firstThread, NULL, printMessageFunction, (void *) firstThreadMessage) == -1) {
            perror("Thread 1 has failed\n");
            exit(0);
        }
        if (pthread_create(&secondThread, NULL, printMessageFunction, (void *) secondThreadMessage) == -1) {
            perror("Thread 2 has failed\n");
            exit(0);
        }
        
        if (pthread_join(firstThread, NULL) == -1) {
            perror("Thread 1 has failed when executing\n");
            exit(0);
        }
        if (pthread_join(secondThread, NULL) == -1) {
            perror("Thread 2 has failed when executing");
        }
    }

    pthread_mutex_destroy(&lock);
    
    return 0;
}