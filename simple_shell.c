#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

/**
 * display_prompt - Display the shell prompt.
 */
void display_prompt(void)
{
	printf("simple_shell $ ");
}

/**
 * main - Entry point of the command line interpreter.
 *
 * Return: Always 0.
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		display_prompt();
		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			printf("\n");
			exit(0);
		}

		command[strcspn(command, "\n")] = '\0';  /* Remove the newline character */

		if (strcmp(command, "exit") == 0)
			exit(0);

		pid_t pid = fork();

		if (pid < 0)
		{
			fprintf(stderr, "Fork failed\n");
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
			int status;
			waitpid(pid, &status, 0);
		}
	}

	return (0);
}
