#include "main.h"

/**
 * env_func -function to display environment
 */

void env_func(void)
{
	char **env = environ;

	while (*env)
	{
		/*write(STDOUT_FILENO, *env, length);*/
		/*write(STDOUT_FILENO, "\n", 2);*/
		printf("%s\n", *env);
		env++;

	}
}
