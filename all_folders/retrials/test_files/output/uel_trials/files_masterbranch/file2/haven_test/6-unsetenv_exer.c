#include "main.h"


int _unsetenv(const char *name)
{
	extern char **environ;
	char **env = environ;
	size_t name_length = strlen(name);
	char **ptr;

	while (*env != NULL)
	{
		if (strncmp(name, *env, name_length) == 0 && (*env)[name_length] == '=')
		{
			/* found the variable now delete it*/

			ptr = env;
			while(*ptr != NULL)
			{
				*ptr = *ptr + 1;
				ptr++;

			}
			return (0);
		}
		env++;

	}
	/* in case variable is not found*/
	return (1);

}
