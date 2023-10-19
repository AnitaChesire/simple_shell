#include "main.h"

/**
 * error_eof - checks for the end of file error
 * @prompt: pointer str
 * @buffer: pointer to buffer
 * Return: if successful -1 and if fail 0
 */

char error_eof(ssize_t prompt, char *buffer)
{
	if (prompt == EOF)
	{
		perror("Error: reched end of file");
		free(buffer);
		exit(EXIT_FAILURE);
	}
	return (0);
}
