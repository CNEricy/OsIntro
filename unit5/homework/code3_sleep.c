#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "vfock_failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("I am child (pid:%d): hello\n", (int)getpid());
    } else {
        sleep(1);
        printf("I am parent of %d (pid:%d): goodbye\n", rc, (int)getpid());
    }
    return 0;
}