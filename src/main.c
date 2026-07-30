#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define VERSION "1.0.0"
char curcmd[1024];

int main() {
    printf("\nsheL - v%s\nunder GPL-3.0 license\nhttps://github.com/ZIZIES/sheL\n\n", VERSION);

    while (1) {
        printf("%% ");

        fgets(curcmd, sizeof(curcmd), stdin);

        curcmd[strcspn(curcmd, "\n")] = 0;
        if (strcmp(curcmd, "exit") == 0) exit(0);  
        else if (strcmp(curcmd, "clear") == 0) system("clear");
        else {
        pid_t pid = fork();
        if (pid == 0) {
          // child process
          char *args[] = {curcmd, NULL};
          execvp(curcmd, args);
          printf("shel: command not found: %s\n", curcmd);
          exit(1);
        } else {
           // parent waits
           waitpid(pid, NULL, 0);
        }
    }
}
}

