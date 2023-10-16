#include "main.h"

void execute(char *command, char **argv);
void handle_exec_error(char *command, char **argv);

/**
 * execute - executes the cmd that users enter
 * @command: for non interactive mode
 * @argv: arguments entered by user
 */

void execute(char *command, char **argv)
{
    pid_t pid;
    char *error = "Error: couldnt fork\n";
    char **env = environ;
    int status;

    if (strcmp(command, "exit") == 0)
    {
        exit(EXIT_SUCCESS);
    }

    if (strcmp(command, "env") == 0)
    {
	while (*env)
        {
            write(STDOUT_FILENO, *env, strlen(*env));
            write(STDOUT_FILENO, "\n", 1);
            env++;
        }
        return;
    }

    pid = fork();
    if (pid == -1)
    {
        write(STDERR_FILENO, error, strlen(error));
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        if (execvp(command, argv) == -1)
        {
            handle_exec_error(command, argv);
        }
    }
    else
    {
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void handle_exec_error(char *command, char **argv)
{
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *path_token = strtok(path_copy, ":");
    char *error = "Error: ";
    char *not_found = " command not found\n";
    char *path_command = (char *)malloc(strlen(path_token) + strlen(command) + 2);

    while (path_token != NULL)
    {
        sprintf(path_command, "%s/%s", path_token, command);
        if (execv(path_command, argv) != -1)
        {
            return;
        }
        path_token = strtok(NULL, ":");
    }

    write(STDERR_FILENO, error, strlen(error));
    write(STDERR_FILENO, command, strlen(command));
 
    write(STDERR_FILENO, not_found, strlen(not_found));
    exit(EXIT_FAILURE);
}

