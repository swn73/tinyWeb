//
// Created by xhl on 15-5-13.
//

#ifndef TINYWEB_CORE_H
#define TINYWEB_CORE_H


#include"error_handling.h"
#include"rio.h"
#include"comm_head.h"

extern int listenfd;

int open_clientfd(char *hostname, int port) {
    int clientfd;
    struct hostent *hp;
    struct sockaddr_in serveraddr;

    if ((clientfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return -1;
    }
    if ((hp = gethostbyname(hostname)) == NULL) {
        return -2;
    }
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *) hp->h_addr_list[0],
          (char *) &serveraddr.sin_addr.s_addr, hp->h_length);
    serveraddr.sin_port = htons(port);

    if (connect(clientfd, (SA *) &serveraddr, sizeof(serveraddr)) < 0) {
        return -1;
    }
    return clientfd;
}


int open_listenfd(int port) {
    int listenfd, optval = 1;
    struct sockaddr_in serveraddr;

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return -1;
    }

    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR,
                   (const void *) &optval, sizeof(int)) < 0) {
        return -1;
    }

    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons((unsigned short) port);
    if (bind(listenfd, (SA *) &serveraddr, sizeof(serveraddr)) < 0) {
        return -1;
    }

    if (listen(listenfd, LISTENQ)) {
        return -1;
    }
    return listenfd;
}

void client_error(int fd, char *cause, const char *errnum,
                  const char *shortmsg, const char *longmsg) {
    char buf[MAXLINE], body[MAXBUF];
    // 构造 HTTP response body.
    sprintf(body, "<html><title>TinyWeb Error</title>");
    sprintf(body, "%s<body bgcolor=\"ffffff\">\r\n", body);
    sprintf(body, "%s %s:%s\r\n", body, errnum, shortmsg);
    sprintf(body, "%s<p>%s:%s\r\n", body, longmsg, cause);
    sprintf(body, "%s<hr><em>The TinyWeb Server</em>\r\n", body);
    // 向客户端打印 HTTP response.
    sprintf(buf, "HTTP/1.0 %s %s\r\n", errnum, shortmsg);
    Rio_writen(fd, buf, strlen(buf));
    sprintf(buf, "Content-type:text/html\r\n");
    Rio_writen(fd, buf, strlen(buf));
    sprintf(buf, "Content-length:%d\r\n\r\n", (int) strlen(body));
    Rio_writen(fd, buf, strlen(buf));
    Rio_writen(fd, body, strlen(body));
    return;
}

void read_request_head(rio_t *rp)
{
    char buf[MAXLINE];

    Rio_readlineb(rp,buf,MAXLINE);
    while(strcmp(buf,"\r\n")){
        Rio_readlineb(rp,buf,MAXLINE);
        printf("%s",buf);
    }
    return;
}

int parse_uri(char *uri,char *filename,char *args)
{
    char *ptr;

    if(!strstr(uri,"bin"))
    {
        strcpy(args,"");
        strcpy(filename,".");
        strcat(filename,uri);

        if(uri[strlen(uri)-1]=='/')
        {
            strcat(filename,"home.html");
            return 1;
        }
        else{
            ptr=index(uri,'?');
            if(ptr!=NULL)
            {
                strcpy(args,ptr+1);
                *ptr='\0';
            }
            else{
                strcpy(args,"");
            }
            strcpy(filename,".");
            strcat(filename,uri);
            return 0;
        }
    }
}
void get_filetype(char *filename,char *filetype)
{
    if(strstr(filename,".html"))
    {
        strcpy(filetype,"text/html");
    }else if(strstr(filename,".gif"))
    {
        strcpy(filetype,"image/gif");
    }else if(strstr(filename,".jpg"))
    {
        strcpy(filetype,"image/jpg");
    }else{
        strcpy(filetype,"text/plain");
    }
    return;
}

void serve_static(int fd,char *filename,int filesize)
{
    int srcfd;
    char *srcp,filetype[MAXLINE],buf[MAXBUF];

    get_filetype(filename,filetype);
    sprintf(buf,"HTTP/1.0 200 OK\r\n");
    sprintf(buf,"%sServer: Tiny Web Server\r\n",buf);
    sprintf(buf,"%sContent-length:%d\r\n",buf,filesize);
    sprintf(buf,"%sContent-Type:%s\r\n\r\n",buf,filetype);
    Rio_writen(fd,buf,strlen(buf));

    if(Fork()==0)
    {
        close(listenfd);
        srcfd=Open(filename,O_RDONLY,0);
        srcp=(char*)malloc(filesize);
        Rio_readn(srcfd,srcp,filesize);
        Rio_writen(fd,srcp,filesize);
        free(srcp);
    }
    close(fd);
    return;
}
void serve_dynamic(int fd,char *filename,char *args)
{
    char buf[MAXLINE],*emptylist[]={NULL};

    sprintf(buf,"HTTP/1.0 200 OK\r\n");
    Rio_writen(fd,buf,strlen(buf));
    sprintf(buf,"Server: Tiny Web Server\r\n");
    Rio_writen(fd,buf,strlen(buf));

    if(Fork()==0)
    {
        close(listenfd);
        setenv("QUERY_STRING",args,1);
        Dup2(fd,STDOUT_FILENO);
        Execve(filename,emptylist,environ);
    }
    close(fd);
}

#endif //TINYWEB_CORE_H
