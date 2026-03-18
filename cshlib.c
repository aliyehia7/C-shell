#include <stdio.h>
#include "cshlib.h"

void cshlib_help()
{
    printf("\n");
    printf("  built-in commands:\n");
    printf("    help     show this help message\n");
    printf("    clear    clear the terminal screen\n");
    printf("    exit     quit the shell\n");
    printf("\n");
}

void cshlib_clear()
{
    printf("\033[2J\033[H");
    fflush(stdout);
}