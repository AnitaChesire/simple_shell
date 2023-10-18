#include "shell.h"

int (*get_builtin(char *command))(char **args, char **front);

/**
 * get_builtin - Matches a command with a corresponding
 *               shellby builtin function.
 * @command: The command to match.
 *
 * Return: A function pointer to the corresponding builtin.
 */

int (*get_builtin(char *command))(char **args, char **front)
{
	int i;

	builtin_t funcs[] = {
		{ "exit", shellby_exit },
		{ "env", shellby_env },
		{ "setenv", shellby_setenv },
		{ "unsetenv", shellby_unsetenv },
		{ "cd", shellby_cd },
		{ "alias", shellby_alias },
		{ "help", shellby_help },
		{ NULL, NULL }
	};

	i = 0;

	while (funcs[i].name)
	{
		if (_strcmp(funcs[i].name, command) == 0)
			return funcs[i].f;
		i++;
	}

	return NULL;
}

/**
 * shellby_help - Displays information about shellby builtin commands.
 * @args: An array of arguments.
 * @front: A pointer to the beginning of args.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 0.
 */

int shellby_help(char **args, char __attribute__((__unused__)) **front)
{
	int i;

	struct {
		const char *command;
		void (*help_function)();
	} help_commands[] = {
		{NULL, help_all},
		{"alias", help_alias},
		{"cd", help_cd},
		{"exit", help_exit},
		{"env", help_env},
		{"setenv", help_setenv},
		{"unsetenv", help_unsetenv},
		{"help", help_help},
		{NULL, NULL}
	};

	i = 0;

	while (help_commands[i].command != NULL) {
		if (strcmp(args[0], help_commands[i].command) == 0) {
			help_commands[i].help_function();
			return 0;
		}
		i++;
	}

	write(STDERR_FILENO, name, _strlen(name));
	return 0;
}


