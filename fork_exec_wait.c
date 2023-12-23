#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
    pid_t child_pid;
    int status;
    int i;

    for (i = 0; i < 5; i++)
    {
        child_pid = fork();
        if (child_pid == -1)
        {
            perror("Error in fork");
            return 1;
        }
        else if (child_pid == 0)
        {
            execve(argv[0], argv, NULL);
            perror("Error in execve");
            return 1;
        }
    }

    for (i = 0; i < 5; i++)
    {
        wait(&status);
    }

    return 0;
}
