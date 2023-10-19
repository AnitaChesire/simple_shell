#include "main.h"

/**
 * path_func- function that searches for a command in the PATH environment
 *@command: the command to be looked for
 *Return: file path
 */

char *path_func(const char *command)
{
	char *the_path, *file_path, *path_args[3];
	char **the_directories;
	int q, r;

	the_path = getenv("PATH");
	if (the_path == NULL)
	{
		return (NULL);
	}
	the_directories = split_func(the_path, ":");
	for (q = 0; the_directories[q] != NULL; q++)
	{
		path_args[0] = the_directories[q];
		path_args[1] = (char *)command;
		path_args[2] = NULL;
		file_path = join(path_args, "/");
		/* if file exists it returns*/
		if (access(file_path, X_OK) == 0)
		{ /*free memory used by the_directories array*/
			for (r = 0; the_directories[r] != NULL; r++)
			{
				free(the_directories[r]);
			}
			free(the_directories);
			return (file_path);
		}
		free(file_path);
	}
	for (q = 0; the_directories[q] != NULL; q++)
	{
		free(the_directories[q]);
	}
	/* check if command is absolute path and return if it exists*/
	if (access(command, X_OK) == 0)
	{
		free(the_directories);
		return (strdup(command));
	}
	free(the_directories);
	return (NULL);
}
