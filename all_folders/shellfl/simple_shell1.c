#include "main.h"
/**
 * main - prints out the results of the user input shell cmd
 * @argc: no of arguments in a argv
 * @argv: array pointer for argc
 * Return - 0 on success and non-sero on failure
 */
int main(int argc, char **argv)
{
	char *buffer, *av[100];
	size_t bufsize = 100;
	int status, executed_execve = 0;
	ssize_t prompt;
	pid_t pid;
	(void)argc, (void)argv;

	buffer = malloc(sizeof(char) * bufsize);

	if (buffer == NULL)
	{
		perror("Error: Allocating malloc");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		printf("$ ");
		prompt = getline(&buffer, &bufsize, stdin);

		if (prompt == EOF)
		{
			printf("end of file\n");
			free(buffer);
			exit(EXIT_FAILURE);
		}

		buffer[strcspn(buffer, "\n")] = '\0';

		exit_status(buffer);

		pid = fork();
		if (pid == -1)
		{
			perror("Error: while creating fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			av[0] = buffer;
			av[1] = NULL;
			if( execve(av[0], av, NULL) == 1)
		
			{
				perror("error: executing execve");
				free(buffer);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS)
			{
				executed_execve = 1;
			}
		}
		if (!executed_execve)
		{
			system(buffer);
		}
		else
		{
			executed_execve = 0;
		}
	}
	free(buffer);
	return (0);
}
