#include "main.h"
#define BUFSIZE 1024
#define MAXIMUM_ARG 128

int main(int argc, char **argv, char **envp);

/**
 * main - prints out unix shell cmd from user input
 * @argc: no. of arguments
 * @argv: pointer array arguments
 * @envp: pointer array of environment variables
 * Return: 0 if success and -1 on failure
 */
int main(int argc, char **argv, char **envp)
{
    int pfd[2], has_pipe = 0, i = 0;
    char *args[MAXIMUM_ARG], command[BUFSIZE], *pipe_token, *token;
    pid_t pid;
    (void)argc, (void)argv;
    char error_msg_one[] = "Error: fork\n";
    char error_msg[] = "Error: Piping\n";
    char new_line[] = "\n";
    char prompt[] = "$ ";

    while (1)
    {
        /* User prompt */
          write(STDOUT_FILENO, prompt, strlen(prompt));
        fflush(stdout);

        /* EOF */
        if (!fgets(command, BUFSIZE, stdin))
        {
           write(STDOUT_FILENO, new_line, strlen(new_line));
            break;
        }

        /* Remove and replace new line */
        command[strcspn(command, "\n")] = 0;
        if (strcmp(command, "exit") == 0)
        {
            break;
        }

        pipe_token = strtok(command, "|");
        if (pipe_token != NULL)
        {
            has_pipe = 1;
            *pipe_token++ = '\0';
            while (*pipe_token == ' ')
            {
                pipe_token++;
            }

            token = strtok(command, " ");
            while (token != NULL && i < MAXIMUM_ARG - 1)
            {
                args[i++] = token;
                token = strtok(NULL, " ");
            }
            args[i] = NULL;

            if (has_pipe)
            {
                if (pipe(pfd) == -1)
                {
        
                    write(STDERR_FILENO, error_msg, strlen(error_msg));
                    exit(EXIT_FAILURE);
                }
                pid = fork();
                if (pid == -1)
                {
        
                    write(STDERR_FILENO, error_msg, strlen(error_msg_one));
                    exit(EXIT_FAILURE);
                }
                else if (pid == 0)
                {
                    close(pfd[0]);
                    dup2(pfd[1], STDOUT_FILENO);
                    close(pfd[1]);
                    token = strtok(command, " ");
                    i = 0;
                    while (token != NULL && i < MAXIMUM_ARG - 1)
                    {
                        args[i++] = token;
                        token = strtok(NULL, " ");
                    }
                    args[i] = NULL;
                    execute(args, envp);
                }
                else
                {
                    close(pfd[1]);
                    dup2(pfd[0], STDOUT_FILENO);
                    close(pfd[0]);
                    token = strtok(pipe_token, " ");
                    i = 0;
                    while (token != NULL && i < MAXIMUM_ARG - 1)
                    {
                        args[i++] = token;
                        token = strtok(NULL, " ");
                    }
                    args[i] = NULL;
                    pipe_rd(STDIN_FILENO, envp);
                }
            }
            else
            {
                execute(args, envp);
            }
        }
    }
    return (0);
}

