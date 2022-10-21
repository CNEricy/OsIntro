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
        int wc = waitpid(-1,NULL,0);
        printf("I am child (pid:%d), wc = %d\n", (int)getpid(), wc);
        exit(0);
    } else {
        int rc1 = fork();
        if (rc1 < 0) {
            fprintf(stderr, "fork failed\n");
            exit(1);
        } else if (rc1 == 0) {
            printf("I am second child (pid:%d)\n", (int)getpid());
            exit(0);
        } else {
            int wc;
            while ((wc = waitpid(-1, NULL, 0)) && wc != -1) { // be careful in the priority of '=' and '&&'
                printf("I am parent (pid:%d) wc = %d\n", (int)getpid(), wc);
            }
        }
    }

    return 0;
}