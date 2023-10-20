#include "shell.h"
/**
 * _realloc - A function that reallocates memory.
 * @ptr: pointer to the old memory allocated.
 * @old_size: former size of the memory, usually smaller
 * @new_size: new size to the allocated memory.
 * Return: Upon success, return s void pointer to the newly allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *g;
	unsigned int i, max = new_size;
	char *old_p = ptr;

	if (ptr == NULL)
	{
		g = malloc(new_size);
		return (g);
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size == old_size)
		return (ptr);

	g = malloc(new_size);
	if (g == NULL)
		return (NULL);
	if (new_size > old_size)
		max = old_size;
	for (j = 0; j< max; j++)
		g[j] = old_p[i];
	free(ptr);
	return (g);
}
