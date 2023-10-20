#include "shell.h"
/**
 * main - This is our(Jude & Mubarak) simple shell main program.
 * Description: This program runs our basic shell project in C programming.
 * @argc: The argument count.
 * @argv: The arguments vector.
 * Return: upon success (0)
 */
int main(int argc, char **argv)
{
	int stat_shell;
	shellinfo_t *ourtype;

	ourtype = malloc(sizeof(shellinfo_t));
	if (ourtype == NULL)
	{
		perror(argv[0]);
		exit(1);
	}

	ourtype->pid = getpid();
	ourtype->code_stat = 0;
	ourtype->num_cmd = 0;
	ourtype->argc = argc;
	ourtype->argv = argv;
	ourtype->it_mode = isatty(0) == 1;
	begin(ourtype);

	stat_shell = ourtype->code_stat;

	free(ourtype);

	return (stat_shell);
}
