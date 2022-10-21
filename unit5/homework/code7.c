#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    close(STDOUT_FILENO);
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        int i;
        for (i = 1000; i >= 0; i--) {
            printf("I am child (pid:%d) %d\n", (int)getpid(), i);
        }
    } else {
        int i;
        for (i = 1000; i >= 0; i--) {
            printf("I am parent of %d (pid:%d) %d\n", rc, (int)getpid(), i);
        }
    }

    return 0;
}