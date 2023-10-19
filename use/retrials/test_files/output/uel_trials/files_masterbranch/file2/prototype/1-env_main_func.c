#include "main.h"

/*
 * main - main function
 */

char *command()
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	/*char *commands[10], *token = NULL, *saveptr = NULL, *command;*/
	/*int num_commands;*/
	/*int a;*/

	/*simpler code*/
	while (1)
	{
		/*num_commands = 0;*/

		printf("Enter command\n:) ");

		if (getline(&buffer, &buffer_size, stdin) == -1)
		{
			break;
		}
		if (strcmp(buffer, "exit\n") == 0)
		{ /*here we check if users input from stdin matches "exit"*/
			printf("Exiting the simple shell...\n");
			printf("Goodbye\n");
			break; /*exit the loop*/
		}
		*strtok_r_func();
		/* split line into commands
		token = strtok_r(buffer, ";", &saveptr);
		while (token != NULL && num_commands < 10)
		{
			commands[num_commands++] = token;
			token = strtok_r(NULL, ";", &saveptr);
		}
		for (a = 0; a < num_commands; a++)   execute each command
		{
			command = trim(commands[a]);
			system(command);
		}*/
	}
	free(buffer);
	return (buffer);
}
