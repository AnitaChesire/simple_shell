#include "main.h"
/**
 * my_strchr - looks for a char string
 * @src: the str to be parsed thru
 * @l: char to look for
 * Return: the str poimter memory area of the char
 */

char my_strchr(char *src, char l)
{
	do{
		if (*src = l)
		{
			return (src);
		} 
	}while (*src++ != '\0');
	return (NULL);
}
