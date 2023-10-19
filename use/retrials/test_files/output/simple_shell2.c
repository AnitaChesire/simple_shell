#include "main.h"
/**
 *main - prints results of shell cmd entered by user
 *@args: pointer array for holding commands
 *Return: if successful 0, and unsuccessful -1
 */
int main(int ac __attribute__((unused)), char *args[])
{
	size_t bufsize = 100;
	char *buffer, *token, *argv[100], *delim = " ";
	ssize_t prompt;
	int status, i = 0, executed_execve = 0;
	pid_t pid;

	buffer = malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
	{
		perror("Error: Allocating space");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		printf("$ ");
		prompt = getline(&buffer, &bufsize, stdin);

		if (prompt == EOF)
		{
			perror("end of line");
			free(buffer);
			exit(EXIT_FAILURE);
		}
		token = strtok(buffer, delim);
		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		pid = fork();
		if (pid == -1)
		{
			perror("Error: fork");
			free(buffer);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error: unsuccessful in execve");
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
			if (!executed_execve)
			{
				system(buffer);
			}
			else
			{
				executed_execve = 0;
			}
		}
	}
	free(buffer);
	return (0);
}
