#include "shell.h"

void *_realloc(void *ptr, size_t old_size, size_t new_size);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: A pointer to the memory previously allocated.
 * @old_size: The size in bytes of the allocated space for ptr.
 * @new_size: The size in bytes for the new memory block.
 *
 * Return: If new_size == old_size - ptr.
 *         If new_size == 0 and ptr is not NULL - NULL.
 *         Otherwise - a pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void *mem;

    if (new_size == old_size)
        return ptr;

    if (ptr == NULL)
    {
        mem = malloc(new_size);
        if (mem == NULL)
            return NULL;
        return mem;
    }

    if (new_size == 0)
    {
        free(ptr);
        return NULL;
    }

    mem = malloc(new_size);
    if (mem == NULL)
        return NULL;

    // Copy the data from the old memory block to the new one
    memcpy(mem, ptr, old_size < new_size ? old_size : new_size);

    free(ptr);
    return mem;
}

/**
 * assign_lineptr - Reassigns the lineptr variable for _getline.
 * @lineptr: A buffer to store an input string.
 * @n: The size of lineptr.
 * @buffer: The string to assign to lineptr.
 * @b: The size of buffer.
 */
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
    if (*lineptr == NULL || b > *n)
    {
        // Allocate new memory if needed
        size_t new_size = b > 120 ? b : 120;
        *lineptr = _realloc(*lineptr, *n, new_size);
        *n = new_size;
    }

    strcpy(*lineptr, buffer);
    free(buffer);
}

/**
 * _getline - Reads input from a stream.
 * @lineptr: A buffer to store the input.
 * @n: The size of lineptr.
 * @stream: The stream to read from.
 *
 * Return: The number of bytes read.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
    ssize_t ret = 0;
    char c;
    int r;

    if (lineptr == NULL || n == NULL)
        return -1;

    // Initialize variables
    size_t input = 0;
    *lineptr = NULL;
    *n = 0;

    while (1)
    {
        r = fread(&c, 1, 1, stream);

        if (r <= 0)
        {
            if (ret == 0)
                ret = r;
            break;
        }

        if (input >= *n)
        {
            // Resize the buffer as needed
            size_t new_size = *n == 0 ? 120 : (*n) * 2;
            *lineptr = _realloc(*lineptr, *n, new_size);
            *n = new_size;
        }

        (*lineptr)[input] = c;
        input++;

        if (c == '\n')
        {
            ret = input;
            break;
        }
    }

    if (ret <= 0 && *lineptr != NULL)
    {
        free(*lineptr);
        *lineptr = NULL;
        *n = 0;
    }

    return ret;
}
