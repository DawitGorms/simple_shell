#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

void display_prompt(void)
{
    printf("#cisfun$ ");
}

int main(void)
{
    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS + 1];  /* +1 for NULL termination */
    
    while (1)
    {
        char *token;
        int arg_count = 0;

        display_prompt();
        
        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
        {
            printf("\n");
            exit(0);
        }
        
        command[strcspn(command, "\n")] = '\0';  /* Remove the newline character */
        
        /* Separate command into arguments */
        for (token = strtok(command, " "); token != NULL && arg_count < MAX_ARGUMENTS; token = strtok(NULL, " "), ++arg_count)
        {
            arguments[arg_count] = token;
        }
        arguments[arg_count] = NULL;  /* NULL terminate the arguments array */
{        
   pid_t pid; /* Declare pid_t variable */
}
pid = fork();

if (pid < 0){
  /* Handle error */
} else if (pid == 0) {
  /* Child process code */
} else {
  /* Parent process code */
  /* ... Use pid to access child process information */
}
        {
           fprintf(stderr, "Fork failed\n");
            continue;
        }
        
        else if (pid == 0)
        {
            /* Execute the command with arguments */
            execvp(arguments[0], arguments);
            
            /* If execvp returns, the command was not found */
            fprintf(stderr, "%s: command not found\n", arguments[0]);
            exit(1);
        }
        
        else
        {
            int status;
            waitpid(pid, &status, 0);
        }
    }
    
    return 0;
}
