#include "shell.h"
/**
 * is_curr_path - A function that checks how the path is being
 * arranged or examines its order of arrangement.
 * @pat: the path to be checked.
 * @ourtype: a shell struct with defined data type.
 * Return: Upon success, nothing.
 */
void is_curr_path(char *pat, shellinfo_t *ourtype)
{
	ourtype->cur_path = 0;

	if (pat == NULL)
	{
		return;
	}

	if (pat[0] == ':')
	{
		ourtype->cur_path = 1;
	}
}

/**
 * is_executable - A function that checks if a file is executable by
 * using stat function with its filename.
 * @name: The name of the file to be checked.
 * Return: On success return 1 to indicate that it has the permission
 * On error -1 is returned showing that it has no permission.
 */
int is_executable(char *name)
{
	struct stat stats;

	if (stat(name, &stats) == 0)
	{
		if (stats.st_mode & X_OK)
		{
			return (1);
		}
		else
		{
			return (-1);
		}
	}

	return (-1);
}

/**
 * is_file - A function that checks if a particular name is a file or binary.
 * @file_name: File to check if it has the permission to execute
 * Return: 1 If is a file with the right permission, else -1.
 */
int is_file(char *file_name)
{
	int m, ego;

	ego = _strlen(file_name);
	for (m = 0; m < ego; m++)
		if (file_name[m] == '/')
		{
			return (is_executable(file_name));
		}

	return (-1);
}
