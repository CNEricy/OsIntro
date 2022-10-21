#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 100;
    printf("x is %d\n", x);

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("I am child (pid:%d), x is %d, ", (int)getpid(), x); 
        x = 101;
        printf("and i changed x into %d\n",  x);
    } else {
        printf("I am parent of %d (pid:%d), i'm waiting for my child finished. ", rc, (int)getpid());

        int wc = wait(NULL);
        printf("Now, my child finished, it's my turn. x is %d, ", x);
        x = 110;
        printf("and i changed x into %d\n", x);
    }
    
    return 0;
}
