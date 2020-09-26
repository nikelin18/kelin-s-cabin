#include <stdio.h>

#include "ftp.h"


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
void ls_FTPClient(FTPCLient* ftp);

//put
void put_FTPClient(FTPCLient* ftp,const char* path);

//get
void get_FTPClient(FTPCLient* ftp,const char* path);

