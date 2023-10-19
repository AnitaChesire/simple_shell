#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

#define BUF_SIZE 1024
#define NUMLINE 234

/**
 * without_getline - accepts a str from input stream as input
 */

char *without_getline(void)
{
	static char buffer[BUF_SIZE]; /* holds the input*/
	static int buff_index = 0; /* tracks current loc of buffer*/
	static int buffer_sz = 0; /*tracks the no. of variable char in buffer*/

	char *str_line = NULL;
	int str_sz = 0;
	while (1)
	{
		/*read input*/
		if (buff_index >= buffer_sz)
		{
			buffer_sz = read(STDIN_FILENO, buffer, BUF_SIZE);
			/*EOF*/
			if (buffer_sz <= 0)
			{
				return (NULL);
			}
			buff_index = 0;
		}

		else
		{
			char str = buffer[buff_index++];
			
			/*new line*/
			if (str == '\n')
			{
				str_line = realloc(str_line, str_sz + 1);
				str_line[str_sz] = '\0';
				return (str_line);
			}

			/* if no new line*/
			else
			{
				str_line = realloc(str_line, str_sz + 2);
				str_line[str_sz++] = str;
			}
		}
	}



}
