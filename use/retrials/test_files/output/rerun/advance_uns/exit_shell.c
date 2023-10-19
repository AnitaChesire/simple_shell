#include "main.h"
/**
 *_strncpy - copies a string
 *@detination: string to be copied to
 *@source: str to copy from
 *@n: no of characters to be copied
 *Return: the copied/conc string
 */
char *_strncpy(char *destination, char *source, int n)
{
	int i = 0, b = 0;
	char *str = destination;

	while (src[i] != '\0' && i < n - 1)
	{
		destination[i] = source[i];
		i++
	}
	if (i < n)
	{
		b = i;
		while (b < n)
		{
			destination[b] = '\0';
			b++;
		}
	}
	return (src);
}

