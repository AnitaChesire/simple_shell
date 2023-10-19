#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "main.h"


/**
 * int _setenv - sets a new env variable
 * @name: pointer environment name
 * @value: pointer to new value
 * @overwrite: the new value
 * Retrun: 0
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	char *new_env, *existing_name;
	size_t nm_len, vl_len;

	/*check if the name variable exists*/
	existing_name = getenv(name);

	if (existing_name != NULL && overwrite == 0)
	{
		return (-1);
	}

	else if (existing_name != NULL && overwrite == 1)
	{
		free(existing_name);
		return (0);
	}

	/*assigning new values*/
	nm_len = strlen(name);
	vl_len = strlen(value);

	new_env = (char *) malloc(nm_len + vl_len + 2);
	if (new_env == NULL)
	{
		return (-1);
	}

	else
	{
		/*copy name into new env*/
		strcpy(new_env, name);
		new_env[nm_len] = '=';
		strcpy(new_env + nm_len + 1, value);

		/*add new env*/
		putenv(new_env);
	}
		return (0);

}
