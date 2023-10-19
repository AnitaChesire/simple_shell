#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - tests if _setenv works
 */

int set_environ_func()
{
	int new_results = _setenv("MY_ENV_VAR", "new environment", 1);

	if (new_results == 0)
	{
		printf("Environment variable set is successful\n");
	}
	else
	{
		printf("Error setting new environment var\n");
	}
	return (0);
}
