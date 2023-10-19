#include "main.h"
/**
 * execute - executes the cmd that users enter
 * @command: for non interactive mode
 * @argv: arguments entered by user
 */

void execute(char **args, int input_fd, int output_fd)
{
	pid_t pid;
	int status, flags, pipefd[2], saved_stdout = dup(STDOUT_FILENO), saved_stdin = dup(STDIN_FILENO), i = 0;
	if (pipe(pipefd) == -1)
	{
		perror("pipe error");
		exit(EXIT_FAILURE);
	}
	
	while (args[i] != NULL)
	{
		if (strcmp(args[i], "<") == 0)
		{
			input_fd = open(args[i + 1], O_RDONLY);
			if (input_fd == -1)
			{
				perror("open error");
				exit(EXIT_FAILURE);
			}
			args[i] = NULL;
		}
		
		else if (strcmp(args[i], ">") == 0 || strcmp(args[i], ">>") == 0)
		{
			flags = O_WRONLY | O_CREAT;

			if (strcmp(args[i], ">>") == 0)
			{
				flags |= O_APPEND;
			}
			else
			{
				flags |= O_TRUNC;
			}

			output_fd = open(args[i + 1], flags, 0666);
			if (output_fd == -1)
			{
				perror("open error");
				exit(EXIT_FAILURE);
			}
			args[i] = NULL;
		}
		else if (strcmp(args[i], "|") == 0)
		{
			args[i] = NULL;
			if (dup2(pipefd[1], STDOUT_FILENO) == -1)
			{
				perror("dup2 error");
				exit(EXIT_FAILURE);
			}
			else if (close(pipefd[1]) == -1)
			{
				perror("close error");
				exit(EXIT_FAILURE);
			}
			
			execute(args, input_fd, STDOUT_FILENO);
			
			if (close(pipefd[0]) == -1)
			{
				perror("close error");
				exit(EXIT_FAILURE);
			}
			if (dup2(saved_stdout, STDOUT_FILENO) == -1)
			{
				perror("dup2 error");
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
	/*fork*/
	
	pid = fork();
	
	if (pid < 0)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/*Child process*/
		if (input_fd != STDIN_FILENO)
		{
			if (dup2(input_fd, STDIN_FILENO) == -1)
			{
				perror("dup2 error");
				exit(EXIT_FAILURE);
			}
		}
		if (output_fd != STDOUT_FILENO)
		{
			if (dup2(output_fd, STDOUT_FILENO) == -1)
			{
				perror("dup2 error");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror("execvp error");
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		do{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		
		if (dup2(saved_stdin, STDIN_FILENO) == -1)
		{
			perror("dup2 error");
			exit(EXIT_FAILURE);
		}
		
		else if (input_fd != STDIN_FILENO)
		{
			if (close(input_fd) == -1)
			{
				perror("close error");
				exit(EXIT_FAILURE);
			}
		}
		else if (output_fd != STDOUT_FILENO)
		{
			if (close(output_fd) == -1)
			{
				perror("close error");
				exit(EXIT_FAILURE);
			}
		}
	}
}
