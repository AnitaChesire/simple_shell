#include "main.h"

/**
 *main - without argc
 *@argc: number of command line arguments/ number of items in argv
 *@argv: null terminated array of strings
 *Return : 0
 */

int main (int argc, char *argv[])
{

	char **arguments = argv;

	while (*arguments != NULL)
	{
		printf("%s\n", *arguments);
		arguments++;
	}


	return (0);
	/* taking advantage of the null pointer to determine the end of args*/





}
