//
// Created by xhl on 15-6-10.
//

#ifndef TINYWEB_SIG_HANDLER_H
#define TINYWEB_SIG_HANDLER_H

#include "comm_head.h"
#include "error_handling.h"

void sig_handler_ECHILD(int sig) {
    pid_t pid;

    /*
     *  try to reap more sub process if possible.
     *
     */
    while ((pid = Waitpit(-1, NULL, 0)) > 0) {
        printf("Handler reaped child process: %d\n", (int) pid);
    }

    /*
     *  father process do not have any sub process.
     */
    if (errno != ECHILD) {
        unix_error("waitpid error");
    }

    return;
}

#endif //TINYWEB_SIG_HANDLER_H
