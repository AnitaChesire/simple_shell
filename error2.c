#include "shell.h"

char *error_126(char **args);
char *error_127(char **args);

/**
 * error_126 - Creates an error message for permission denied failures.
 */
char *error_126(char **args)
{
	int len;
	char *error;
    char *hist_str;
    
    hist_str = _itoa(hist);
    if (!hist_str)
        return NULL;

    len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 24;
    error = malloc(len + 1);

    if (!error)
    {
        free(hist_str);
        return NULL;
    }

    snprintf(error, len + 1, "%s: %s: %s: Permission denied\n", name, hist_str, args[0]);
    free(hist_str);

    return error;
}

/**
 * error_127 - Creates an error message for command not found failures.
 */
char *error_127(char **args)
{
	char *hist_str;
	int len;
	char *error;

    hist_str = _itoa(hist);
    if (!hist_str)
        return NULL;

    len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 16;
    error = malloc(len + 1);

    if (!error)
    {
        free(hist_str);
        return NULL;
    }

    snprintf(error, len + 1, "%s: %s: %s: not found\n", name, hist_str, args[0]);
    free(hist_str);

    return error;
}

