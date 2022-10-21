#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        int wc = wait(NULL);
        printf("I am child (pid:%d), wc = %d\n", (int)getpid(), wc);
    } else {
        int wc = wait(NULL);
        printf("I am parent of %d (pid:%d), wc = %d\n", rc, (int)getpid(), wc);
    }

    return 0;
}