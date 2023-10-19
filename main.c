#include "main.h"

#define COMMAND_MAX_LENGTH 1024

/**
 * main - Main shell program
 * @ac: Number of command line arguments
 * @av: Array containing the program command line arguments
 * Return: 0
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
    char *command = NULL, *directory;
    size_t buffer_size = 0;
    int line_nbr = 1;
    char **command_tokens;
    int status;

    while (1)
    {
        if (isatty(STDOUT_FILENO))
		write(STDOUT_FILENO, "", 1);
/*            printf(" ");*/

        if (getline(&command, &buffer_size, stdin) == -1)
        {
            free(command);
            exit(EXIT_SUCCESS);
        }

        if (command[0] == '#')
            continue;

        line_nbr++;

        if (strcmp(command, "exit\n") == 0)
            exit(EXIT_SUCCESS);

        if (strncmp(command, "exit ", 5) == 0)
        {
            status = atoi(command + 5);
            if (status >= 0)
                exit(status);

            fprintf(stderr, "%s: %d: exit: Illegal number: %d\n", av[0], line_nbr, status);
            continue;
        }

        command_tokens = tokenize_command(command);

        if (command_tokens[0] != NULL)
        {
            if (strcmp(command_tokens[0], "cd") == 0)
            {
                directory = command_tokens[1];
                if (!directory || strcmp(directory, "-") == 0)
                    directory = getenv("HOME");

                if (directory && chdir(directory) == 0)
                    setenv("PWD", directory, 1);
                else
                    fprintf(stderr, "%s: %d: cd: %s: No such file or directory\n", av[0], line_nbr, directory);
            }
            else
            {
                exec(command_tokens, av[0]);
            }
        }

        free(command_tokens);
    }

    return 0;
}

/**
 * tokenize_command - Function to tokenize commands
 * @command: The command to be tokenized
 * Return: Fully and well tokenized commands
 */
char **tokenize_command(char *command)
{
    char **command_tokens;
    char *token;
    int q = 0;

    command_tokens = malloc(sizeof(char *) * COMMAND_MAX_LENGTH + 1);
    if (!command_tokens)
    {
        perror("malloc failed from tokenize_command");
        exit(EXIT_FAILURE);
    }

    token = custom_strtok(command, " \n");

    while (token && token[0] != '#')
    {
        command_tokens[q++] = token;
        token = custom_strtok(NULL, " \n");
    }

    command_tokens[q] = NULL;
    free(token);

    return command_tokens;
}

