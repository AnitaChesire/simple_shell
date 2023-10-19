#include "main.h"
/**
 *shell_interactive - rest if shell is interactive mode
 *@unix: struct address;
 *Return: true (1) shell is interactive otherwise (0)
 *
 *
 */
int shell_interactive(my_shell *unix)
{
	return (isatty(STDIN_FILENO) && unix->readfd <= 2);
}
