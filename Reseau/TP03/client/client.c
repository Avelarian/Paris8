#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>

struct MenuOption {
    int optionNumber;
    const char *optionText;
};

struct MenuOption menuOptions[] = {
    {1, "Send a number"},
    {2, "Send an image"},
    {0, "Exit"}
};

typedef struct {
    int type; // 1 for number, 2 for image, 0 for response
    char message[1024];

    int number;

    char filename[1024];
    char fileData[1024];
    int fileSize; // Added field to store the length of the data
} Message;

void numberExchange(int clientSocket) {
    // Get number from user
    int number;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &number);

    // Send data to server
    printf("Sending number to server...\n");
    uint32_t numberToSend = htonl(number);
    Message message = {0};
    message.type = 1; // number message
    message.number = numberToSend;

    send(clientSocket, &message, sizeof(message), 0);

    printf("Waiting for server response...\n");

    // Receive data from server
    Message response;
    int bytesReceived = recv(clientSocket, &response, sizeof(response), 0);
    if (bytesReceived < 0) {
        // Error receiving data
        perror("Function recv failed...");
        exit(EXIT_FAILURE);
    }

    printf("Message received from server: %s\n", response.message);
    printf("Number response received: %d\n", ntohl(response.number));
}

void imageExchange(int clientSocket) {
    // Open the image file
    FILE *file = fopen("image.jpeg", "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    // Get the size of the file
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate a buffer to hold the file data
    char *buffer = (char*) malloc(fileSize);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        fclose(file);
        return;
    }

    // Read the file data into the buffer
    size_t bytesRead = fread(buffer, 1, fileSize, file);
    if (bytesRead != fileSize) {
        printf("Error reading file\n");
        free(buffer);
        fclose(file);
        return;
    }

    // Send the file data to the server
    printf("Sending image to server...\n");
    Message message = {0};
    message.type = 2; // image message
    strcpy(message.filename, "image.jpeg");
    strcpy(message.fileData, buffer);
    message.fileSize = fileSize;

    int bytesSent = send(clientSocket, &message, sizeof(message), 0);
    if (bytesSent != sizeof(message)) {
        printf("Error sending file data\n");
        free(buffer);
        fclose(file);
        return;
    }

    // Free the buffer and close the file
    free(buffer);
    fclose(file);

    printf("Waiting for server response...\n");

    // Receive data from server
    Message response;
    int bytesReceived = recv(clientSocket, &response, sizeof(response), 0);
    if (bytesReceived < 0) {
        // Error receiving data
        perror("Function recv failed...");
        exit(EXIT_FAILURE);
    }

    printf("Message received from server: %s\n", response.message);
}

int main(){
    int clientSocket;
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    // Create socket
    clientSocket = socket(PF_INET, SOCK_STREAM, 0);

    // Configure server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    // Connect to server
    addr_size = sizeof serverAddr;
    connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

    printf("Connected to the server!\n");
    printf("What do you want to do?\n");

    for (int i = 0; i < sizeof(menuOptions) / sizeof(menuOptions[0]); i++) {
        printf("%d. %s\n", menuOptions[i].optionNumber, menuOptions[i].optionText);
    }

    int optionNumber;
    printf("Enter option number: ");
    scanf("%d", &optionNumber);

    // Check if the option number is valid
    int optionIndex = -1;
    for (int i = 0; i < sizeof(menuOptions) / sizeof(menuOptions[0]); i++) {
        if (menuOptions[i].optionNumber == optionNumber) {
            optionIndex = i;
            break;
        }
    }

    if (optionIndex < 0) {
        printf("Invalid option number\n");
        return 1;
    }

    if (menuOptions[optionIndex].optionNumber == 1) {
        numberExchange(clientSocket);
    } else if (menuOptions[optionIndex].optionNumber == 2) {
        imageExchange(clientSocket);
    } else if (menuOptions[optionIndex].optionNumber == 0) {
        printf("Exiting...\n");
    }

    return 0;
}