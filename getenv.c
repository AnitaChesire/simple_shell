#include "shell.h"
/**
 * fetch_full_env - A function that helps user get all the environme
 * ts variables.
 * Return: nothing, upon success.
 */
void fetch_full_env(void)
{
	int k = 0;
	char **temp;

	for (k = 0, temp = environ; temp[k] != NULL; k++)
	{
		display(temp[k]);
		write_character('\n');
	}
}

/**
 * get_env - A function that assists users in getting an environment variable.
 * @variable: the environment variable to get.
 * Return: If (successful) {printf(name of var)} else{return (NULL)}
 */
char *get_env(const char *variable)
{
	char **enviro, *aux, *tok, *mob;
	int siz;

	siz = _strlen((char *) variable);

	for (enviro = environ; *enviro; ++enviro)
	{
		aux = _strdup(*enviro);

		tok = strtok(aux, "=");
		if (tok == NULL)
		{
			free(aux);
			return (NULL);
		}

		if (_strlen(tok) != siz)
		{
			free(aux);
			continue;
		}
		if (_strcmp((char *) variable, aux) == 0)
		{
			tok = strtok(NULL, "=");
			mob = _strdup(tok);
			free(aux);
			return (mob);
		}
		free(aux);
	}
	return (NULL);
}
