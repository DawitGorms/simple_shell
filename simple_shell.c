#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 512
#define PROMPT "#cisfun$ "

int execute_command(char *command)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1)
    {
        perror("Fork failed");
        return -1;
    }
    else if (pid == 0)
    {
        if (execlp(command, command, NULL) == -1)
        {
            fprintf(stderr, "Error: Command not found\n");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
    }

    return (0);
}

int main(void)
{
    char command[BUFFER_SIZE];

    while (1)
    {
        printf(PROMPT);

        if (fgets(command, BUFFER_SIZE, stdin) == NULL)
            break;

        command[strcspn(command, "\n")] = '\0';  /* remove trailing newline */

        if (execute_command(command) == -1)
            break;
    }

    return (0);
}
