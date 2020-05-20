#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main() {

    char command[BUFSIZ];
    int status;
    pid_t pid;

    for (;;) {
        printf("shell: ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            printf("\n");
            return 0;
        }
        command[strlen(command) - 1] = '\0';
        if ((pid = fork()) == 0)
            execlp(command, command, 0);
        while (wait(&status) != pid)
            continue;
        printf("\n");
    }
    return 0;
}


