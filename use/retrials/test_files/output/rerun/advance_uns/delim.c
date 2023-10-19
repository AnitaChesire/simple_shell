#include "main.h"
/**
 *is_delim - test whether the str is delimeter
 *@c: char str
 *@delim: pointer to special character
 *Return: 0 on success, -1 on failure
 */
unsigned int is_delim(char s, char *delim)
{
	while (*delim != '\0')
	{
		if ( c == *delim)
		{
			return (1);
		}
		delim++;
	}
	return (0);
}
