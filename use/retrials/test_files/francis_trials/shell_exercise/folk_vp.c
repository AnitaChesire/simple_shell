#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
 */
int main()
{
	pid_t my_pid;
	pid_t pid;

	/* folk center */
	pid = fork();

	/* I am an error*/
	if (pid == -1)
	{
		perror("error in generating process\n");
		return (-1);
	}
	/* I am a child */
	my_pid = getpid();
	if (pid == 0)
	{
		printf("iam a child & id process: %u\n", my_pid);
	}
	
	/* I am a parent*/
	else
	{
		printf("I am a parent & id process: %u\n", my_pid);
	}
	return (0);
}
