#include "shell.h"
/**
 * output_to_fd - A function that prints a string to file descriptor
 * @message: instead of character a string is printed.
 * @fil_des: File descriptor to print to either 1 2 or 0
 *
 * Return: On success numbers of bytes printed is returned
 **/
int output_to_fd(char *message, int fil_des)
{
	int buffer;

	buffer = _strlen(message);
	return (write(fil_des, message, buffer));
}

/**
 * write_character_to_fd - A function that helps the user write a character to a specific file descriptor.
 * @cha: Character to print
 * @fil_des: specific file descriptor to be 0,1 or 2
 * Return: On success 1.
 */
int write_character_to_fd(char cha, int fil_des)
{
	return (write(fil_des, &cha, 1));
}

