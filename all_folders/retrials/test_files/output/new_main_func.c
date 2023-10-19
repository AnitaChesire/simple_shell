#include "main.h"

/**
 * main - main function
 * @ac: the number of command line arguments
 * @argv: an array containing the program command line argumnets
 * Return: 0
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
			free(command);
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

/**
 * commands_reading - a function that reads user's command
 * @command: the command entered by user
 * Return: 0
 */

int commands_reading(char **command)
{
	ssize_t total_no_of_chars_read;
	size_t buffer_size = 0;
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
/**
 * command_tokens - function to tokenize commands entered by user
 * @command: the command to be tokenized
 * Return: a tokenized token
 */

/* the trouble some funtion*/
char **command_tokens(char *command)
{
	char **tokens = NULL, **argv;
	char *token, *command_copy = NULL;
	int a = 0, token_amount = 0, allocated_size = 10;
	const char *delimiter = " \n";

	tokens = malloc(sizeof(char *) * (allocated_size + 1));
	if (tokens == NULL)
	{
		return(NULL);
	}
	command_copy = strdup(command);
	token = custom_strtok(command_copy, delimiter);
	while (token != NULL)
	{
		token_amount++;
		if (token_amount >= allocated_size)
		{
			allocated_size *= 2;
			tokens = realloc(tokens, sizeof(char *) * allocated_size + 1);
			if (tokens == NULL)
			{
				free(command_copy);
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
		free(command_copy);
	for (a = 0; tokens[a] != NULL; a++)
		argv[a] = tokens[a];
	argv[token_amount] = NULL;
	exec(argv);
	free(argv);
	free(command_copy);
	return (tokens);
}

/**
 *free_the_tokens - function that frees all memory already allocated
 *@tokens: the tokens whose memory is to be freed
 */
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
