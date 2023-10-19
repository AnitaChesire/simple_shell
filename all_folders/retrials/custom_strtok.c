#include "main.h"

/**
 *custom_strtok - a custom strtok function
 *@string: the string to be tokenized
 *@delimiter: the delimiter
 *Return: tokenized string
 */

char *custom_strtok(char *string, const char *delimiter)
{
	/* pointing to the final token found in the string*/
	static char *the_final_token;

	if (string != NULL)
	{
		the_final_token = NULL;
	}
	/* if string is NULL, continue searching from the position*/
	/* pointed by the final token */

	if (string == NULL)
	{
		string = the_final_token;

	}
	/* if string is still empty this means there are no more*/
	/* tokens to extract */
	if (string == NULL)
	{
		return (NULL);
	}


	/* find the start of the next token*/
	string = string + strspn(string, delimiter);

	if (*string ==  '\0')
	{
		return (NULL);
	}
	/* find the end of the token*/
	the_final_token = string + strcspn(string, delimiter);
	if (*the_final_token != '\0')
	{
		*the_final_token++ = '\0';
	}

	return (string);

}
