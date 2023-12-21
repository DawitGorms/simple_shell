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
	write(STDOUT_FILENO, "#cisfun$ ", 10);
}

/**
 * main - Entry point of the command line interpreter.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *command = NULL;
	size_t bufsize = 0;
	pid_t pid;
	int status;

	while (1)
	{
		display_prompt();
		if (getline(&command, &bufsize, stdin) == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			free(command);
			exit(0);
		}
		command[strcspn(command, "\n")] = '\0';
		pid = fork();
		if (pid == 0)
		{
			execute_command(command);
			exit(0);
		}
		else if (pid < 0)
		{
			perror("Fork failed");
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}

	return (0);
}
