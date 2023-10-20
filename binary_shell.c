#include "shell.h"
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
