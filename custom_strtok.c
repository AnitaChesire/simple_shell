#include "main.h"
/**
 * custom_strtok - A custom strtok function for tokenizing a string.
 * @string: The string to be tokenized.
 * @delimiter: The delimiter characters.
 *
 * Return: The next token from the string or NULL if there are no more tokens.
 */
char *custom_strtok(char *string, const char *delimiter)
{
char *last_token = NULL;
char *start;
if (string != NULL)
last_token = string;
if (last_token == NULL)
return (NULL);
while (*last_token != '\0' && strchr(delimiter, *last_token) != NULL)
last_token++;
if (*last_token == '\0')
{
last_token = NULL;
return (NULL);
}
start = last_token;
while (*last_token != '\0' && strchr(delimiter, *last_token) == NULL)
last_token++;
if (*last_token != '\0')
*last_token++ = '\0';
return (start);
}
