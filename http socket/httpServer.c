#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080


int main() {
    FILE *pHtmlData;
    pHtmlData = fopen("index.html", "r");

    char responseData[1024];
    fgets(responseData, sizeof(responseData), pHtmlData);

    char httpHeader[2048] = "HTTP/1.1 200 OK\r\n\n";
    strcat(httpHeader, responseData);

    int serverSocket;
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

    listen(serverSocket, 64);

    int clientSocket;
    
    while (1) {
        clientSocket = accept(serverSocket, NULL, NULL);
        send(clientSocket, httpHeader, sizeof(httpHeader), 0);
        close(clientSocket);
    }

    return 0;
}
