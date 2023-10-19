#include "main.h"

/**
 *PPID function
 *
 *Return: always (0) successful
 */

int ppid(void)
{
	pid_t my_ppid;
	my_ppid = getppid();

	printf("%u\n", my_ppid);

	return (my_ppid);

	/* PPID values are same after every instance as they are */
	/* all from the same parent which is the shell we use to create */
	/* our simple shell thus echo $$ prints the same value as running the*/
	/* same program several times within the same shell*/


}

