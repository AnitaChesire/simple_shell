#include "main.h"

void set_env(char **args)
{
    if(args[1] == NULL || args[2] == NULL)
    {
        write(STDERR_FILENO, "setenv: Too few arguments\n", strlen("setenv: Too few arguments\n"));
        return;
    }
    if(args[3] != NULL)
    {
        write(STDERR_FILENO, "setenv: Too many arguments\n", strlen("setenv: Too many arguments\n"));
        return;
    }

    if(setenv(args[1], args[2], 1) != 0)
    {
        perror("setenv");
    }
}

void unset_env(char **args)
{
    if(args[1] == NULL)
    {
        write(STDERR_FILENO, "unsetenv: Too few arguments\n", strlen("unsetenv: Too few arguments\n"));
        return;
    }
    if(args[2] != NULL)
    {
        write(STDERR_FILENO, "unsetenv: Too many arguments\n", strlen("unsetenv: Too many arguments\n"));
        return;
    }

    if(unsetenv(args[1]) != 0)
    {
        perror("unsetenv");
    }
}

