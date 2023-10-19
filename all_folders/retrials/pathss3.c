#include "main.h"

/**
 * sspath - finds the path of the and check if cmd exits
 */

char *sspath(char *command)
{
	struct stat st;
	char *path_line, *ret, *directory, *path = NULL;

	/*dec and env*/
	path_line = getenv("PATH");
	ret = strdup(path_line);
	directory = strtok(ret, ":");

	if (ret == NULL)
	{
		perror("Error: strdup didnt work");
		exit(EXIT_FAILURE);
	}

	while (directory != NULL)
	{
		path = malloc(strlen(directory) + strlen(command) + 2);
		sprintf(path, "%s%s", directory, command);
		if (stat(path, &st) == 0)
		{
			free(ret);
			return (path);
		}
		free(path);
		directory = strtok(NULL, ":");
	}
	free(ret);
	return NULL;

}
