#include "shell.h"

int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);

/**
 * _strlen - Returns the length of a string.
 * @s: A pointer to the characters string.
 *
 * Return: The length of the character string.
 */
int _strlen(const char *s)
{
    int length = 0;

    if (!s)
        return length;

    while (s[length] != '\0')
        length++;

    return length;
}

/**
 * _strcpy - Copies the string pointed to by src to dest.
 * @dest: Pointer to the destination of copied string.
 * @src: Pointer to the source string.
 *
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, const char *src)
{
    size_t i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
    return dest;
}

/**
 * _strcat - Concatenates two strings.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 *
 * Return: Pointer to destination string.
 */
char *_strcat(char *dest, const char *src)
{
    char *destTemp = dest;

    while (*destTemp)
        destTemp++;

    while (*src)
    {
        *destTemp = *src;
        destTemp++;
        src++;
    }

    *destTemp = '\0';
    return dest;
}

/**
 * _strncat - Concatenates n bytes from src to dest.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 * @n: Number of bytes to copy from src.
 *
 * Return: Pointer to destination string.
 */
char *_strncat(char *dest, const char *src, size_t n)
{
    size_t dest_len = _strlen(dest);
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];

    dest[dest_len + i] = '\0';

    return dest;
}

