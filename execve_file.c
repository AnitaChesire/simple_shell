#include "main.h"

/**
 * exec - function that executes a command
 * @argv: an array containing the program command line arguments
 * @program_name: the name of the program
 */

void exec(char **argv, char *program_name)
{
	char *cmd = NULL, *true_cmd = NULL;
	int line_num = 1, a, cs, the_pipefd[2]; /*current_state;*/ 
	pid_t pid;
	char buffer [1024];

	if (argv)
	{
		cmd = argv[0];
		if (strcmp(cmd, "env") == 0)
		{
			env_func();
			return;
		}

		else if (strcmp(cmd, "setenv") == 0)
		{
			if (argv[1] == NULL || argv[2] == NULL || argv[3] != NULL)
			{
				fprintf(stderr, "%s: %d: usage: setenv VARIABLE VALUE\n", program_name, line_num);
				return;
			}
			if (setenv(argv[1], argv[2], 1) == -1)
			{
				perror("error in setenv");
				return;
			}
			return;
		}
		else if (strcmp(cmd, "unsetenv") == 0)
		{
			if (argv[1] == NULL || argv[2] != NULL)
			{
				fprintf(stderr, "%s: %d: usage: unsetenv VARIABLE\n", program_name, line_num);
				return;
			}
			if (unsetenv(argv[1]) == -1)
			{
				perror("There is an error in unsetenv");
				return;
			}
			return;
		}
		true_cmd = path_func(cmd);
		if (true_cmd == NULL)
		{
			fprintf(stderr, "%s: %d: %s: not found\n", program_name, line_num, argv[0]);
			exit(2);
		}
		pipe(the_pipefd);

		pid = fork();
		if (pid == -1) /* child process failure*/
		{
			perror("There is an error in pid");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			close(the_pipefd[0]);
			dup2(the_pipefd[1], STDOUT_FILENO);
			close(the_pipefd[1]);
			if (execve(true_cmd, argv, environ) == -1)
			{
				fflush(stdout);
				exit(2);
			}

		}
		else
		{  /* parent process*/
			close(the_pipefd[1]);
			while((a = read(the_pipefd[0], buffer, sizeof(buffer))) > 0)
			{
				write(STDOUT_FILENO, buffer, a);

			}
			if (waitpid(pid, &cs, 0) == -1)
			{
				perror("waitpid");
				exit(WEXITSTATUS(cs));
			}
			else if (WIFSIGNALED(cs))
			{
				WEXITSTATUS(cs);
				
			}
		}
	}
	free(true_cmd);
}
