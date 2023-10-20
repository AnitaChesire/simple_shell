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

/**
 * binary_env - A function that helps in the implementation of the
 * builtin of the env.
 * @ourtype: the shell struct.
 * @args: the command passed to the shell eng.
 * Return: Nothing upon success.
 */
void binary_env(shellinfo_t *ourtype, char **args)
{
	(void) ourtype;
	(void) args;

	fetch_full_env();
}

/**
 * binary_exit - A function that helps user exit the shell env.
 * @ourtype: the shell struct.
 * @args: argument passed to the shell.
 * Return: void or nothing, upon success.
 */
void binary_exit(shellinfo_t *ourtype, char **args)
{
	int stat, status_sh;

	stat = 1;
	if (args[1] != NULL)
	{
		stat = handle_numbers(ourtype, args[1]);
	}

	if (stat == 0)
	{
		return;
	}

	status_sh = ourtype->code_stat;

	release_memory_pointer((void **) args);
	release_memory((void *) ourtype->buf);
	release_memory((void *) ourtype->env);
	release_memory((void *) ourtype);

	exit(status_sh);
}
