#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUF_SIZE 1024

int main(void);
{
char *prompt = "#cisfun$ ";
char command[BUF_SIZE];

while (1)
{
printf("%s", prompt);
if (fgets(command, BUF_SIZE, stdin) == NULL)
{
printf("\n");
break;
}

command[strcspn(command, "\n")] = '\0'; /* Remove trailing newline character */

/* Variable declaration before any executable statement in ISO C90 style*/
pid_t pid;
pid = fork();
if (pid == -1)
{
perror("fork");
return (1);
}
else if (pid == 0)
{
if (execlp(command, command, NULL) == -1)
{
perror(command)
return (1);
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
