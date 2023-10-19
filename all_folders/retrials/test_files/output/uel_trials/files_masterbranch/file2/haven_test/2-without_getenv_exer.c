#include "main.h"


char *_getenv(const char *name)
{
	extern char **environ;
	char **env = environ;
	size_t name_length = strlen(name);

	while ( *env != NULL)
	{
		if (strncmp( name, *env, name_length) == 0 && (*env)[name_length] == '=')
		{
			/* use of + 1 to skip over the equals in Name=Value format*/
			return (&(*env)[name_length + 1]);



		}
		env++;

	}
	return (NULL);




}
