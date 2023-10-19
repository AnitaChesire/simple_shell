#include "main.h"

/**
 * path_func - a function that finds the PATH
 * @cmd : the command to be used to search for path
 * Return: the file PATH
 */


char *path_func(char *cmd)
{
	struct stat path_buffer;
	char *the_path = NULL, *the_path_dup = NULL, *retu = NULL;
	char *the_path_token = NULL, *the_file_path = NULL;

	the_path = getenv("PATH");
	if (the_path != NULL)
	{
		the_path_dup = strdup(the_path);
		if (the_path_dup == NULL)
		{
			exit(EXIT_FAILURE);
		}
		the_path_token = custom_strtok(the_path_dup, ":");
		while (the_path_token != NULL)
		{
			the_file_path = path_builder(the_path_token, cmd);
			if (stat(the_file_path, &path_buffer) == 0) /* if file path exists*/
			{
				retu = strdup(the_file_path);
				if (retu == NULL)
				{
					exit(EXIT_FAILURE);
				}
				free(the_file_path);
				free(the_path_dup);
				return (retu);
			}
			else /* if not exist*/
			{
				free(the_file_path);
				the_file_path = NULL;
				the_path_token = custom_strtok(NULL, ":"); /* find the next dir*/
			}
		}
		if (stat(cmd, &path_buffer) == 0) /* if it is a cmd that already exists*/
		{
			retu = strdup(cmd);
			free(the_path_dup);
			return (retu);
		}
		else
		{
			return (NULL);

		}
	}
	free(the_path_dup);
	return (NULL); /*otherwise if no path is there for cmd*/
}
