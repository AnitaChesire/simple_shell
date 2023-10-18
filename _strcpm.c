#include "shell.h"

char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/**
 * _strchr - Locates a character in a string.
 * @s: The string to be searched.
 * @c: The character to be located.
 *
 * Return: If c is found - a pointer to the first occurrence.
 *         If c is not found - NULL.
 */
char *_strchr(char *s, char c)
{
	int index = 0;

	while (s[index] != '\0')
	{
		if (s[index] == c)
			return (s + index);
		index++;
	}

	return NULL;
}

/**
 * _strspn - Gets the length of a prefix substring.
 * @s: The string to be searched.
 * @accept: The prefix to be measured.
 *
 * Return: The number of bytes in s which
 *         consist only of bytes from accept.
 */
int _strspn(char *s, char *accept)
{
	int bytes = 0;
	int index;

	while (*s)
	{
		for (index = 0; accept[index] != '\0'; index++)
		{
			if (*s == accept[index])
			{
				bytes++;
				break;
			}
		}
		s++;
	}

	return bytes;
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: 0 if s1 and s2 are equal.
 *         Positive value if s1 is greater than s2.
 *         Negative value if s1 is less than s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * _strncmp - Compare two strings.
 * @s1: Pointer to a string.
 * @s2: Pointer to a string.
 * @n: The first n bytes of the strings to compare.
 *
 * Return: Less than 0 if s1 is shorter than s2.
 *         0 if s1 and s2 match.
 *         Greater than 0 if s1 is longer than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return s1[i] - s2[i];
		i++;
	}

	if (i == n)
		return 0;
	else
		return s1[i] - s2[i];
}

