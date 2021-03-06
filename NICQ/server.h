#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX 50

typedef struct Account
{
	int clifd;
	char name[20];
	struct sockaddr_in cli_addr;
	pthread_t tid;	
}Account;

typedef struct sockaddr* SP;
size_t cnt;
size_t count = 0;
Account acc[MAX] = {};
	
struct sockaddr_in S_init(int* sockfd);
void* run(void* arg);


#endif//SERVER_H
