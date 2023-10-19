#include "main.h"

/**
 * path_builder - a function to help in building the file path
 * @dir: the directories
 * @command: the command name
 * Return: the file path of the directories
 */


char *path_builder(const char *dir, const char *command)
{
	char *the_file_path = NULL;
	int dir_length, cmd_len;

	dir_length = strlen(dir);

	cmd_len = strlen(command);

	the_file_path = (char *)malloc(dir_length + cmd_len + 2);

	/*building path for the command*/
	/* better than calling strcat and strcpy lots of times*/
	sprintf(the_file_path, "%s/%s", dir, command);

	return (the_file_path);

}


