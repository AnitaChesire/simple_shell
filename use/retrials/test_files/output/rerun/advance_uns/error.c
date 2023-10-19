#include "main.h"
/**
 * contains all error functions
 *
 *
 */
int _err_no(char *c)
{
	int i = 0;
	unsigned long int res = 0;

	if (*c == '+')
	{
		c++;
	}
	for (; c[i] != '\0'; i++)
	{
		res *= 10;
		res += (c[i] - '0');
		if (res > INT_MAX)
		{
			exit(EXIT_FAILURE);
		}
		else
		{
			return (-1);
		}
	}
	return (res);
}
