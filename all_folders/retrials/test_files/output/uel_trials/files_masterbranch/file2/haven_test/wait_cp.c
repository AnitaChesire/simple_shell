#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "main.h"

/**
 * main - checks the wait process
 */
int wait_func()
{
	pid_t wait_fk;
	pid_t my_pid;
	int status;

	printf("checking......");
	wait_fk = fork();

	/*error on folk*/
	if (wait_fk == -1)
	{
		perror("error in fork");
		return (-1);
	}

	my_pid = getpid();
	/*child*/
	if (wait_fk == 0)
	{
		printf("i am the child & my process id %u\n", my_pid);
	}
	/*parent*/
	else
	{
		wait(&status);
		/*printf("My child has reached home\n");*/
		printf(" I am the father & my process id is %u\n", my_pid);
	}
	return (0);
}
