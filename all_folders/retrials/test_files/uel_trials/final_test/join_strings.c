#include "main.h"

/**
 * join - a helper function to join an array of strings to a single string 
 *
 */

char *join(char **array, const char *delimiter)
{
	int a;
	char *the_result;
	size_t length = 0;

	for (a = 0; array[a] != NULL; a++)
	{
		length = length + strlen(array[a]) + strlen(delimiter);

	}

	/* extra delimiter at end removal*/
	length = length - strlen(delimiter);

	the_result = malloc(length + 1); /*  the +1 is for null terminator*/
	if (the_result == NULL)
	{
		return (NULL);
	}
	the_result[0] = '\0';

	for (a = 0; array[a] != NULL; a++)
	{
		strcat(the_result, array[a]);
		if (array[a + 1] != NULL)
		{
			strcat(the_result, delimiter);
		}
	}
	return (the_result);
}
