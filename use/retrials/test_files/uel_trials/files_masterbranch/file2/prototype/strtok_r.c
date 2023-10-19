#include "main.h"


char *strtok_r_func()
{
	char *buffer = NULL;
	char *commands[10], *token = NULL, *saveptr = NULL, *command;
	int num_commands;
	int a;

	while (1)
	{
		/* split line into commands*/
		token = strtok_r(buffer, ";", &saveptr);
		while (token != NULL && num_commands < 10)
		{
			commands[num_commands++] = token;
			token = strtok_r(NULL, ";", &saveptr);
		}
		for (a = 0; a < num_commands; a++) /*execute each command*/
		{
			command = trim(commands[a]);
			system(command);
		}
	}

	return (buffer);

}
