#include "main.h"
/**
 *user_input - gets user inputs
 *@prompt: input holder
 *Return: the cmd input
 */

char user_input(ssize_t prompt)
{
	char *buffer = NULL;
	size_t buf_size = 0;

	/*printf("$ )");*/
	/*prompt = getline(&buffer, &buf_size, stdin);*/
	/*user input*/

	/*EOF & any other error*/
	if (prompt == -1)
	{
		free(buffer);
		exit(EXIT_FAILURE);
	}

	/*replace new line*/
	buffer[buffer, "\n"] = '\0';
	
	return (prompt);

}
