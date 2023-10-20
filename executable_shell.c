#include "shell.h"
/**
 * is_curr_path - A function that checks how the path is being arranged or examines its order of arrangement.
 * @pat: the path to be checked.
 * @mytype: a shell struct with defined data type.
 * Return: Upon success, nothing. 
 */
void is_curr_path(char *pat, shellinfo_t *mytype)
{
	mytype->cur_path = 0;

	if (pat == NULL)
	{
		return;
	}

	if (pat[0] == ':')
	{
		mytype->cur_path = 1;
	}
}

/**
 * is_executable - A function that checks if a file is executable by using stat function with its filename.
 * @name: The name of the file to be checked. 
 * Return: On success return 1 to indicate that it has the permission.
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
 * @filename: File to check if it has the permission to execute
 * Return: If is a file with the right permission
 * it will
 **/
int isFile(char *filename)
{
	int m, aye;

	aye = _strlen(filename);
	for (m = 0; m < aye; m++)
		if (filename[m] == '/')
		{
			return (is_executable(filename));
		}

	return (-10);
}
