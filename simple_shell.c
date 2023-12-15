#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <simple_shell.h>

#define MAX_COMMAND_LENGTH 100

int main(void);
{
char command[MAX_COMMAND_LENGTH];
char prompt[] = "simple_shell> ";

while (1)
{
printf("%s", prompt);

/* Read the command from the user */
if (fgets(command, sizeof(command), stdin) == NULL)
{
/* Handle end of file condition (Ctrl+D) */
printf("\n");
break;
}

/* Remove the newline character at the end of the command */
command[strcspn(command, "\n")] = '\0';

/* Fork a child process to execute the command */
pid_t pid = fork();

if (pid < 0)
{
/* Error while forking */
fprintf(stderr, "Error forking child process\n");
exit(1);
}
else if (pid == 0)
{
/* Child process */
/* Execute the command */
execlp(command, command, NULL);

/* Execution failed, print error message */
fprintf(stderr, "%s: command not found\n", command);
exit(1);
}
else
{
/* Parent process */
/* Wait for the child process to finish */
int status;
waitpid(pid, &status, 0);
}
}

return (0);
}
