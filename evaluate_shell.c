#include "shell.h"
/**
 * evaluate - A function that runs analysis on args passed to the shell prompt.
 * @args: argument to be checked.
 * @ourtype: a structure created of a certain shell data type.
 * @buffer: Line accepted.
 * Return: nothing, upon success.
 */
void evaluate(char **args, shellinfo_t *ourtype, char *buffer)
{
	char *cmd;
	int update;

	if (*args == NULL || args == NULL)
	{
		return;
	}
	cmd = args[0];
	ourtype->cmd = cmd;
	if (verify_builtin(ourtype, args) == 1)
	{
		return;
	}
	update = is_file(cmd);
	if (update == 0)
	{
		ourtype->code_stat = 126;
		ourtype->error_digit = 13;
		issue(ourtype);
		return;
	}
	if (update == 1)
	{
		run(cmd, args, ourtype, buffer);
		return;
	}
	if (get_current_dir(cmd, args, buffer, ourtype) == 1)
		return;
	ourtype->cmd_path = choose(cmd, ourtype);
	if (ourtype->cmd_path != NULL)
	{
		run(ourtype->cmd_path, args, ourtype, buffer);
		release_memory((void *) ourtype->cmd_path);
		return;
	}
	ourtype->code_stat = 127;
	ourtype->error_digit = 132;
	issue(ourtype);
}
