#include "main.h"

void exec(char **argv)
{
	char *command = NULL, *actual_command = NULL;
	int status;
	pid_t pid;
	if (argv)
	{
		/* get the command */
		command = argv[0];
		/* generate the path to this command before passing it to execve */
		actual_command = get_location(command);
		pid = fork();
		if (pid == -1)
		{
			perror("Fork error");
		}
		else if (pid == 0)
		{
			if (execve(actual_command, argv, NULL) == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		else /* parent process*/
		{
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("Error:");
			}
		}
	}

}

