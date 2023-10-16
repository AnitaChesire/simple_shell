#include "main.h"

void execute(char **args, char **envp);

void execute(char **args, char **envp)
{
    pid_t pid;
    int pipepath[2], status;
    char *error_message;

    if (pipe(pipepath) == -1)
    {
        error_message = "Error: Piping\n";
        write(STDERR_FILENO, error_message, strlen(error_message));
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1)
    {
        error_message = "Error: fork\n";
        write(STDERR_FILENO, error_message, strlen(error_message));
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        close(pipepath[0]);
        if (dup2(pipepath[1], STDOUT_FILENO) == -1)
        {
            error_message = "Error: Duplicate file descriptor\n";
            write(STDERR_FILENO, error_message, strlen(error_message));
            exit(EXIT_FAILURE);
        }
        close(pipepath[1]);
        if (execve(args[0], args, envp) == -1)
        {
            error_message = "Error: execve\n";
            write(STDERR_FILENO, error_message, strlen(error_message));
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        close(pipepath[1]);
        pipe_rd(pipepath[0], envp);

        if (waitpid(pid, &status, 0) == -1)
        {
            error_message = "Waitpid\n";
            write(STDERR_FILENO, error_message, strlen(error_message));
            exit(EXIT_FAILURE);
        }
    }
}

