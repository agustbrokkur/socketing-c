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
	int clientSocket;
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(PORT);
	serverAddress.sin_addr.s_addr = INADDR_ANY;

	int connectionStatus = connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

	if (connectionStatus == 0) {
		printf("Connection successful\n");
	} else {
		printf("Connection failed\n");
		close(clientSocket);
		return -1;
	}

	char buffer[256];
	recv(clientSocket, &buffer, sizeof(buffer), 0);

	printf("Server: %s\n", buffer);
	close(clientSocket);

	return 0;
}
