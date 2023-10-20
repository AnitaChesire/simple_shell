#include "shell.h"
/**
 * release_memory - A function that frees a pointer.
 * @pointer: Pointer to be freed is passed here.
 * Return: void, upon success.
 */
void release_memory(void *pointer)
{
	if (pointer != NULL)
	{
		free(pointer);
		pointer = NULL;
	}
	pointer = NULL;
}

/**
 * release_memory_pointer - A function that frees a double pointer,
 * which is a pointer to a pointer.
 * @pointer: the pointer to a pointer to be freed.
 * Return: nothing, upon success.
 */
void release_memory_pointer(void **pointer)
{
	void **temp;

	for (temp = pointer; *temp != NULL; temp++)
	{
		release_memory(*temp);
	}

	release_memory(pointer);
}
