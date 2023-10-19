#include "main.h"
/**
 * main - resturns the results of shell cmd 
 * @argc: number of arguments
 * @argv: arg vector
 * Return: 0 on success and -1 on failure
 */

#define MAX_CMD_LEN 1024
#define MAX_ARGS 10
int main(int argc, char **argv)
{
	FILE *fp;
	char *command, *args[MAX_ARGS], *env_path = getenv("PATH");
	char *path_copy = malloc(strlen(env_path) + 1), *token, *cmd_path;
	int cmd_line, i = 0;
	strcpy(path_copy, env_path);

	command = malloc(sizeof(char) * MAX_CMD_LEN);
	/*non interactive mode*/
	if (argc > 1)
	{
		fp = fopen(argv[1], "r");
		if (fp == NULL)
		{
			printf("Error opening file: %s\n", argv[1]);
			exit(1);
		}
		while (fgets(command, MAX_CMD_LEN, fp) != NULL)
		{
			cmd_line = strlen(command);
		       if (command[cmd_line - 1] == '\n')
		       {
			       command[cmd_line - 1] = '\0';
		       }

		       token = strtok(command, " ");
		       
		       while (token != NULL)
		       {
			       args[i] = token;
			       token = strtok(NULL, " ");
			       i++;
		       }

		       /*get cmd path*/
		       args[i] = NULL;
		       cmd_path = get_cmd_path(args[0], path_copy);
		       execute(args, STDIN_FILENO, STDOUT_FILENO);
		       free(cmd_path);


		}
		fclose(fp);
		free(path_copy);
		free(command);
		exit(0);
	}
	else
	{
		/*intereactive mode*/
		while (1)
		{
			printf("$ ");
			fflush(stdout);

			if(fgets(command, MAX_CMD_LEN, stdin) == NULL)
			{
				perror("Exiting");
				free(command);
				free(path_copy);
				exit(EXIT_FAILURE);
			}

			cmd_line = strlen(command);
			if (command[cmd_line - 1] == '\n')
			{
				command[cmd_line - 1] = '\0';
			}

			token = strtok(command, " ");
			i = 0;
			while (token != NULL)
			{
				args[i] = token;
				token = strtok(NULL, " ");
				i++;
			}
			args[i] = NULL;

			if (strcmp(args[0], "cd") == 0)
			{
				if (args[1] == NULL)
				{
					chdir(getenv("HOME"));
				}
				else
				{
					chdir(args[1]);
				}
				continue;
			}
			else if(strcmp(args[0], "exit") == 0)
			{
				free(path_copy);
				free(command);
				exit(0);
			}

			else if(strcmp(args[0], "env") == 0)
			{
				print_env();
				continue;
			}

			else
			{
				cmd_path = get_cmd_path(args[0], path_copy);
				if (cmd_path != NULL)
				{
					execute(args, STDIN_FILENO, STDOUT_FILENO);
				}
				else
				{
					printf("%s: command not found\n", argv[0]);
					continue;
				}
			}
			i = 0;
		}
	}
	free(path_copy);
	free(command);
	return (0);
}
