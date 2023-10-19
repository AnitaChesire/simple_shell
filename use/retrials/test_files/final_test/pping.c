#include "main.h"
/**
 *
 *
 */
void execute_pipe(char **cm1, char **cm2)
{
	int fd[2];
	pid_t pid;

	if (pipe(fd) == -1)
	{
		perror("Error: couldn't pipe");
		exit(EXIT_FAILURE);
	}

	pid = fork();

	if (pid == -1)
	{
		perror("Couldn't fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);

		if(execve(cm1[0], cm1, environ) == -1)
		{
			perror("Error: execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		pid = fork();

		if (pid == -1)
		{
			perror("Error: forking cmd 2");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);

			if (execve(cm2[0], cm2, environ) == -1)
			{
				perror("Error: execve cm2");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			close(fd[0]);
			close(fd[1]);

			waitpid(pid, NULL, 0);
		}
	}
}

