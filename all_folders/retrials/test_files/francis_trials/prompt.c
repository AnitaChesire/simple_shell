#include "main.h"
#define BUFSIZE 1024
/**
 */
/*function*/

int main(int ac, char **av)
{
	ssize_t command;
	size_t bufsize = 0;
	char *buffer = NULL, *token = NULL;
	int i = 0;
	const char *delim = " \n";
	(void)ac;

	/*function protype for buffer*/
	buffer = malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
	{
		perror("Error: allocating space");
		exit(EXIT_FAILURE);
	}
	
	while (1)
	{
		/*user input*/
		printf("$ ");
		command = getline(&buffer, &bufsize, stdin);
		/*eof or ctrl+d*/
		if (command == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				free(buffer);
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("Error: command error");
				continue;
			}
		}

		if (buffer[command - 1] == '\n')
		{
			buffer[command - 1] = '\0';
		}

		av = malloc(sizeof(char *) * BUFSIZE);
		if (!av)
		{
			perror("error allocating space to av");
			exit(EXIT_FAILURE);
		}

		token = strtok(buffer, delim);
		/*number of tokens determ*/
		while (token != NULL)
		{
			av[i] = token;
			i++;
			token = strtok(NULL, delim);
		}
		av[i] = NULL;

		execmd(av);
		free(av);
		av = NULL;
	}
	free(buffer);
	buffer = NULL;

	return (0);
}
