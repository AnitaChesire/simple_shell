#include "shell.h"

/**
 * _atoi - A function converts a string to an integer.
 * @s: input string value.
 * Return: integer.
 */
int _atoi(char *s)
{
	int result = 0;
	int sign = 1; /*Positive by default*/
	int k = 0;

	/*Handle negative numbers*/
	if (s[0] == '-')
	{
		sign = -1;
		k++;
	}

	/*Iterate through the string and convert to integer*/
	while (s[k] != '\0')
	{
		if (s[k] >= '0' && s[k] <= '9')
		{
			result = result * 10 + (s[k] - '0');
		}
		else
		{
			/*Invalid character found, break the loop*/
			break;
		}
		k++;
	}

	return (result * sign);
}
