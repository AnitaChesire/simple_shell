#include "main.h"

int handle_exit(char *command, char *program_name);
void execute_commands(char *command, char *program_name);
void handle_cd(char **command_tokens, char *program_name, int line_nbr);
char **tokenize_command(char *command);

#define COMMAND_MAX_LENGTH 1024

/**
 * main - main shell program
 * @ac: number of command line arguments
 * @av: an array containing the program command line arguments
 * Return: 0
 */

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
    char *command = NULL;
    size_t buffer_size = 0;
    char *program_name = av[0];

    while (1)
    {
        printf(" ");
        if (getline(&command, &buffer_size, stdin) == -1)
        {
            free(command);
            exit(EXIT_SUCCESS);
        }
        if (command[0] == '#')
        {
            continue;
        }
        if (handle_exit(command, program_name))
        {
            free(command);
            exit(EXIT_SUCCESS);
        }
        execute_commands(command, program_name);
    }
}

int handle_exit(char *command, char *program_name)
{
	int status;

    if (strcmp(command, "exit\n") == 0 || strcmp(command, "exit 0\n") == 0)
    {
        free(command);
        exit(EXIT_SUCCESS);
    }
    if (strncmp(command, "exit ", 5) == 0)
    {
        status = atoi(command + 5);
        if (status >= 0)
        {
            free(command);
            exit(status);
        }
        else
        {
            fprintf(stderr, "%s: exit: Illegal number: %d\n", program_name, status);
            free(command);
            exit(2);
        }
    }
    return 0;
}

void execute_commands(char *command, char *program_name)
{
    char *cmd_ptr = command;
    int line_nbr = 1;
     char **command_tokens;
     char *sem_ptr;

    while (*cmd_ptr != '\0')
    {
        sem_ptr = strchr(cmd_ptr, ';');
        if (sem_ptr != NULL)
        {
            *sem_ptr = '\0';
        }

        command_tokens = tokenize_command(cmd_ptr);
        if (command_tokens[0] != NULL)
        {
            if (access(command_tokens[0], F_OK) == -1)
            {
                exec(command_tokens, program_name);
            }
            else if (strcmp(command_tokens[0], "cd") == 0)
            {
                handle_cd(command_tokens, program_name, line_nbr);
            }
            else
            {
                exec(command_tokens, program_name);
            }
        }
        free(command_tokens);

        if (sem_ptr != NULL)
        {
            cmd_ptr = sem_ptr + 1;
        }
        else
        {
            break;
        }
    }
}

void handle_cd(char **command_tokens, char *program_name, int line_nbr)
{
    char *directory = command_tokens[1];

    if (directory == NULL || strcmp(directory, "-") == 0)
    {
        directory = getenv("HOME");
    }
    if (directory != NULL && chdir(directory) == 0)
    {
        setenv("PWD", directory, 1);
    }
    else
    {
        fprintf(stderr, "%s: %d: cd: %s: No such file or directory\n", program_name, line_nbr, directory);
    }
}

/**
 * tokenize_command - function to tokenize commands
 * @command: the command to be tokenized
 * Return: fully and well tokenized commands
 */

char **tokenize_command(char *command)
{
    char **command_tokens = malloc(sizeof(char *) * COMMAND_MAX_LENGTH + 1);
    char *token;
    int q;

    if (command_tokens == NULL)
    {
        perror("malloc failed from tokenize_command");
        exit(EXIT_FAILURE);
    }
    q = 0;

    token = custom_strtok(command, " \n");
    while (token != NULL)
    {
        if (token[0] == '#')
        {
            break;
        }
        command_tokens[q++] = token;
        token = custom_strtok(NULL, " \n");
    }
    command_tokens[q] = NULL;
    return command_tokens;
}

