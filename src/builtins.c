#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "builtins.h"

int is_builtin(char *cmd) {
    return strcmp(cmd, "exit") == 0 || strcmp(cmd, "clear") == 0 || strncmp(cmd, "cd", 2) == 0;
}

void run_builtin(char *cmd) {
    if (strcmp(cmd, "exit") == 0) exit(0);
    else if (strcmp(cmd, "clear") == 0) system("clear");
    else if (strncmp(cmd, "cd", 2) == 0) {
    char *path = cmd + 3;
    if (chdir(path) != 0) perror("shel: cd");
}
}