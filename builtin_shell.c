#include "shell.h"

/**
 * verify_builtin - A function that checks if a given command is a
 * built-in command in the shell.
 * @ourtype: Pointer to a struct containing shell-related information.
 * @args: Array of arguments.
 * Return: 1 if the command is built-in, 0 otherwise.
 */
int verify_builtin(shellinfo_t *ourtype, char **args)
{
	int k, space;

	sysFunction_t builtins[] = {
		{"exit", binary_exit},
		{"env", binary_env}
	};

	space = sizeof(builtins) / sizeof(builtins[0]);
	k = 0;
	while (k < space)
	{
		if (_strcmp(ourtype->cmd, builtins[k].cmd) == 0)
		{
			builtins[k].func(ourtype, args);
			return (1);
		}
		k++;
	}

	return (0);
}

/**
 * system_function - A function assist the user in checking for
 * executable built-ins.
 * @ourtype: a structure with a datatype of info about the shell.
 * @args: The command to be checked.
 * Return: 1 if the command is built-in, 0 otherwise.
 */
int system_function(shellinfo_t *ourtype, char **args)
{
	int check;

	check = verify_builtin(ourtype, args);
	if (check == 0)
	{
		return (0);
	}

	return (1);
}
