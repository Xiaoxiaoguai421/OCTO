#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>  //网络地址二进制与字符串转换
#include <netinet/in.h> //网络socket地址 sockaddr_in
#include <sys/socket.h> //常用的socket编程函数接口
#include <string.h> //memset()
#include <unistd.h> //close()
#define SOCKET_ERROR -1
#define INVALID_SOCKET -1
#define BUF_SIZE 254

int main()
{
    int sfd =socket(AF_INET,SOCK_STREAM,0);
    if(sfd==INVALID_SOCKET)
    {
        perror("socket()出错!\n");
        exit(-1);
    }
    struct sockaddr_in server;
    memset(&server,0,sizeof (server));
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    server.sin_family=AF_INET;
    server.sin_port=htons(9999);
    printf("向服务器:127.0.0.1 端口号:9999发起连接...\n");
    if(connect(sfd,(struct sockaddr*)&server,sizeof (server))==SOCKET_ERROR)
    {
        perror("connect()出错!\n");
        close(sfd);
        exit(-1);
    }
    printf("连接成功!\n");
    char sbuf[BUF_SIZE];
    char rbuf[BUF_SIZE];
    long int count=0;
    while(1)
    {
        scanf("%s",sbuf);
        if(send(sfd,sbuf,strlen(sbuf),0)==SOCKET_ERROR)
        {
            perror("客户端send()出错!\n");
            close(sfd);
            exit(-1);
        }
        if(strcmp(sbuf,"quit")==0)
            break;
        long len=recv(sfd,rbuf,sizeof (rbuf),0);
        rbuf[len]='\0';
        printf("%ld 客户端接受数据:\n%s",count++,rbuf);
    }
    printf("谢谢!再见!\n");
    close(sfd);
    return 0;
}
