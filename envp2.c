#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

extern char **environ;

char **_copyenv(void);
void _freeenv(char **env);
char *_getenv(const char *var);

/**
 * _copyenv - Creates a copy of the environment.
 *
 * Return: If an error occurs - NULL.
 *         O/w - a double pointer to the new copy.
 */
char **_copyenv(void)
{
    char **new_env = NULL;
    int index = 0;

    while (environ[index] != NULL)
    {
        index++;
    }

    new_env = malloc(sizeof(char *) * (index + 1));
    if (new_env == NULL)
    {
        perror("Memory allocation error");
        return (NULL);
    }

    for (index = 0; environ[index] != NULL; index++)
    {
        new_env[index] = strdup(environ[index]);

        if (new_env[index] == NULL)
        {
            perror("Memory allocation error");
            for (int j = index - 1; j >= 0; j--)
                free(new_env[j]);
            free(new_env);
            return (NULL);
        }
    }
    new_env[index] = NULL;

    return (new_env);
}

/**
 * _freeenv - Frees the environment copy.
 */
void _freeenv(char **env)
{
    if (env == NULL)
        return;

    for (int index = 0; env[index] != NULL; index++)
    {
        free(env[index]);
    }
    free(env);
}

/**
 * _getenv - Gets an environmental variable from the environment copy.
 * @var: The name of the environmental variable to get.
 *
 * Return: If the environmental variable does not exist - NULL.
 *         Otherwise - a pointer to the environmental variable value.
 */
char *_getenv(const char *var)
{
    int len = strlen(var);

    for (int index = 0; environ[index] != NULL; index++)
    {
        if (strncmp(var, environ[index], len) == 0 && environ[index][len] == '=')
            return &environ[index][len + 1];
    }

    return (NULL);
}
