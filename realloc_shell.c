#include "shell.h"
/**
 * _realloc - A function that reallocates memory.
 * @ptr: pointer to the old memory allocated.
 * @old_size: former size of the memory, usually smaller.
 * @new_size: new size to the allocated memory.
 * Return: Upon success, return a void pointer to the newly allocated memory.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *void_ptr;
	unsigned int g, max = new_size;
	char *old_ptr = ptr;

	if (ptr == NULL)
	{
		void_ptr = malloc(new_size);
		return (void_ptr);
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size == old_size)
		return (ptr);

	void_ptr = malloc(new_size);
	if (void_ptr == NULL)
		return (NULL);
	if (new_size > old_size)
		max = old_size;
	for (g = 0; g < max; g++)
		void_ptr[g] = old_ptr[g];
	free(ptr);
	return (void_ptr);
}
