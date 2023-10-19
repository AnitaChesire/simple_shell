#include "main.h"

/**
 * path_func - a function that finds the PATH
 * @cmd : the command to be used to search for path
 * Return: the file PATH
 */


char *path_func(char *cmd)
{
	struct stat path_buffer;
	char *the_path = NULL, *the_path_dup = NULL;
	char *the_path_token = NULL, *the_file_path = NULL;

	the_path = getenv("PATH");

	if (the_path != NULL)
	{
		the_path_dup = strdup(the_path);

		the_path_token = custom_strtok(the_path_dup, ":");

		while (the_path_token != NULL)
		{
			the_file_path = path_builder(the_path_token, cmd);
			/* if file path exists*/
			if (stat(the_file_path, &path_buffer) == 0)
			{
				free(the_path_dup);
				return (the_file_path);
			}
			else /* if not exist*/
			{
				free(the_file_path);
				the_file_path = NULL;
				/* find the next dir*/
				the_path_token = custom_strtok(NULL, ":");
			}

		}
		/* if it is a cmd that already exists*/
		if (stat(cmd, &path_buffer) == 0)
		{
			return (cmd);
		}
		free(the_path_dup);
	}
	/*otherwise if no path is there for cmd*/
	return (NULL);
}
