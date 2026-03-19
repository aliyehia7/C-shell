#include <stdio.h>
#include <unistd.h>
#include "cshlib.h"

void cshlib_help()
{
    printf("\n");
    printf("---- Built-in commands ----\n");
    printf("help      show this help message\n");
    printf("clear     clear the terminal screen\n");
    printf("exit      quit the shell\n");
    printf("pwd       print current directory\n");
    printf("\n");
}

void cshlib_clear()
{
    printf("\033[2J\033[H");
    fflush(stdout);
}

void cshlib_pwd()
{
    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("%s\n", cwd);
    }
    else
    {
        perror("printing of working directory failed.");
    }
}