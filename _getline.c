#include "shell.h"

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

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    void *mem;
    char *ptr_copy;
    unsigned int size_to_copy, index;

    if (new_size == old_size)
        return ptr;

    if (new_size == 0 && ptr != NULL) {
        free(ptr);
        return NULL;
    }

    mem = malloc(new_size);
    if (mem == NULL)
        return NULL;

    if (ptr != NULL) {
        ptr_copy = ptr;
        size_to_copy = (new_size < old_size) ? new_size : old_size;
        for (index = 0; index < size_to_copy; index++)
            ((char *)mem)[index] = ptr_copy[index];
        free(ptr);
    }

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
	size_t new_size;

    if (*lineptr == NULL || b > *n)
    {
        /* Allocate new memory if needed*/
        new_size = b > 120 ? b : 120;
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
    char *buffer = NULL;
    size_t bufsize = 0;
    char c;
    int r;

    if (lineptr == NULL || n == NULL)
        return -1;

    while (1)
    {
        r = fread(&c, 1, 1, stream);

        if (r <= 0)
        {
            if (ret == 0)
                ret = r;
            break;
        }

        if ((size_t)ret >= bufsize)
        {
            bufsize = bufsize == 0 ? 120 : bufsize * 2;
            buffer = _realloc(buffer, bufsize, bufsize + 1);

            if (buffer == NULL)
            {
                free(buffer);
                return -1;
            }
        }

        buffer[ret] = c;
        ret++;

        if (c == '\n')
            break;
    }

    if (ret <= 0 && buffer != NULL)
    {
        free(buffer);
        *lineptr = NULL;
        *n = 0;
    }
    else
    {
        assign_lineptr(lineptr, n, buffer, ret);
    }

    return ret;
}

