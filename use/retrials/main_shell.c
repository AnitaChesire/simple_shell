#include "main.h"

/**
 * main - resturns the results of shell cmd 
 * @argc: number of arguments
 * @argv: arg vector
 * Return: 0 on success and -1 on failure
 */

#define MAX_CMD_LEN 100
#define MAX_ARGS 10
int main(int argc, char *argv[])
{
	char *command, *arg, cmd_line[MAX_CMD_LEN], *args[MAX_ARGS + 1];
	FILE *fp;
	int i, interact_mode = 1;
	const char *delim = " ";

	if (argc > 1)
	{
		/*non interactive mode*/
		interact_mode = 0;
		fp = fopen(argv[1], "r");
		if (fp == NULL)
		{
			printf("Error: could not open%s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	}
	while (1)
	{
		if (interact_mode)
		{
			printf("$ ");
		}
		if (fgets(cmd_line, MAX_CMD_LEN, interact_mode ? stdin : fp) == NULL)
		{
			if (interact_mode)
			{
				printf("\n");
			}
			break;
		}
		/*remove new line*/
		cmd_line[strcspn(cmd_line, "\n")] = '\0';

		/*parse com and arg*/
		i = 0;
		command = strtok(cmd_line, delim);
		if (command == NULL)
		{
			continue;
		}
		args[i++] = command;
		while ((arg = strtok(NULL, delim)) != NULL)
		{
			if (i == MAX_ARGS)
			{
				printf("Error: to much args");
				break;
			}
			args[i++] = arg;
		}
		args[i] = NULL;

		execute(command, args);

		if (!interact_mode)
		{
			printf("%s\n", cmd_line);
		}
	}
	if (!interact_mode)
	{
		fclose(fp);
	}
	
	return (EXIT_SUCCESS);
}
