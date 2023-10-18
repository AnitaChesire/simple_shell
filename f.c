#include "shell.h"

int cant_open(char *file_path);
int proc_file_commands(char *file_path, int *exe_ret);

/**
 * cant_open - If the file doesn't exist or lacks proper permissions, print
 * a can't open error.
 * @file_path: Path to the supposed file.
 *
 * Return: 127.
 */
int cant_open(char *file_path)
{
    char *error;
    int len;

    len = _strlen(name) + _strlen(file_path) + 16;
    error = malloc(sizeof(char) * (len + 1));
    if (!error) {
        return 127;
    }

    snprintf(error, len, "%s: Can't open %s\n", name, file_path);
    write(STDERR_FILENO, error, len);
    free(error);
    return 127;
}

/**
 * proc_file_commands - Takes a file and attempts to run the commands stored
 * within.
 * @file_path: Path to the file.
 * @exe_ret: Return value of the last executed command.
 *
 * Return: If file couldn't be opened - 127.
 *   If malloc fails - -1.
 *   Otherwise the return value of the last command ran.
 */
int proc_file_commands(char *file_path, int *exe_ret)
{
	int i, file;
	char **front;
	char **args;
	ssize_t b_read;
	unsigned int k, line_size = 0;
	unsigned int old_size = 120;
	char *line = NULL;
	char buffer[120];
	int ret;

	hist = 0;
	file = open(file_path, O_RDONLY);
	if (file == -1)
	{
		*exe_ret = cant_open(file_path);
		return (*exe_ret);
	}

	line = malloc(sizeof(char) * old_size);
	if (!line)
		return (-1);

	while ((b_read = read(file, buffer, 119)) > 0)
	{
		buffer[b_read] = '\0';
		line_size += b_read;
		line = _realloc(line, old_size, line_size);
		_strcat(line, buffer);
		old_size = line_size;
	}

	if (b_read == -1 && line_size == 0)
	{
		free(line);
		return (-1);
	}

	for (k = 0; k < line_size; k++)
	{
		if (line[k] == '\n')
		{
			line[k] = ';';
			for (k += 1; k < line_size && line[k] == '\n'; k++)
				line[k] = ' ';
		}
	}

	variable_replacement(&line, exe_ret);
	handle_line(&line, line_size);
	args = _strtok(line, " ");
	free(line);

	if (!args)
		return (0);

	if (check_args(args) != 0)
	{
		*exe_ret = 2;
		free_args(args, args);
		return (*exe_ret);
	}

	front = args;

	
	for (i = 0; args[i]; i++)
	{
		if (_strncmp(args[i], ";", 1) == 0)
		{
			free(args[i]);
			args[i] = NULL;
			ret = call_args(args, front, exe_ret);
			args = &args[i + 1];
			i = 0;
		}
	}

	ret = call_args(args, front, exe_ret);

	free(front);
	return (ret);
}

