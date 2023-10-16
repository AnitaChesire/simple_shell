#include "main.h"
#define BUFSIZE 1024
#define MAXIMUM_ARG 150

void pipe_rd(int pfd, char **envp);

void pipe_rd(int pfd, char **envp)
{
    int pipepath[2], i = 0;
    pid_t pid;
    char *args = NULL, *args1[MAXIMUM_ARG], *args2[MAXIMUM_ARG], *token;
    const char *delim = " ";

    if (pipe(pipepath) == -1)
    {
        perror("Error: Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1)
    {
        perror("Error: Forking failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        close(pipepath[0]);
        if (dup2(pipepath[1], STDOUT_FILENO) == -1)
        {
            perror("Error: Duplication of file descriptor failed");
            exit(EXIT_FAILURE);
        }
        close(pipepath[1]);

        token = strtok(args, delim);
        while (token != NULL && i < MAXIMUM_ARG - 1)
        {
            args1[i++] = token;
            token = strtok(NULL, delim);
        }
        args1[i] = NULL;

        execute(args1, envp);
    }
    else
    {
        close(pipepath[1]);
        if (dup2(pfd, STDIN_FILENO) == -1)
        {
            perror("Error: Duplication of file descriptor failed");
            exit(EXIT_FAILURE);
        }
        close(pfd);

        token = strtok(args, delim);
        while (token != NULL && i < MAXIMUM_ARG - 1)
        {
            args2[i++] = token;
            token = strtok(NULL, delim);
        }
        args2[i] = NULL;

        execute(args2, envp);
    }
}
