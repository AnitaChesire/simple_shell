
#include "shell.h"
/**
 * evaluate - A function that runs analysis on args passed to the shell prompt.
 * @args: argument to check for
 * @mytype: a structure created of a certain shell data type.
 * @buffer: Line accepted
 * Return: nothing, upon success. 
 */
void evaluate(char **args, shellinfo_t *mytype, char *buffer)
{
	char *cmd;
	int update;

	if (*args == NULL || args == NULL)
	{
		return;
	}
	cmd = args[0];
	mytype->cmd = cmd;
	if (verify_builtin(mytype, args) == 1)
	{
		return;
	}
	update = is_file(cmd);
	if (update == 0)
	{
		mytype->code_stat = 126;
		mytype->error_digit = 13;
		issue(mytype);
		return;
	}
	if (update == 1)
	{
		run(cmd, args, mytype, buffer);
		return;
	}
	if (get_current_dir(cmd, args, buffer, mytype) == 1)
		return;
	mytype->cmd_path = choose(cmd, mytype);
	if (mytype->cmd_path != NULL)
	{
		run(mytype->cmd_path, args, mytype, buffer);
		release_memory((void *) mytype->cmd_path);
		return;
	}
	mytype->code_stat = 127;
	mytype->error_digit = 132;
	issue(mytype);
}

/**
 * exchange - A function that is built for replacement. 
 * @mytype: a struct called g_t that takes in a pointer
 * @id: index parameter to take note.
 * @word: input words.
 * Return: pointer to a string
*/
char *exchange(shellinfo_t *mytype, int *id, char *word)
{
	char *temp, sign;

	(void) id;

	sign = *word;
	if (sign != '?' && sign != '$')
	{
		temp = sub_env(mytype, word);
		return (temp);
	}

	temp = (sign == '$') ? stringify(mytype->pid) :
		stringify(mytype->code_stat);

	return (temp);
}

