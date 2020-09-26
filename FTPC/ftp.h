#ifndef FTP_H
#define FTP_H

#include <stdio.h>

#define IP "172.20.10.2"

typedef struct FTPClient
{
	int cli_sock;		//命令通道描述符
	int cli_pasv;		//数据通道描述符
	short port;			//端口号
	char ip[16];		//服务器ip
	char path[256];		//服务器当前路径
	int status;			//返回码
	char buf[256];		//执行结果
}FTPClient;



typedef struct sockaddr* SP;

enum{
	BYE=0,ON=1,LS_L,PWD,MKD,CWD,STOR,RETR
};

//创建FTP客户端对象
FTPClient* create_FTPClient(const char* ip,short port);

//销毁FTP客户端对象
void destory_FTPClient(FTPClient* ftp);

//向服务器发送客户端命令
void user_FTPClient(FTPClient* ftp,const char* user);

//向服务器发送密码
void pass_FTPClient(FTPClient* ftp,const char* pass);

//pwd
void pwd_FTPClient(FTPClient* ftp);

//cd
void cd_FTPClient(FTPClient* ftp);

//mkdir
void mkdir_FTPClient(FTPClient* ftp,const char* path);

//ls
void ls_FTPClient(FTPClient* ftp);

//put
void put_FTPClient(FTPClient* ftp,const char* path);

//get
void get_FTPClient(FTPClient* ftp,const char* path);


#endif//FTP_H
