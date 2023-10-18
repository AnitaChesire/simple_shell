#include "shell.h"

char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);

/**
 * error_env - Creates an error message for shellby_env errors.
 */
char *error_env(char **args)
{
	char *error;
char *hist_str;
int len;

hist_str = _itoa(hist);

    if (!hist_str)
        return NULL;

    len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 45;
    error = malloc(len + 1);

    if (!error)
    {
        free(hist_str);
        return NULL;
    }

    snprintf(error, len + 1, "%s: %s: %s: Unable to add/remove from environment\n", name, hist_str, args[0]);
    free(hist_str);

    return error;
}

/**
 * error_1 - Creates an error message for shellby_alias errors.
 */
char *error_1(char **args)
{
    int len = _strlen(name) + _strlen(args[0]) + 13;
    char *error = malloc(len + 1);

    if (!error)
        return NULL;

    snprintf(error, len + 1, "alias: %s not found\n", args[0]);

    return error;
}

/**
 * error_2_exit - Creates an error message for shellby_exit errors.
 */
char *error_2_exit(char **args)
{
	char *error;
char *hist_str;
int len;

hist_str = _itoa(hist);
    if (!hist_str)
        return NULL;

    len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 27;
    error = malloc(len + 1);

    if (!error)
    {
        free(hist_str);
        return NULL;
    }

    snprintf(error, len + 1, "%s: %s: exit: Illegal number: %s\n", name, hist_str, args[0]);
    free(hist_str);

    return error;
}

/**
 * error_2_cd - Creates an error message for shellby_cd errors.
 */
char *error_2_cd(char **args)
{
	char *type;
	int len;
	char *error;
	char *hist_str;

    hist_str = _itoa(hist);

    if (!hist_str)
        return NULL;

    type = (args[0][0] == '-') ? "cd: Illegal option" : "cd: can't cd to";
    len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 24;
    error = malloc(len + 1);

    if (!error)
    {
        free(hist_str);
        return NULL;
    }

    snprintf(error, len + 1, "%s: %s: %s %s\n", name, hist_str, type, args[0]);
    free(hist_str);

    return error;
}

/**
 * error_2_syntax - Creates an error message for syntax errors.
 */
char *error_2_syntax(char **args)
{
	char *error;
char *hist_str;
int len;

hist_str = _itoa(hist);

    if (!hist_str)
        return NULL;

    len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 33;
    error = malloc(len + 1);

    if (!error)
    {
        free(hist_str);
        return NULL;
    }

    snprintf(error, len + 1, "%s: %s: Syntax error: \"%s\" unexpected\n", name, hist_str, args[0]);
    free(hist_str);

    return error;
}

