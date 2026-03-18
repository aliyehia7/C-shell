#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cshlib.h"

#define MAX_INPUT 1024  // max characters per input line
#define MAX_ARGS 64     // max number of arguments

/* splits the input string into an array of tokens separated by spaces */
char **splitInp(char *input)
{
    char **args = malloc(MAX_ARGS * sizeof(char *));

    if (args == NULL)
    {
        perror("memory allocation failed.");
    }

    int i = 0;

    char *token = strtok(input, " ");

    while (token != NULL && i < MAX_ARGS - 1)
    {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }

    args[i] = NULL;  // null-terminate the args array
    return args;
}

/* checks if the command is a built-in and runs it, returns 1 if handled, 0 if not */
int run_cshlib(char **args)
{
    if (args[0] == NULL)
    {
        return 0;
    }

    if (strcmp(args[0], "help") == 0)
    {
        cshlib_help();
        return 1;
    }

    if (strcmp(args[0], "clear") == 0)
    {
        cshlib_clear();
        return 1;
    }

    return 0;
}

int main()
{
    char input[MAX_INPUT];

    while (1)
    {
        printf("> ");
        fflush(stdout);

        /* exit on EOF (e.g. Ctrl+D) */
        if (fgets(input, MAX_INPUT, stdin) == NULL)
        {
            printf("\n");
            exit(0);
        }

        input[strcspn(input, "\n")] = '\0';  // strip trailing newline

        if (strcmp(input, "exit") == 0)
        {
            exit(0);
        }

        char **args = splitInp(input);

        /* run built-in if matched, otherwise treat as external command */
        if (run_cshlib(args) == 0)
        {
            printf("external command: %s (not yet implemented)\n", args[0]);
        }

        free(args);
    }

    return 0;
}
