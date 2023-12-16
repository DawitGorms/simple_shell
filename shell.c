#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

/**
 * display_prompt - Display the shell prompt
 */
void display_prompt(void)
{
printf("#cisfun$ ");
}

/**
 * main - Entry point
 *
 * Return: Always 0
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

/* Task-specific implementation goes here */

}

return (0);
}
