#include "main.h"

char *handle_comments(char *command)
{
	command[strcspn(command, "\n")] = '\0';

	/* checking if command is a comment*/
	if (command[0] == '#')
	{
		return (NULL);
	}

	return (command);

}
