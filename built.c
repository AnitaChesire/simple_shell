#include "shell.h"
#include <stddef.h>

int (*get_builtin(char *command))(char **args, char **front);
int shellby_exit(char **args, char **front);
int shellby_cd(char **args, char __attribute__((__unused__)) **front);
int shellby_help(char **args, char __attribute__((__unused__)) **front);

/**
 * shellby_exit - Causes normal process termination
 *                for the shellby shell.
 * @args: An array of arguments containing the exit value.
 * @front: A double pointer to the beginning of args.
 *
 * Return: If there are no arguments - -3.
 *         If the given exit value is invalid - 2.
 *         O/w - exits with the given status value.
 *
 * Description: Upon returning -3, the program exits back in the main function.
 */

int shellby_exit(char **args, char **front)
{
	char *endptr;
        long exit_code;

    if (args[0])
    {
        exit_code = strtol(args[0], &endptr, 10);
        if (*endptr != '\0')
        {
            return create_error(args, 2);
        }
        free_args(args, front);
        free_env();
        free_alias_list(aliases);
        exit((int)exit_code);
    }
    else
    {
        return -3;
    }
}

int shellby_cd(char **args, char __attribute__((__unused__)) **front)
{
    char *oldpwd = getcwd(NULL, 0);
    char *dir_info[] = {"OLDPWD", NULL, "PWD", NULL, NULL};  
    char *pwd;

    if (!oldpwd)
    {
        return -1;
    }

    if (args[0])
    {
        if (strcmp(args[0], "--") == 0 || strcmp(args[0], "-") == 0)
        {
            if (_getenv("OLDPWD") != NULL)
            {
                chdir(*(_getenv("OLDPWD") + 7));
            }
        }
        else
        {
            if (chdir(args[0]) != 0)
            {
                free(oldpwd);
                return create_error(args, 2);
            }
        }
    }
    else if (_getenv("HOME") != NULL)
    {
        chdir(*(_getenv("HOME") + 5));
    }

    pwd = getcwd(NULL, 0);

    if (!pwd)
    {
        free(oldpwd);
        return -1;
    }
    dir_info[1] = oldpwd;
dir_info[3] = pwd;

    if (shellby_setenv(dir_info, dir_info) == -1)
    {
        free(oldpwd);
        free(pwd);
        return -1;
    }

    if (args[0] && args[0][0] == '-' && args[0][1] != '-')
    {
        write(STDOUT_FILENO, pwd, _strlen(pwd));
        write(STDOUT_FILENO, "\n", 1);
    }

    free(oldpwd);
    free(pwd);
    return 0;
}

