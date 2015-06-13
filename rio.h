//
// Created by xhl on 15-5-13.
//

#ifndef TINYWEB_RIO_H
#define TINYWEB_RIO_H

#include "comm_head.h"

/*
 *  IO function of read and write without buffer.
 */
ssize_t rio_readn(int fd, void *usrbuf, size_t n) {
    size_t nleft = n;
    ssize_t nread;
    char *bufp = (char *) usrbuf;
    while (nleft > 0) {
        if ((nread = read(fd, bufp, nleft)) < 0) {
            if (errno == EINTR) {   //  will call rio_readn() again.
                nread = 0;  /*  Interrupted by  sig handler return  */
            }
            else {
                return -1;  /*  errno set by read() */
            }
        } else if (0 == nread) {
            break;  // EOF
        }
        nleft -= nread;
        bufp += nread;
    }
    return n - nleft;
}

ssize_t rio_writen(int fd, char *usrbuf, size_t n) {
    size_t nleft = n;
    ssize_t nwriten;
    char *bufp = (char *) usrbuf;
    while (nleft > 0) {
        if ((nwriten = write(fd, bufp, nleft)) < 0) {
            if (errno == EINTR) {
                nwriten = 0;
            }
            else {
                return -1;
            }
        }
        nleft -= nwriten;
        usrbuf += nwriten;
    }
    return n;
}


/*
 *  IO function with buffer.
 */
#define RIO_BUFFER_SIZE 8192
typedef struct {
    int rio_fd;
    int rio_cnt;
    char *rio_bufptr;
    char rio_buf[RIO_BUFFER_SIZE];
} rio_t;

void rio_readinitb(rio_t *rp, int fd) {
    rp->rio_fd = fd;
    rp->rio_cnt = 0;
    rp->rio_bufptr = rp->rio_buf;
}


ssize_t rio_read(rio_t *rp, char *usrbuf, size_t n) {
    int cnt;
    while (rp->rio_cnt <= 0) {
        rp->rio_cnt = read(rp->rio_fd, rp->rio_buf, RIO_BUFFER_SIZE);
        if (rp->rio_cnt < 0) {
            if (errno != EINTR) {
                return -1;
            }
        } else if (0 == rp->rio_cnt) {
            return 0;
        } else {
            rp->rio_bufptr = rp->rio_buf;
        }
    }

    cnt = n < (rp->rio_cnt) ? n : rp->rio_cnt;
    memcpy(usrbuf, rp->rio_bufptr, cnt);
    rp->rio_bufptr += cnt;
    rp->rio_cnt -= cnt;
    return cnt;
}

ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen) {
    int n, rc;
    char c, *bufp = (char *) usrbuf;
    for (n = 1; n < maxlen; ++n) {
        if ((rc = rio_read(rp, &c, 1)) == 1) {
            *bufp = c;
            bufp++;
            if ('\n' == c) {
                break;
            }
        }
        else if (0 == rc) {
            if (1 == n)
                return 0;
            else
                break;
        } else {
            return -1;
        }
    }
    *bufp = '\0';
    return n;
}

ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n) {
    size_t nleft = n;
    ssize_t nread;
    char *bufp = (char *) usrbuf;
    while (nleft > 0) {
        if ((nread = rio_read(rp, bufp, nleft)) < 0) {
            if (errno == EINTR)
                nread = 0;
            else
                return -1;
        }
        else if (0 == nread) {
            break;
        }
        nleft = nleft - nread;
        bufp = bufp + nread;
    }
    return n - nleft;
}




#endif //TINYWEB_RIO_H
