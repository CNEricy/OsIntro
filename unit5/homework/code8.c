#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd[2];
    int pc = pipe(fd); // create a pipe
    if (pc) {
        fprintf(stderr, "create pipe failed\n");
        return 1;
    }
    
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        char msg[1024];
        sprintf(msg, "written from child (pid:%d)\n", (int)getpid());
        write(fd[1], msg, strlen(msg));
    } else {
        int rc1 = fork();
        if (rc1 < 0) {
            fprintf(stderr, "fork second child failed\n");
            exit(1);
        } else if (rc1 == 0) {
            char rcv[1024];
            read(fd[0], rcv, 1024);
            printf("I am second child (pid:%d), i've received msg from first child: %s", 
            (int)getpid(), rcv);
        } else {
            int wc;
            while ((wc = waitpid(-1, NULL, 0)) && wc != -1) {}
            close(fd[1]);
            close(fd[0]);
        }
    }
}
