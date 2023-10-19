#include "main.h"
/**
* env_func - Function to display the environment.
*/
void env_func(void)
{
char **env = environ;
size_t length = 0;
while (*env)
{
length = _strlen(*env);
write(STDOUT_FILENO, *env, length);
write(STDOUT_FILENO, "\n", 1);
env++;
}
}
/**
* _strlen - Calculate the length of a string.
* @str: The string to calculate the length of.
* Return: The length of the string.
*/
size_t _strlen(const char *str)
{
size_t length = 0;
while (str[length] != '\0')
length++;
return (length);
}
