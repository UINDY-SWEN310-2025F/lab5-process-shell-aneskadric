#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t fork_return;

    fork_return = fork();

    if (fork_return < 0) {
        fprintf(stderr, "Fork Failed\n");
        return 1;
    } else if (fork_return == 0) {
        execlp("ls", "ls", "-lt", NULL);
        fprintf(stderr, "execlp failed\n");
        return 1;
    } else {
        wait(NULL);
        printf("Child process is done\n");
    }

    return 0;
}