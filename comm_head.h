//
// Created by xhl on 15-5-13.
//

#ifndef TINYWEB_COMM_HEAD_H
#define TINYWEB_COMM_HEAD_H


#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>

#define MAXLINE 1024
#define MAXBUF 8192
#define LISTENQ 1024

typedef struct sockaddr SA;

#endif //TINYWEB_COMM_HEAD_H
