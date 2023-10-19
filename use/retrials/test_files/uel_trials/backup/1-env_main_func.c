#include "main.h"

/*
 * main - main function
 */

int main()
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	char *commands[10], *token = NULL, *command;
	int num_commands;
	int a;

	/*simpler code*/
	while (1)
	{
		num_commands = 0;

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
		buffer = handle_comments(buffer);
		{
			if (buffer == NULL)
			{
				continue;
			}

		}
		/* split line into commands*/
		token = custom_strtok(buffer, ";");
		while (token != NULL && num_commands < 10)
		{
			commands[num_commands++] = token;
			token = custom_strtok(NULL, ";");
		}
		for (a = 0; a < num_commands; a++) /*execute each command*/
		{
			command = trim(commands[a]);
			execute_command(command);
		}
	}
	free(buffer);
	return (0);
}
