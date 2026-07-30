#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "executor.h"

void execute(char *cmd) {
    char *args[64];
    int i = 0;
    char *token = strtok(cmd, " ");
    while (token != NULL && i < 63) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    pid_t pid = fork();
    if (pid == 0) {
        execvp(args[0], args);
        printf("shel: command not found: %s\n", args[0]);
        exit(1);
    } else {
        waitpid(pid, NULL, 0);
    }
}