#include "main.h"

/**
 * exec - function that executes a command
 * @argv: an array containing the program command line arguments
 * @program_name: the name of the program
 */

void exec(char **argv, char *program_name)
{
	char *true_cmd;
	pid_t pid;
	char buffer[1024];
        ssize_t a;
	int cs;

    if (argv == NULL || argv[0] == NULL)
    {
        fprintf(stderr, "%s: command not found\n", program_name);
        return;
    }

    if (strcmp(argv[0], "env") == 0)
    {
        env_func();
        return;
    }
    else if (strcmp(argv[0], "setenv") == 0)
    {
        if (argv[1] == NULL || argv[2] == NULL || argv[3] != NULL)
        {
            fprintf(stderr, "Usage: %s VARIABLE VALUE\n", program_name);
            return;
        }
        if (setenv(argv[1], argv[2], 1) == -1)
        {
            perror("Error in setenv");
            return;
        }
        return;
    }
    else if (strcmp(argv[0], "unsetenv") == 0)
    {
        if (argv[1] == NULL || argv[2] != NULL)
        {
            fprintf(stderr, "Usage: %s VARIABLE\n", program_name);
            return;
        }
        if (unsetenv(argv[1]) == -1)
        {
            perror("Error in unsetenv");
            return;
        }
        return;
    }

  	true_cmd = path_func(argv[0]);
    if (true_cmd == NULL)
    {
        fprintf(stderr, "%s: %s: not found\n", program_name, argv[0]);
        exit(2);
    }

      if (pipe(the_pipefd) == -1)
    {
        perror("Error creating a pipe");
        free(true_cmd);
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1)
    {
        perror("Error forking a child process");
        free(true_cmd);
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        
        close(the_pipefd[0]);
        dup2(the_pipefd[1], STDOUT_FILENO);
        close(the_pipefd[1]);
        if (execve(true_cmd, argv, environ) == -1)
        {
            perror("Error in execve");
            free(true_cmd);
            exit(2);
        }
    }
    else
    {
        
        close(the_pipefd[1]);
        
    	while ((a = read(the_pipefd[0], buffer, sizeof(buffer)) > 0)
        {
            write(STDOUT_FILENO, buffer, a);
        }


        if (waitpid(pid, &cs, 0) == -1)
        {
            perror("waitpid");
            free(true_cmd);
            exit(EXIT_FAILURE);
        }
        else if (WIFSIGNALED(cs))
        {
            exit(WTERMSIG(cs));
        }
    }
    free(true_cmd);
}

