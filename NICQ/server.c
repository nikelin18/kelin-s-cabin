#include "server.h"

void* run(void* arg)
{
	Account* me = arg;
	char buf[4096] = {};
	size_t buf_size = sizeof(buf);
	sprintf(buf,"%s来了\n",me->name);
	puts(buf);
	for(int i=0;i<MAX;i++)
	{
		if(0 != acc[i].clifd && acc[i].clifd != me->clifd)
		{
			send(acc[i].clifd,&buf,strlen(buf)+1,0);
		}
	}
	char str[4096] = {};
	int flag = 0;
	while(!flag)
	{
		memset(buf,0,sizeof(buf));
		memset(str,0,sizeof(str));
		int ret = recv(me->clifd,buf,buf_size,0);
		if(0 >= ret || 0 == strcmp("quit",buf))
		{
			flag = 1;
		}		
		if(ret > 0 && strlen(buf)>0)
		{
			
			sprintf(str,"%s:%s\n",me->name,buf);
			
			puts(str);
			
			for(int i=0;i<MAX && !flag;i++)
			{
				if(0 != acc[i].clifd && acc[i].clifd != me->clifd)
				{
					send(acc[i].clifd,&str,strlen(str)+1,0);
				}
			}
		}
	}	
	
	memset(str,0,sizeof(str));
	sprintf(str,"%s走了\n",me->name);
	puts(str);
	for(int i=0;i<MAX;i++)
	{
		if(0 != acc[i].clifd && acc[i].clifd != me->clifd)
		{
			send(acc[i].clifd,&str,strlen(str)+1,0);
		}
	}
	
	close(me->clifd);
	return NULL;
}

struct sockaddr_in S_init(int* sockfd)
{
	//创建socket
	*sockfd = socket(AF_INET,SOCK_STREAM,0);
	//准备通信地址
	struct sockaddr_in svr_addr = {};
	svr_addr.sin_family = AF_INET;
	svr_addr.sin_port = htons(5678);
	svr_addr.sin_addr.s_addr = INADDR_ANY;
	return svr_addr;
}

int main(int argc,const char* argv[])
{	
	int sockfd;
	struct sockaddr_in svr_addr = S_init(&sockfd);
	if(sockfd < 0)
	{
		perror("socket");
		return EXIT_FAILURE;
	}
	socklen_t addrlen = sizeof(svr_addr);
	//绑定
	if(bind(sockfd,(SP)&svr_addr,addrlen))
	{
		perror("bind");
		return EXIT_FAILURE;
	}
	//监听
	if(listen(sockfd,MAX))
	{
		perror("listen");
		return EXIT_FAILURE;
	}
	
	while(1)
	{
		if(count>=MAX)
		{
			puts("聊天室已满");
			sleep(10);		
		}
		for(cnt = 0;cnt < MAX;cnt++)
		{
			if(0 == acc[cnt].clifd)
			{
				acc[cnt].clifd = accept(sockfd,(SP)&acc[cnt].cli_addr,&addrlen);
				if(0 > acc[cnt].clifd)
				{
					perror("accept");
					return EXIT_FAILURE;
				}
				
				recv(acc[cnt].clifd,acc[cnt].name,sizeof(acc[cnt].name),0);
				recv(acc[cnt].clifd,&acc[cnt].cli_addr,sizeof(acc[cnt].cli_addr),0);
				count++;
				
				pthread_create(&acc[cnt].tid,NULL,run,&acc[cnt]);
				
					
			}
		}	
	}

}
