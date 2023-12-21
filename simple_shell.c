#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 256

/**
 * display_prompt - Display the shell prompt.
 */
void display_prompt(void)
{
    printf("#cisfun$ ");
}

int main(void)
{
    pid_t pid;
    char *command = NULL;
    size_t bufsize = 0;
    int status;

    while (1)
    {
        display_prompt();

        if (getline(&command, &bufsize, stdin) == -1)
        {
            printf("\n");
            free(command);
            exit(0);
        }

        command[strcspn(command, "\n")] = '\0'; /* Remove the newline character */

        pid = fork();

        if (pid < 0)
        {
            perror("Fork failed");
            continue;
        }
        else if (pid == 0)
        {
            if (execlp(command, command, NULL) == -1)
            {
                fprintf(stderr, "%s: command not found\n", command);
                exit(1);
            }
        }
        else
        {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}
