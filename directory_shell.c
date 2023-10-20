#include "shell.h"
/**
 * choose - A function built for finding directories when it's needed.
 * @dirname: directory name inputted
 * @ourtype: A struct that defines a certain shell info type.
 * Return: pointer to the string of the path to the directory
 */
char *choose(char *dirname, shellinfo_t *ourtype)
{
	char *path, *path_temp, *tokn, *del;
	int space;

	(void) ourtype;

	path = get_env("PATH");
	if (path == NULL)
	{
		return (NULL);
	}

	tokn = strtok(path, ":");

	space = _strlen(dirname) + 2;
	del = malloc(space * sizeof(char));
	del = _strcpy(del, "/");
	del = _strcat(del, dirname);

	while (tokn != NULL)
	{
		path_temp = malloc(_strlen(tokn) + space);
		path_temp = _strcpy(path_temp, tokn);
		path_temp = _strcat(path_temp, del);

		if (is_executable(path_temp) == 1)
		{
			free(path);
			free(del);
			return (path_temp);
		}
		tokn = strtok(NULL, ":");

		free(path_temp);
	}

	free(del);
	free(path);

	return (NULL);
}

/**
 * get_current_dir - A function that helps user execute a command if
 * the order requires.
 * @command: Command to be executed is passed here.
 * @argu: Argument passed with the command is done here
 * @buff: Line readed or the buffer received.
 * @ourtype: a struct that contains general info about the shell
 * Return: a number which equates the status of the program
 */
int get_current_dir(char *command, char **argu, char *buff,
shellinfo_t *ourtype)
{

	if (ourtype->cur_path == 0)
	{
		return (0);
	}

	if (is_executable(command) == 1)
	{
		run(command, argu, ourtype, buff);
		return (1);
	}

	return (0);
}
