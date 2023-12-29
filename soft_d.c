#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point for the simple shell
 * Return: Always 0
 */
int main(void)
{
    char *input;

    while (1)
    {
        printf("$ ");
        input = NULL;

        /* Read a line from the user */
        size_t len = 0;
        getline(&input, &len, stdin);

        /* Check for end of file */
        if (feof(stdin))
        {
            printf("\n");
            free(input);
            exit(EXIT_SUCCESS);
        }

        /* Remove the newline character */
        input[len - 1] = '\0';

        /* Execute the command (for now, just print it) */
        printf("Executing: %s\n", input);

        free(input);
    }

    return 0;
}

