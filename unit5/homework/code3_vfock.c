#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int flag = 0;
    int rc = vfork();
    if (rc < 0) {
        fprintf(stderr, "vfock_failed\n");
        exit(1);
    } else if (rc == 0) {
        if (!flag) {
            // printf("I am child of (pid:%d): hello\n", (int)getpid());
            printf("I am child of %d (pid:%d): hello\n", (int)getppid(), (int)getpid()); // if call getppid() here and do not call _exit(), proc will be blocked
            flag = 1;
            _exit(0); // if do not use this to exit child proc, there will be 2 child procss
        }
    } else {
        while(!flag){}
        printf("I am parent of %d (pid:%d): goodbye\n", rc, (int)getpid());
    }
    return 0;
}