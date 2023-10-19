#include "main.h"
/**
 *fork_child - takes a string argument to be executed by child
 *@buffer: string pointer whose command are executed
 *Return: process id to the parent
 */

pid_t fork_child(char *buffer)
{
	char *av[100];
	pid_t pid = fork();

	/*fork error*/
	if (pid == -1)
	{
		perror("Error: while creating fork");
		exit(EXIT_FAILURE);
	}

	/*child process*/
	else if (pid == 0)
	{
		av[0] = buffer;
		av[1] = NULL;
		if (execve(av[0], av, NULL) == -1)
		{
			perror("error: executing execve");
			free(buffer);
			exit(EXIT_FAILURE);
		}
	}

	/*parent process*/
	else
	{
		return (pid);
	}
	return (0);
}
