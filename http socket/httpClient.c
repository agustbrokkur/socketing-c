#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 80

int main(int argc, char **argv) {
    char *ipAddress = argv[1];

    int clientSocket;
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in remoteAddress;
    remoteAddress.sin_family = AF_INET;
    remoteAddress.sin_port = htons(PORT);
    inet_aton(ipAddress, &remoteAddress.sin_addr);

    connect(clientSocket, (struct sockaddr *)&remoteAddress, sizeof(remoteAddress));

    char request[] = "GET / HTTP/1.1\r\n\r\n";
    char response[1024];

    send(clientSocket, request, sizeof(request), 0);
    //recv(clientSocket, &response, sizeof(response), 0);
    while (recv(clientSocket, &response, sizeof(response), 0) > 0) {
        printf("------------------------------------------\n");
        printf("%s", response);
        printf("------------------------------------------\n");
    }

    //printf("Response from server '%s': %s\n", ipAddress, response);
    close(clientSocket);

    return 0;
}