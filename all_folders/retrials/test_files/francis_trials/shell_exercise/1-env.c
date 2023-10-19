#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include "main.h"

/*
 * main - finds the path of of the filename
 */

int main()
{
	char *buffer[100];
	size_t bufsize = 0;

	/*simpler code*/
	while (1)
	{
		printf("Enter command\nUser/$: ");
		ssize_t prompt = without_getline(&buffer, &bufsize, stdin);

		if (prompt == NULL)
		{
			break;
		}

		buffer[strcspn(buffer, "\n")] = '\0';
		system(buffer);
	}
	return (0);
}
