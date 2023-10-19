#include "main.h"

/*
 * main - main function
 */

int main(int ac __attribute__((unused)), char **argv __attribute__((unused)))
{
	char *command = NULL;
	char **tokens = NULL;

	/*simpler code*/
	while (1)
	{
		write(STDOUT_FILENO, "Enter command\n:) ", 18);
		if (commands_reading(&command) == -1)
		{
			perror("exiting now");
			return (-1);
		}
		if (command == NULL)
		{
			continue;
		}
		if (strcmp(command, "exit\n") == 0)
		{ /*here we check if users input from stdin matches "exit"*/
			write(STDOUT_FILENO, "Goodbye\n", 9);
			break; /*exit the loop*/
		}
		tokens = command_tokens(command);
		if (tokens == NULL)
		{
			free(command);
			continue;
		}
		free_the_tokens(tokens);
	}
	free(command);
	return (0);
}


int commands_reading(char **command)
{
	ssize_t total_no_of_chars_read;
	size_t buffer_size= 0;
	/*command = NULL;*/

	total_no_of_chars_read = getline(command, &buffer_size, stdin);

	if (total_no_of_chars_read == -1)
	{
		write(STDOUT_FILENO, "Goodbye from shell\n", 20);
		free(*command);
		return (-1);
	}
	/*free(*command);*/
	return (0);
}
/* the trouble some funtion*/
char **command_tokens(char *command)
{
	char **tokens = NULL;
	char *token, *command_copy = NULL;
	int a = 0;
	const char *delimiter = " \n";
	char **argv;
	int token_amount = 0, allocated_size = 10;
	 /*memory allocation for tokens*/
	tokens = malloc(sizeof(char *) * (allocated_size + 1));
	if (tokens == NULL) 
	{
		perror("error allocating memory for tokens");
		exit(-1);
	}
	command_copy = strdup(command);

	token = custom_strtok(command_copy, delimiter);

	while (token != NULL)
	{
		token_amount++;

		if (token_amount >= allocated_size)
		{
			allocated_size *= 2; /*double the size*/
			tokens = realloc(tokens, sizeof(char *) * allocated_size + 1);
			if (tokens == NULL)
			{
				perror("Error reallocating tokens memory");
				exit(-1);
			}
		}
		tokens[a] = malloc(sizeof(char *) * (strlen(token) + 1));
		strcpy(tokens[a], token);
		token = custom_strtok(NULL, delimiter);
		a++;
	}
	tokens[a] = NULL;
	argv = malloc(sizeof(char *) * (token_amount + 1));
	if (argv == NULL)
	{
		perror("error allocating memory for argv");
		exit(-1);
	}
	for (a = 0; tokens[a] != NULL; a++)
	{
		argv[a] = tokens[a];
	}
	argv[token_amount] = NULL;
	exec(argv);
	free(argv);
	free(command_copy);
	return (tokens);
}

void free_the_tokens(char **tokens)
{
	int a;

	if (tokens == NULL)
	{
		return;
	}

	for (a = 0; tokens[a] != NULL; a++)
	{
		if (tokens[a] != NULL)
		{
			free(tokens[a]);
			tokens[a] = NULL;
		}
	}

	/* freeing memory for the array itself*/

	free(tokens);

}
