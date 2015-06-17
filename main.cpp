#include"core.h"
#include"sig_handler.h"

void doit(int fd);

int listenfd, connfd, port;

int main(int argc, char **argv) {

    /*
     *  set handler function of signal : SIGCHLD
     */
    Signal(SIGCHLD,sig_handler_ECHILD);


    socklen_t clientlen;
    struct sockaddr_in clientaddr;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }
    port = atoi(argv[1]);

    listenfd = open_listenfd(port);
    while (1) {
        clientlen = sizeof(clientaddr);
        connfd = accept(listenfd, (SA *) &clientaddr, &clientlen);
        doit(connfd);
    }
}

void doit(int fd) {
    int is_static;
    struct stat sbuf;
    char buf[MAXLINE], method[MAXLINE], uri[MAXLINE], version[MAXLINE];
    char filename[MAXLINE], args[MAXLINE];
    rio_t rio;

    rio_readinitb(&rio, fd);
    Rio_readlineb(&rio, buf, MAXLINE);
    sscanf(buf, "%s %s %s", method, uri, version);
    if (strcasecmp(method, "GET")) {
        client_error(fd, method,
                     "501",
                     "Not Implemented",
                     "Tiny Web does not implement this method");
        return;
    }
    read_request_head(&rio);

    is_static = parse_uri(uri, filename, args);
    if (stat(filename, &sbuf) < 0) {
        client_error(fd, filename,
                     "404",
                     "Not Found",
                     "Tiny Web couldn't find this file");
        return;
    }

    if (is_static) {
        if (!(S_ISREG(sbuf.st_mode)) || !(S_IRUSR & sbuf.st_mode)) {
            client_error(fd, filename,
                         "403",
                         "Forbidden",
                         "Tiny Web could't read this file");
            return;
        }
        serve_static(fd, filename, sbuf.st_size);
    }
    else {
        if (!(S_ISREG(sbuf.st_mode)) || !(S_IXUSR & sbuf.st_mode)) {
            client_error(fd, filename,
                         "403",
                         "Forbidden",
                         "Tiny Web could't run target program");
            return;
        }
        serve_dynamic(fd,filename,args);
    }
}