#include "main.h"

int cd_func(char *argv[])
{
	char *home_dir = getenv("HOME");
	char *current_dir = getcwd(NULL, 0);
	char *previ_dir = getenv("OLDPWD");

	if (argv[0] == NULL || strcmp(argv[0], "~") == 0)
	{
		chdir(home_dir);
	}

	if (strcmp(argv[0], "-" ) == 0)
	{
		if (previ_dir == NULL)
		{
			perror("Error in getting the previous directory OLDPWD not set");
			exit(EXIT_FAILURE);
		}
		chdir(previ_dir);
		printf("%s\n", previ_dir);
	}
	else /* change dir to the path specified*/
	{
		if (chdir(argv[0]) == -1)
		{
			perror("error in cd");
			exit(EXIT_FAILURE);
		}
	}

	setenv("PWD", current_dir, 1);
	setenv("OLDPWD", current_dir, 1);
	free(current_dir);
	return (0);

}
