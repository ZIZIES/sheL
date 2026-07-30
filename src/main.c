#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define VERSION "1.0.0"

char curcmd[1024];

int main() {
    // startup banner
    printf("\nsheL - v%s\nunder GPL-3.0 license\nhttps://github.com/ZIZIES/sheL\n\n", VERSION);

    while (1) {
        printf("%% ");

        // read input
        fgets(curcmd, sizeof(curcmd), stdin);
        curcmd[strcspn(curcmd, "\n")] = 0; // strip newline

        // builtins
        if (strcmp(curcmd, "exit") == 0) exit(0);
        else if (strcmp(curcmd, "clear") == 0) system("clear");
        else {
            // parse args
            char *args[64];
            int i = 0;
            char *token = strtok(curcmd, " ");
            while (token != NULL && i < 63) {
                args[i++] = token;
                token = strtok(NULL, " ");
            }
            args[i] = NULL;

            // fork and exec
            pid_t pid = fork();
            if (pid == 0) {
                // child
                execvp(args[0], args);
                printf("shel: command not found: %s\n", args[0]);
                exit(1);
            } else {
                // parent waits
                waitpid(pid, NULL, 0);
            }
        }
    }
}