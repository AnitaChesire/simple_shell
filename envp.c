#include "shell.h"

/**
 * shellby_env - Prints the current environment.
 * @args: An array of arguments passed to the shell.
 *
 * Return: If an error occurs - -1.
 *   Otherwise - 0.
 *
 * Description: Prints one variable per line in the
 *              format 'variable'='value'.
 */
int shellby_env(char **args, char __attribute__((__unused__)) **front)
{
	int index;
	char nc = '\n';

	if (!environ)
		return (-1);

	for (index = 0; environ[index]; index++)
	{
		write(STDOUT_FILENO, environ[index], _strlen(environ[index]));
		write(STDOUT_FILENO, &nc, 1);
	}

	return (0);
}

/**
 * shellby_setenv - Changes or adds an environmental variable to the PATH.
 * @args: An array of arguments passed to the shell.
 * Description: args[0] is the name of the new or existing environment variable.
 *              args[1] is the value to set the new or changed variable to.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 0.
 */
int shellby_setenv(char **args, char __attribute__((__unused__)) **front)
{
	int index, size;
	char **new_environ;
	char **env_var;
	char *new_value;

	if (!args[0] || !args[1])
	{
		return (-1);
	}

	new_value = malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);
	if (!new_value)
	{
		/* Handle memory allocation error*/
		return (-1);
	}

	_strcpy(new_value, args[0]);
	_strcat(new_value, "=");
	_strcat(new_value, args[1]);

	env_var = _getenv(args[0]);
	if (env_var)
	{
		free(*env_var);
		*env_var = new_value;
	}
	else
	{
		/* Add a new environment variable*/
		size = 0;
		while (environ[size] != NULL)
		{
			size++;
		}

		new_environ = malloc(sizeof(char *) * (size + 2));
		if (!new_environ)
		{
			free(new_value);
			return (-1);
		}

		for (index = 0; index < size; index++)
		{
			new_environ[index] = environ[index];
		}

		new_environ[index] = new_value;
		new_environ[index + 1] = NULL;

		free(environ);
		environ = new_environ;
	}

	return (0);
}

/**
 * shellby_unsetenv - Deletes an environmental variable from the PATH.
 * @args: An array of arguments passed to the shell.
 * Description: args[0] is the environment variable to remove.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 0.
 */
int shellby_unsetenv(char **args, char __attribute__((__unused__)) **front)
{
	char **env_var;
	int size, index, index2;
	char **new_environ;

	if (!args[0])
	{
		/* Print an error message or handle the error as needed*/
		return -1;
	}

	env_var = _getenv(args[0]);
	if (env_var)
	{
		/* Remove the environment variable*/
		size = 0;
		while (environ[size] != NULL)
		{
			size++;
		}

		new_environ = malloc(sizeof(char *) * size);
		if (!new_environ)
		{
			return (-1);
		}

		index = 0;
		index2 = 0;

		for (index = 0; index < size; index++)
		{
			if (*env_var == environ[index])
			{
				free(*env_var);
				continue;
			}
			new_environ[index2] = environ[index];
			index2++;
		}

		free(environ);
		environ = new_environ;
		environ[size - 1] = NULL;
	}
	return (0);
}
