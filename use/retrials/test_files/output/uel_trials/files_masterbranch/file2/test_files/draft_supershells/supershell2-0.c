#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"
#include <string.h>

/**
 * main - prints out the shell commands
 */

int main(int ac, char **argv)
{
	/*initializationa and declaration*/
	char *buffer;
	size_t bufsize = 32;


	/* instruction message*/
	printf("Welcome to print shell 2.0\n Enter command & Ctlr+D to exit");

	/* allocate space*/
	buffer = (char *) malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
	{
		perror("Didn't allocate successfully");
		return (0);
	}
	else
	{
		while (1)
		{
			printf("Enter shell:\nuser/$: ");
			ssize_t prompt = getline(&buffer, &bufsize, stdin);
			
			/*EOF*/
			if (prompt == EOF)
			{
				printf("existing the program...");
				free(buffer);
				return (0);
			}
			
			/* Successful*/
			else
			{
				/* strtok section*/
				char *token;
				const char *delim = " ";

				/*replacing newline character with null character*/
				buffer[strcspn(buffer, "\n")] = '\0';

				/*tokenization*/
				token = strtok(buffer, delim);
				char *av[10] = { NULL };
				int argc = 0;
				
				/*second tokenization*/
				while (token != NULL && argc < 10)
				{
					av[argc++] = token;
					token = strtok(NULL, delim);
				}
				
				if (argc > 0)
				{
					/*fork section*/
					/*int status;*/
					pid_t pid;
					pid = fork();
					
					
					/*error of fork*/
					if (pid == -1)
					{
						if (execve( av[0], av, NULL) == -1)
						{
							printf("error while forking\n");
							free(buffer);
							return (1);
						}
					}
					
					/*success on fork*/
					else if (pid == 0)
					{
						if (execve( av[0], av, NULL) == -1)
						{
							printf("failed to execve propely\n");
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
		}
		
		/*print the prompt from the user*/
		/*printf("%s\n", buffer);*/
	}
	free(buffer);
	return (0);
}
