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
    int file;
    ssize_t b_read;
    unsigned int line_size = 0;
    unsigned int old_size = 120;
    char *line = NULL;
    char buffer[121]; 
    int ret;

    hist = 0;
    file = open(file_path, O_RDONLY);
    if (file == -1) {
        *exe_ret = cant_open(file_path);
        return *exe_ret;
    }

    line = malloc(sizeof(char) * old_size);
    if (!line) {
        return -1;
    }

    while ((b_read = read(file, buffer, 120)) > 0) 
    {
        buffer[b_read] = '\0';
        line_size += b_read;
        line = _realloc(line, old_size, line_size);
        _strcat(line, buffer);
        old_size = line_size;
    }

    free(line);
    return ret;
}
