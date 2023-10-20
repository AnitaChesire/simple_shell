#include "shell.h"
/**
 * stringify - A function that converts a given number to a string.
 * @numbe: Number to be converted will be passed here
 * Return: Converted Number to string
 */
char *stringify(int numbe)
{
	char *num;
	int total_digits, k;

	total_digits = number(numbe);
	num = malloc(total_digits * sizeof(char) + 1);
	if (num == NULL)
		return (NULL);
	if (numbe == 0)
	{
		num[0] = '0';
		num[1] = '\0';
		return (num);
	}

	num[total_digits] = '\0';

	for (k = total_digits - 1; numbe != 0; numbe /= 10, k--)
	{
		num[k] = (numbe % 10) + '0';
	}

	return (num);
}

/**
 * has_letter - A function that checks if a digit string contains letter
 * @string: String to be checked for presence of letters. 
 * Return: If a non-digits was found, return 1
 * Otherwise, return 0.
 */
int has_letter(char *string)
{
	int n;

	for (n = 0; string[n] != '\0'; n++)
	{
		if (is_numeric(string[n]) == 0)
			return (1);
	}

	return (0);
}
