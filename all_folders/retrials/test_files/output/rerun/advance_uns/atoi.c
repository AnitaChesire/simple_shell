#include "main.h"
/**
 * my_atoi - converts strings into numerals
 * @str - string holder
 * Return: 0 if there are no numbers otherwise converted no
 */

int my_atoi(char *str)
{
	int i = 0, alert = 0, sigh = 1, result;
	unsigned int presult = 0;

	for (i = 0; str[i] != '\0' && alert != 2; i++)
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			alert = 1;
			presult *= 10;
			presult += (str[i] - '0');
		}
		else if (alert == 1)
		{
			alert = 2;
		}
	}
	if (sign == -1)
	{
		result = -presult;
	}
	else
	{
		result = presult;
	}
	return (result);
}
