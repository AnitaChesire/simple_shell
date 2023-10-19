#include "main.h"

void exec(char **argv)
{
	char *command = NULL, *true_cmd = NULL;
	int status;
	char **tokens;

	pid_t pid;
	if (argv)
	{
		/* get the command */
		command = argv[0];
		/* generate the path to this command before passing it to execve */
		if (strcmp(command, "env") == 0)
		{
			env_func();
			return;
		}
		true_cmd = path_func(command);
		if (true_cmd == NULL)
		{
			perror(command);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("Fork error");
		}
		else if (pid == 0)
		{
			if (execve(true_cmd, argv, NULL) == -1)
			{
				/*perror("execve: try again");*/
				exit(EXIT_FAILURE);
			}
		}
		else /* parent process*/
		{
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
			/*if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			{
				fprintf(stderr, "Command '%s' exited with status %d\n", command, WEXITSTATUS(status));
			}*/
		}
	}

}
