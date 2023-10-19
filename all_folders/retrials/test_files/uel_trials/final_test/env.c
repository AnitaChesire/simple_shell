#include "main.h"

extern char **environ;

void env_func()
{
	char **env = environ;
	size_t length = strlen(*env);

	while (*env)
	{
		/*write(STDOUT_FILENO, *env, length);*/
		/*write(STDOUT_FILENO, "\n", 2);*/
		printf("%s\n", *env);
		env++;

	}

}
