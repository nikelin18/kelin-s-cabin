#include "client.h"

struct sockaddr_in C_init(int* sockfd)
{
	*sockfd = socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(5678);
	addr.sin_addr.s_addr = inet_addr("172.20.10.2");	
	return addr;
}

void* receive(void* arg)
{
	char buf[4096] = {};
	size_t buf_size = sizeof(buf);
	while(acc.clifd)
	{
		int ret = recv(acc.clifd,buf,buf_size,0);	
		if(0 >= ret)
		{
			puts("连接断开");
			acc.clifd = 0;
		}	
		puts(buf);
		memset(buf,0,buf_size);
	}
	return NULL;
}

void* pickup(void* arg)
{
	char buf[4096] = {};
	size_t buf_size = sizeof(buf);
	while(acc.clifd)
	{	
		gets(buf);
		send(acc.clifd,buf,buf_size,0);
		if(0 == strcmp("quit",buf))
		{
			puts("END");
			acc.clifd = 0;
		}
		memset(buf,0,buf_size);
	}
	return NULL;
}

int main(int argc,const char* argv[])
{
	acc.cli_addr = C_init(&acc.clifd); 
	if(acc.clifd < 0)
	{
		perror("socket");
		return EXIT_FAILURE;
	}
	
	if(connect(acc.clifd,(struct sockaddr*)&acc.cli_addr,sizeof(acc.cli_addr)))
	{
		perror("connect");
		return EXIT_FAILURE;
	}
	
	printf("请输入昵称：");
	scanf("%s",acc.name);
	
	send(acc.clifd,acc.name,strlen(acc.name)+1,0);
	send(acc.clifd,&acc.cli_addr,sizeof(acc.cli_addr),0);
	
	pthread_t tid1,tid2;
	pthread_create(&tid2,NULL,pickup,NULL);
	pthread_create(&tid1,NULL,receive,NULL);

	while(acc.clifd!=0);

}

