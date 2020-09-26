#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

typedef struct Account
{
	int clifd;
	char name[20];
	struct sockaddr_in cli_addr;
}Account;

Account acc;


struct sockaddr_in C_init(int* sockfd);
void* receive(void* arg);
void* pickup(void* arg);
#endif//CLIENT_H
