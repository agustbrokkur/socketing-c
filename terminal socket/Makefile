CC := gcc
CFLAGS := -Wall

CLIENT_SRC := client.c
SERVER_SRC := server.c

CLIENT_OUTPUT := client
SERVER_OUTPUT := server

all: $(CLIENT_OUTPUT) $(SERVER_OUTPUT)

$(CLIENT_OUTPUT): $(CLIENT_SRC)
	$(CC) $(CFLAGS) -o $@ $^

$(SERVER_OUTPUT): $(SERVER_SRC)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f $(CLIENT_OUTPUT) $(SERVER_OUTPUT)