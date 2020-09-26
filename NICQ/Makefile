CC=gcc
STD=-std=gnu99
FLAG=-Wall -Werror -DEBUG
LIBS=-pthread
BIN=server client

all:$(BIN)

server:server.c server.h
	$(CC) $(STD) $(LIBS) $(FLAG) server.c -o server
	
client:client.c client.h 
	$(CC) $(STD) $(LIBS) $(FLAG) client.c -o client

clean:
	rm -rf $(BIN) *.o *.h.gch
