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
    }
}

