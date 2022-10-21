#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void * input()
{
    int value;
    printf("Enter a value:\n");
    scanf("%d", &value);
    return (void *) value;
}

void * output(void * value)
{
    int index, newValue = (int) (void *) value;
    for (index = 0; index < 10; index++) {
        newValue += 1;
        printf("Result of the iteration %d is: %d\n", index + 1, newValue);
    }
}
  
int main()
{
    void * value;
    pthread_t thread[2];

    if(pthread_create(&thread[0],	NULL, input, NULL) == -1) {
        perror("Error creating thread.");
        return	EXIT_FAILURE;
    }
    if(pthread_join(thread[0], &value)) {
        perror("Error joining thread.");
        return	EXIT_FAILURE;
    }

    if(pthread_create(&thread[1],	NULL, output, value) == -1) {
        perror("Error creating thread.");
        return	EXIT_FAILURE;
    }
    if(pthread_join(thread[1], NULL)) {
        perror("Error joining thread.");
        return	EXIT_FAILURE;
    };
    return EXIT_SUCCESS;
}