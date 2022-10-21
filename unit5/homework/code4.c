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
        char *myargs[3];
        myargs[0] = strdup("/bin/ls");
        myargs[1] = strdup("-l");
        myargs[2] = NULL;
        execv("/usr/bin/", myargs);
    } else {
        int wc = wait(NULL);
    }

    return 0;
}