#include "shell.h"
/**
 * run - A function that executes a command in another process called child.
 * @cmd: The command to execute is passed and received here.
 * @argu: Arguments passed to the command.
 * @ourtype: a struct of the shell info.
 * @buffer: Line counter.
 * Return: nothing upon success.
 */
void run(char *cmd, char **argu, shellinfo_t *ourtype, char *buffer)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(cmd, argu, environ);
		perror("./sh");

		release_memory_pointer((void *) argu);

		if (ourtype->cmd_path != NULL)
		{
			free(ourtype->cmd_path);
			ourtype->cmd_path = NULL;
		}

		free(ourtype);
		free(buffer);
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			ourtype->code_stat = WEXITSTATUS(status);
		}
	}
}
/**
 * is_file - A function that checks if a particular name is a file or binary.
 * @file_name: File to check if it has the permission to execute
 * Return: 1 If is a file with the right permission, else -1.
 */
int is_file(char *file_name)
{
	int m, ego;

	ego = _strlen(file_name);
	for (m = 0; m < ego; m++)
		if (file_name[m] == '/')
		{
			return (is_executable(file_name));
		}

	return (-1);
}
/**
 * write_character - A function that prints a character to the standard output.
 * @character: Character to be printed is parsed here.
 * Return: On success 1.
 */
int write_character(char character)
{
	return (write(1, &character, 1));
}
/**
 * sub_env - A function used for replacing env variables.
 * @ourtype: input as parameter.
 * @envi_var: environment variable input.
 * Return: pointer to the string.
 */
char *sub_env(shellinfo_t *ourtype, char *envi_var)
{
	char *envi;

	(void) ourtype;

	envi = get_env(envi_var);
	if (envi != NULL)
	{
		return (envi);
	}

	return (NULL);
}
