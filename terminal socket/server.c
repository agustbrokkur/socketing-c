#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#define PORT 8080

// AF_INET = IPV4
// SOCK_STREAM = TCP
// INADDR_ANY = Any address -> 0.0.0.0 IP
// htons = make value netweork compliant (big-endian)

int main() {
	int serverSocket;
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(PORT);
	serverAddress.sin_addr.s_addr = INADDR_ANY;

	bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

	listen(serverSocket, 64);

	int clientSocket;
	clientSocket = accept(serverSocket, NULL, NULL);

	char buffer[256] = "Successfully connected to the server!";
	send(clientSocket, &buffer, sizeof(buffer), 0);

	close(serverSocket);

	return 0;
}
