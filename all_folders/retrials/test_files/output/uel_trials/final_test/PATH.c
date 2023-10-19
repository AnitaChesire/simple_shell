#include "main.h"

/**
 * path_func- function that searches for a command in the PATH environment
 *
 */

char *path_func(const char *command)
{
	char *the_path, *file_path;
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
		file_path = join((char *[]) {the_directories[q],
				(char *)command, NULL}, "/");
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
	/* free memory used by the_directories array*/
	for(q = 0; the_directories[q] != NULL; q++)
	{
		free(the_directories[q]);
	}
	/* check if command is absolute path and return if it exists*/
	if (access(command, X_OK) == 0)
	{
		return (strdup(command));
	}
	free(the_directories);

	return (NULL);
}
