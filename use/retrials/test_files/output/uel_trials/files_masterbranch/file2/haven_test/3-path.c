#include "main.h"

/**
 * path_file - prints out the path of the current dir
 */

int path_func_3()
{
	char *buffer, *dir;
	const char *delimiter = " : ";

	/*path dec*/
	buffer = getenv("PATH");

	if (buffer == NULL)
	{
		fprintf(stderr, "no dir path found");
		exit(0);
	}

	else
	{
		dir = _strtok(buffer, delimiter);
		while (dir != NULL)
		{
			printf("%s\n", dir);
			dir = _strtok(NULL, delimiter);
		}
	}
	return (0);

}
