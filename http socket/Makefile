CC := gcc
CFLAGS := -Wall

CLIENT_SRC := httpClient.c
SERVER_SRC := httpServer.c

CLIENT_OUTPUT := httpClient
SERVER_OUTPUT := httpServer

all: $(CLIENT_OUTPUT) $(SERVER_OUTPUT)

$(CLIENT_OUTPUT): $(CLIENT_SRC)
	$(CC) $(CFLAGS) -o $@ $^

$(SERVER_OUTPUT): $(SERVER_SRC)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f $(CLIENT_OUTPUT) $(SERVER_OUTPUT)