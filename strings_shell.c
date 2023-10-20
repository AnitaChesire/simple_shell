#include "shell.h"

/**
 * _strcat - A function that concatenates two strings.
 * @dest: the destination string.
 * @src: the source string.
 * Return: destination string (char *ptr)
 */
char *_strcat(char *dest, char *src)
{
	int len1, len2, p;

	for (len1 = 0; dest[len1] != '\0'; len1++)
	{

	}

	for (len2 = 0; src[len2] != '\0'; len2++)
	{

	}
	for (p = 0; p <= len2; p++)
	{
		dest[len1 + p] = src[p];
	}

	return (dest);
}

/**
 * _strlen - A function that returns the length of a string.
 * @s: character string.
 * Return: length of the string.
 */
int _strlen(char *s)
{
	int len_total;

	len_total = 0;
	while (s[len_total] != '\0')
	{
		len_total++;
	}

	return (len_total);
}

/**
 * _strcmp - A function that compares two strings.
 * @s1: first string.
 * @s2: second string.
 * Return: (0) when they are the same, positive if s1 > s2, negative if s1 < s2
 */
int _strcmp(char *s1, char *s2)
{
	int k;
	int j = 0;

	for (k = 0; s1[k] != '\0' && j == 0; k++)
	{
		j = s1[k] - s2[k];
	}

	return (j);
}

/**
 * _strcpy - Copies a string from source to destination.
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the source string.
 * Return: Pointer to the destination buffer.
 */
char *_strcpy(char *dest, char *src)
{
	int g;

	for (g = 0; src[g] != '\0'; g++)
	{
		dest[g] = src[g];
	}
	dest[g] = '\0';

	return (dest);
}

/**
 * _strdup - A function that copies a string.
 * @str: String to be copied.
 * Return: A character pointer to the newly allocated string in memory.
 */
char *_strdup(char *str)
{
	char *dest;
	int str_size, m;

	if (str == NULL)
	{
		return (NULL);
	}

	str_size = _strlen(str) + 1;
	dest = malloc(str_size * sizeof(char));
	if (dest == NULL)
	{
		return (NULL);
	}
	for (m = 0; m < str_size; m++)
	{
		dest[m] = str[m];
	}

	return (dest);
}
