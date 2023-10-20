#include "shell.h"

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
 * signature_handler - A function that handles SIGINT.
 * @num: a parameter that is not used.
 * Return: Nothing ((fflush flushes out content of output string))
 */
void signature_handler(int num)
{
	(void) num;

	signal(SIGINT, signature_handler);
	display("\n$ ");
	fflush(stdout);
}
