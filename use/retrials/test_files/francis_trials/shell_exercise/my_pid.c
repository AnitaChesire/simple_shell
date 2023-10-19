#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <unistd.h>
/**
 * PID
 */

int main(void)
{
	pid_t my_pid;
	pid_t my_ppid;
	/*child processor id*/
	my_pid = getpid();
	/* parent processsor id */
	my_ppid = getppid();

	printf("child: %u\nParent:%u\n", my_pid, my_ppid);
	return (0);
}

