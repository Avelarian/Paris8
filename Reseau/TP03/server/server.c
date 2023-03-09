#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>

typedef struct {
    int type; // 1 for number, 2 for image, 0 for response
    char message[1024];

    int number;

    char filename[1024];
    char fileData[1024];
    int fileSize; // Added field to store the length of the data
} Message;

int factorial(int number) {
    int index;
    int factorial = 1;

    // Check if the number is negative
    if (number < 0) {
        printf("Error: Factorial of negative number doesn't exist.");
        return 0;
    }

    // Calculate the factorial
    for (index = 1; index <= number; index++) {
        factorial *= index;
    }

    return factorial;
}

void handleNumberMessage(int clientSocket, Message request) {
    // Calculate factorial of the number
    int recievedNumber = ntohl(request.number);
    printf("Calculating factorial of %d\n", recievedNumber);
    int result = factorial(recievedNumber);

    // Send response back to client
    printf("Sending response back to client...\n");
    Message response = {0};
    response.type = 0; // type response
    response.number = htonl(result);
    strcpy(response.message, "Factorial calculated!");
    send(clientSocket, &response, sizeof(response), 0);
}

void handleImageMessage(int clientSocket, Message request) {
    // Save image to file
    printf("Saving image to file...\n");
    FILE *fp;
    fp = fopen(request.filename, "wb");
    fwrite(request.fileData, sizeof(char), request.fileSize, fp);
    fclose(fp);

    // Send response back to client
    printf("Sending response back to client...\n");
    Message response = {0};
    response.type = 0; // type response
    strcpy(response.message, "Image received!");
    send(clientSocket, &response, sizeof(response), 0);
}

void handleMessage(int clientSocket, Message message) {
    if (message.type == 1) {
        printf("Handling number message...\n");
        handleNumberMessage(clientSocket, message);
    } else if (message.type == 2) {
        printf("Handling image message...\n");
        handleImageMessage(clientSocket, message);
    } else {
        printf("Invalid message type!\n");
        // Send response back to client
        Message response = {0};
        response.type = 0; // type response
        strcpy(response.message, "Request type doesn't exist!");
        send(clientSocket, &response, sizeof(response), 0);
    }
}

int main(){
    int serverSocket, newSocket;
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;
    Message request;

    // Create socket
    serverSocket = socket(PF_INET, SOCK_STREAM, 0);

    // Configure server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    // Bind socket to address
    bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

    // Listen for incoming connections
    if(listen(serverSocket,5) == 0)
        printf("Listening...\n");
    else
        printf("Error...\n");

    // Accept incoming connections
    addr_size = sizeof serverStorage;
    newSocket = accept(serverSocket, (struct sockaddr *) &serverStorage, &addr_size);
    printf("Connected to client and ready to recieve data!\n");

    // Receive message from client
    int bytesReceived = recv(newSocket, &request, sizeof(request), 0);
    if (bytesReceived == 0) {
        // Connection closed by client
        printf("Connection closed by client...\n");
        close(newSocket);
        return 0;
    } else if (bytesReceived < 0) {
        // Error receiving data
        perror("Function recv failed...\n");
        exit(EXIT_FAILURE);
    }

    if (request.type == 0) {
        // Connection closed by client
        printf("Connection closed by client...\n");
        close(newSocket);
        return 0;
    } else {
        handleMessage(newSocket, request);
    }

    close(newSocket);
    return 0;
}