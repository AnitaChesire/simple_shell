#include "main.h"
/**
 *my_strncat - concats two strings
 *@destination: the 1st char str
 *@source: the 2nd char str
 *@n: no of bytes to fully allocated
 *Return - the concat str
 */
char *my_strncat(char *destination, char *source, int n)
{
	int m = k = 0;
	char *chr = destination;

	while (destination[m] != '\0')
	{
		i++;
	}
	while (source[k] != '\0' && k < n)
	{
		destination[m] = source[k];
		m++, k++;
	}
	if (k < n)
	{
		destination[i] = '\0';
	}
	return (chr);
}

