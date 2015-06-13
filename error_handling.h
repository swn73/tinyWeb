//
// Created by xhl on 15-5-13.
//

#ifndef TINYWEB_ERROR_HANDLING_H
#define TINYWEB_ERROR_HANDLING_H


#include"comm_head.h"
#include"rio.h"

void unix_error(const char *msg)
{
    fprintf(stderr,"%s: %s\n",msg,strerror(errno));
}

pid_t Fork(void)
{
    pid_t pid;

    if((pid=fork())<0)
    {
        unix_error("fork error");
    }
    return pid;
}

ssize_t Rio_readn(int fd, void *usrbuf, size_t n)
{
    ssize_t nread;
    if((nread=rio_readn(fd,usrbuf,n))<0)
    {
        unix_error("rio_readn error");
    }
    return nread;
}

ssize_t Rio_writen(int fd, char *usrbuf, size_t n)
{
    ssize_t  nwrite;
    if((nwrite=rio_writen(fd,usrbuf,n))<0)
    {
        unix_error("rio_writen error");
    }
}

ssize_t Rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen)
{
    ssize_t  nread;
    if((nread=rio_readlineb(rp,usrbuf,maxlen))<0)
    {
        unix_error("rio_readlineb error");
    }
    return nread;
}

ssize_t Rio_readnb(rio_t *rp, void *usrbuf, size_t n)
{
    ssize_t nread;
    if((nread=rio_readnb(rp,usrbuf,n))<0)
    {
        unix_error("rio_readnb error");
    }
    return nread;
}
int Open(char *filename,int flags,mode_t mode)
{
    int fd;
    if((fd=open(filename,flags,mode))<0)
    {
        unix_error("open error");
    }
    return fd;
}

int Close(int fd)
{
    int close_state;

    if((close_state=close(fd))<0)
    {
        unix_error("close error");
    }
    return close_state;
}

int Dup2(int oldfd,int newfd)
{
    int dup2_state;

    if((dup2_state=dup2(oldfd, newfd))<0)
    {
        unix_error("dup2 error");
    }
    return dup2_state;
}

int Execve(char *filename,char *argv[],char* envp[])
{
    int state;

    if((state=execve(filename,argv,envp))<0)
    {
        unix_error("execve error");
    }
    return state;
}
int Wait(int *status)
{
    pid_t state;

    if((state=wait(status))<0)
    {
        unix_error("wait error");
    }
    return state;
}

pid_t Waitpit(pid_t pid,int *status,int options)
{
    pid_t return_pid;

    if((return_pid=waitpid(pid,status,options))<0)
    {
        unix_error("waitpid error");
    }
    return return_pid;
}

sighandler_t Signal(int signum,sighandler_t hander)
{
    if(SIG_ERR==signal(signum,hander))
    {
        fprintf(stderr,"signal error\n");
        return SIG_ERR;
    }
    return hander;
}





#endif //TINYWEB_ERROR_HANDLING_H
