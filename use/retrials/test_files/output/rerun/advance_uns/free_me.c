#include "main.h"
/**
 * free_me - frees ptr memory address
 * @ptr: pointer address for memory alloc
 * Return: 0 on success and -1 on fail
 */
int free_me(void **ptr)
{
	/*ensure there are no leaks when tested with valgrind*/
	if (*ptr && ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
