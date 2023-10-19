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
			free(command);
			free_the_tokens(tokens);
			return (-1);
		}
		write(STDOUT_FILENO, "", 0);
		write(STDOUT_FILENO, command, strlen(command));

		if (strcmp(command, "exit\n") == 0)
		{ /*here we check if users input from stdin matches "exit"*/
			write(STDOUT_FILENO, "Goodbye\n", 9);
			break; /*exit the loop*/
		}
		tokens = command_tokens(command);
		free_the_tokens(tokens);
		free(command);

	}
	return (0);
}


int commands_reading(char **command)
{
	ssize_t total_no_of_chars_read;
	size_t buffer_size= 0;
	*command = NULL;

	total_no_of_chars_read = getline(command, &buffer_size, stdin);
	command = malloc(sizeof(char) * buffer_size);

	if (total_no_of_chars_read == -1)
	{
		write(STDOUT_FILENO, "Goodbye from shell\n", 20);
		return (-1);
	}

	/*command_copy = malloc(sizeof(char) * total_no_of_chars_read);
	if (command_copy == NULL)
	{
		perror("error allocating command_copy memory");
		return (-1);
	}
	strcpy(command_copy, total_no_of_chars_read);*/

	return (0);
}

char **command_tokens(char *command)
{
	char **tokens = NULL;
	char *token;
	int a = 0;
	const char *delimiter = " \n";
	char **argv;
	int token_amount = 0;
	char *command_path;
	/* memory allocatiohn for tokens*/
	tokens = malloc(sizeof(char *) * (token_amount + 1));
	if (tokens == NULL) 
	{
		perror("error allocating memory for tokens");
		exit(-1);
	}

	token = custom_strtok(command, delimiter);

	while (token != NULL)
	{
		token_amount++;
		tokens[a] = malloc(sizeof(char) * (strlen(token) + 1));
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
	for (int a = 0; a < token_amount; a++)
	{
		argv[a] = tokens[a];
	}
	argv[token_amount] = NULL;
	exec(argv);
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
		free(tokens[a]);
	}

	/* freeing memory for the array itself*/

	free(tokens);

}
