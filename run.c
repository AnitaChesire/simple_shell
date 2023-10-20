#include "shell.h"
/**
 * run - A function that executes a command in another process called child.
 * @cmd: The command to execute is passed and received here.
 * @argu: Arguments passed to the command.
 * @ourtype: a struct of the shell info.
 * @buffer: Line counter.
 * Return: nothing upon success.
 */
void run(char *cmd, char **argu, shellinfo_t *ourtype, char *buffer)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(cmd, argu, environ);
		perror("./sh");

		release_memory_pointer((void *) argu);

		if (ourtype->cmd_path != NULL)
		{
			free(ourtype->cmd_path);
			ourtype->cmd_path = NULL;
		}

		free(ourtype);
		free(buffer);
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			ourtype->code_stat = WEXITSTATUS(status);
		}
	}
}
