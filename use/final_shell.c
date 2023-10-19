#include "main.h"

#define COMMAND_MAX_LENGTH 1024

/**
 * main - main shell program
 * @ac: number of command line arguments
 * @av: an array containing the program command line arguments
 * Return: 0
 */


int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *command = NULL;
	char **command_tokens;
	size_t buffer_size = 0;
	int i_mode = 1;
	char *program_name = av[0];

	while (1)
	{
		i_mode = isatty(STDOUT_FILENO);
		if (i_mode)
		{
			write(STDOUT_FILENO, "", 1);
		}
		if (getline(&command, &buffer_size, stdin) == -1)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}
		if (command[0] == '#')
		{
			continue;
		}
		if (strcmp(command, "exit\n") == 0)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}
		if (strcmp(command, "exit 98\n") == 0)
		{
			free(command);
			exit(98);
		}
		command_tokens = tokenize_command(command);
		i_mode = isatty(STDOUT_FILENO);
		if (!i_mode && command_tokens[0] != NULL
				&& access(command_tokens[0], F_OK) == -1)
		{
			exec(command_tokens, program_name);
			free(command_tokens);
		}
		else if (command_tokens[0] != NULL)
		{
			exec(command_tokens, program_name);
			/*free(command_tokens);*/
		}
<<<<<<< HEAD
		else if (strcmp(command_tokens[0], "cd") == 0)
		{
			if (command_tokens[1] == NULL)
			{
				chdir(getenv("HOME"));
			}
			else if (strcmp(command_tokens[1], "-") == 0)
			{
				char *prev_dir = getenv("OLDPWD");
				if (prev_dir == NULL)
				{
					fprintf(stderr, "cd: OLDPWD not set\n");
				}
				else
				{
					if (chdir(prev_dir) != 0)
					{
						perror("cd");
					}
					else
					{
						printf("%s\n", prev_dir);
					}
				}
			}
			else
			{
				if (chdir(command_tokens[1]) != 0)
				{
					perror("cd");
				}
				else
				{
					setenv("OLDPWD", getenv("PWD"), 1);
					setenv("PWD", getcwd(NULL, 0), 1);
					printf("%s\n", getenv("PWD"));
				}
			}
			continue;
		}

=======
		free(command_tokens);
>>>>>>> 8a4c95a76a21bc33c786373109e8d83126ada94b
	}
	return (0);
}

/**
 * tokenize_command - function to tokenize commands
 * @command: the command to be tokenized
 * Return: fully and well tokenized commands
 */

char **tokenize_command(char *command)
{
	char **command_tokens;
	char *token;
	int q = 0;

	command_tokens = malloc(sizeof(char *) * COMMAND_MAX_LENGTH);

	if (command_tokens == NULL)
	{
		perror("malloc failed from tokenize_command");
		exit(EXIT_FAILURE);
	}
	token = custom_strtok(command, " \n");

	while (token != NULL)
	{
		command_tokens[q++] = token;
		token = custom_strtok(NULL, " \n");
	}
	command_tokens[q] = NULL;

	return (command_tokens);


}
