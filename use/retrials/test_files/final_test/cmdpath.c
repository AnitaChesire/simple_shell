#include "main.h"
/**
 *
 */
char *get_cmd_path(char *cmd, char *env_path)
{
	char *token = strtok(env_path, ":");

	while (token != NULL)
	{
		char *cmd_path = malloc(strlen(token) + strlen(cmd) + 2);
		sprintf(cmd_path, "%s%s", token, cmd);

		if (access(cmd_path, X_OK) == 0)
		{
			return (cmd_path);
		}

		free(cmd_path);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
void print_env()
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
