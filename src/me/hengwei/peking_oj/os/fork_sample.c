#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int count = 0;
int main()
{
    pid_t pid;
    /* fork a child process */
    pid = fork();
    while(count < 10) {
        if (pid < 0) { /* error occurred */
            fprintf(stderr, "Fork Failed");
            return 1;
        }
        else if (pid == 0 && (count%2 == 0)) { /* child process */
            printf("Child Execute: %d\n", count);
        }
        else if (pid > 0 && (count % 2 == 1)){ /* parent process */
        /* parent will wait for the child to complete */
            printf("Parent Execute: %d\n", count);
        }
        count++;
    }
    return 0;
}
