#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

void display_prompt()
{
    printf("simple_shell $ ");
}

int main()
{
    char command[MAX_COMMAND_LENGTH];
    pid_t pid;

    while (1)
    {
        display_prompt();

        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
        {
            printf("\n");
            exit(0);
        }

        command[strcspn(command, "\n")] = 0;  /* Remove the newline character */

        pid = fork();

        if (pid < 0)
        {
            fprintf(stderr, "Fork failed\n");
            continue;
        }
        else if (pid == 0)
        {
            if (execlp(command, command, (char *)NULL) == -1)
            {
                fprintf(stderr, "%s: command not found\n", command);
                exit(1);
            }
        }
        else
        {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}
