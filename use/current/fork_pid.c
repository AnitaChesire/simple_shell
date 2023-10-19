#include "main.h"

void execute(char **args, char **envp)
{
	pid_t pid;
	int pipepath[2], status;

	if (pipe(pipepath) == -1)
	{
		perror("Error: Pipping");
		exit(EXIT_FAILURE);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("error: fork");
		exit(EXIT_FAILURE);
	}

	else if (pid == 0)
	{
		close(pipepath[0]);
		if (dup2(pipepath[1], STDOUT_FILENO) == -1)
		{
			perror("Error: error duplicate file descriptor");
			exit(EXIT_FAILURE);
		}
		close(pipepath[1]);
		if (execve(args[0], args, environ) == -1)
		{
			perror("error: execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		close(pipepath[1]);
		pipe_rd(pipepath[0], envp);
		
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("Waitpid");
			exit(EXIT_FAILURE);
		}
	}
}
