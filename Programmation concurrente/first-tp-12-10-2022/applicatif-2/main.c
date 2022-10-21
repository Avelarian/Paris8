#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *myAuxFunction()
{
    double number;
    printf("Enter a value:\n");
    scanf("%lf", &number);
    printf("The incremented value is %lf\n", number + 1);
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
    if(pthread_join(thread, NULL)) {
        perror("Error joining thread.");
        return	EXIT_FAILURE;
    };
    printf("Closing thread...\n");
    return EXIT_SUCCESS;
}