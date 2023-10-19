#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/*
 */
int main(int ac, char **argv)
{
	char *buffer = NULL, *token;
	size_t bufsize = 0, command;
	const char *delim = " ";

	while (1)
	{
		printf("Enter command & to exit (ctrl + D)\nroot/user/$: ");
		ssize_t command = getline(&buffer, &bufsize, stdin);
		/*EOF*/
		if (command == EOF)
		{
			free(buffer);
			printf("\nExiting program....\n");
			return (0);
		}
		/* parsing center */
		/*int count = strlen(buffer);*/
		/*replacing newline character with null character*/
		buffer[strcspn(buffer, "\n")] = '\0';
		token = strtok(buffer, delim);
		char *av[10] = { NULL };
		int arggc = 0;

		while (token != NULL && arggc < 10)
		{
			av[arggc++] = token;
			token = strtok(NULL, delim);
		}
		if (arggc > 0)
		{
			pid_t pid = fork();
			if (pid == -1)
			{
				if (execve( av[0], av, NULL) == -1)
				{
					printf("Error fork failed\n");
					free(buffer);
					return (1);
				}
			}
			else if (pid == 0)
			{
				if (execve( av[0], av, NULL)     == -1)
				{
					printf("Error:execve failed.\n");
					free(buffer);
					return (1);
				}
				
			}
			else
			{
				wait(NULL);	
			}
		}
	}
	printf("\nExiting program...\n");
	return (0);
}
