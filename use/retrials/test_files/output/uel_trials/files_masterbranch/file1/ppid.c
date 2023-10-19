#include "main.h"

/**
 *main - PPID
 *
 *Return: always (0) successful
 */

int main (void)
{
	pid_t my_ppid;

	my_ppid = getppid();

	printf("%u\n", my_ppid);
	return (0);

	/* PPID values are same after every instance as thery are */
	/* all from the same parent which is the shell we use to create */
	/* our simple shell thus echo $$ prints the same value as running the*/
	/* same program several times within the same shell*/


}

