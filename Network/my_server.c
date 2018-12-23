#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <ctype.h>
#include <unistd.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define BUF_SIZE 254
int count(const char* s)
{
    int cc=0;
    for(size_t i=0; s[i]!='\0'; i++)
    {
        if(isalpha( s[i]))
        {
            cc++;
        }
    }
    return cc;
}
int main(void)
{
    int sfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sfd == INVALID_SOCKET)
    {
        perror("socket()出错");
        exit(-1);
    }

    //server准备
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(9999);
    if (bind(sfd, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
    {
        perror("bind()出错");
        close(sfd);
        exit(-1);
    }
    if (listen(sfd, 5) == SOCKET_ERROR)
    {
        perror("bind()出错");
        close(sfd);
        exit(-1);
    }
    printf("tcp服务器程序在端口号:9999上等待连接......\n");

    // clien连接
    struct sockaddr_in client;
    unsigned len = sizeof(client);
    int cfd = accept(sfd, (struct sockaddr *)&client, &len);
    if (cfd == SOCKET_ERROR)
    {
        perror("accept()出错\n");
        close(sfd);
        exit(-1);
    }
    printf("客户机IP:%s 端口号:%d 已经连接进来!\n", inet_ntoa(client.sin_addr),
           ntohs(client.sin_port));

    //业务处理
    char rbuf[BUF_SIZE];
    char sbuf[BUF_SIZE];
    int cc = 0;
    while(1)
    {
        long len=recv(cfd,rbuf,sizeof (rbuf),0);
        if(len<=0)
        {
            perror("recv()出错\n");
            close(sfd);
            close(cfd);
            exit(-1);
        }
        rbuf[len]='\0';
        if(strcmp(rbuf, "quit")==0)
            break;
        cc=count(rbuf);
        sprintf(sbuf,"数据:%s 长度:%d\n",rbuf,cc);
        if(send(cfd,sbuf,strlen(sbuf),0)==SOCKET_ERROR)
        {
            perror("send()出错!\n");
            close(sfd);
            close(cfd);
            exit(-1);
        }
    }
    printf("谢谢!再见!\n");

    close(sfd);
    close(cfd);

    return 0;
}
