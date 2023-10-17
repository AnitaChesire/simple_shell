#include "shell.h"

char *get_args(char *line, int *exe_ret);
int call_args(char **args, char **front, int *exe_ret);
int run_args(char **args, char **front, int *exe_ret);
int handle_args(int *exe_ret);
int check_args(char **args);

/**
 * get_args - Get command from standard input.
 * @line: to store the command.
 * @exe_ret: The return value of the last executed command.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the stored command.
 */

char *get_args(char *line, int *exe_ret)
{
    size_t n = 0;
    ssize_t read;
    char *prompt = "$ ";

    if (line)
    {
        free(line);
        line = NULL; // Set to NULL after freeing to avoid double free
    }

    while (1)
    {
        read = _getline(&line, &n, STDIN_FILENO);

        if (read == -1)
            return NULL;

        if (read > 1)
            break;

        hist++;
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, prompt, 2);
    }

    line[read - 1] = '\0';
    variable_replacement(&line, exe_ret);
    handle_line(&line, read);

    return line;
}
int call_args(char **args, char **front, int *exe_ret)
{
    int ret = 0;
    char *op = NULL;

    while (args && *args)
    {
        op = *args;

        if (_strncmp(op, "||", 2) == 0 || _strncmp(op, "&&", 2) == 0)
        {
            args++;
            args = replace_aliases(args);
            ret = run_args(args, front, exe_ret);

            if ((_strncmp(op, "||", 2) == 0 && *exe_ret == 0) || (_strncmp(op, "&&", 2) == 0 && *exe_ret != 0))
                break;
        }
        else
        {
            args = replace_aliases(args);
            ret = run_args(args, front, exe_ret);
            break;
        }
    }

    free_args(args, args);
    return ret;
}

int run_args(char **args, char **front, int *exe_ret)
{
    int ret = 0;
    int (*builtin)(char **args, char **front);

    builtin = get_builtin(args[0]);

    if (builtin)
    {
        ret = builtin(args + 1, front);
        if (ret != EXIT)
            *exe_ret = ret;
    }
    else
    {
        *exe_ret = execute(args, front);
        ret = *exe_ret;
    }

    hist++;
    free_args(args, args);
    return ret;
}

int handle_args(int *exe_ret)
{
    int ret = 0;
    char **args, *line = NULL, **front;

    line = get_args(line, exe_ret);
    if (!line)
        return END_OF_FILE;

    args = _strtok(line, " ");
    free(line);
    if (!args)
        return ret;

    if (check_args(args) != 0)
    {
        *exe_ret = 2;
        free_args(args, args);
        return *exe_ret;
    }

    front = args;
    ret = call_args(args, front, exe_ret);
    free(front);
    return ret;
}



