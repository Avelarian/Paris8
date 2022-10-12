#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *myAuxFunction()
{
    printf("Executing my aux function in 3 seconds...\n");
    sleep(3);
    printf("Function executed\n");
    pthread_exit(NULL);
}
  
int main()
{
    pthread_t thread;
    printf("Creating thread...\n");
    if(pthread_create(&thread,	NULL, myAuxFunction, NULL) == -1) {
        perror("Error creating thread.");
        return	EXIT_FAILURE;
    }
    pthread_join(thread, NULL);
    printf("Closing thread...\n");
    return EXIT_SUCCESS;
}