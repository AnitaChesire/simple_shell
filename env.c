#include "main.h"
#include <unistd.h>

/**
 * env_func - function to display environment
 */
void env_func(void)
{
    char **env = environ;

    while (*env)
    {
        write(STDOUT_FILENO, *env, strlen(*env));
        write(STDOUT_FILENO, "\n", 1);
        env++;
    }
}

