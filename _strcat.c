#include "shell.h"
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUFFER_SIZE 120

void *_realloc(void *ptr, size_t old_size, size_t new_size);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
    if (new_size == old_size)
        return ptr;

    void *mem = malloc(new_size);

    if (mem == NULL)
    {
        if (ptr != NULL)
            free(ptr);
        return NULL;
    }

    if (ptr != NULL)
    {
        size_t copy_size = (new_size < old_size) ? new_size : old_size;
        memcpy(mem, ptr, copy_size);
        free(ptr);
    }

    return mem;
}

void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
    if (*lineptr == NULL || b > *n)
    {
        // Allocate new memory if needed
        size_t new_size = (b > INITIAL_BUFFER_SIZE) ? b : INITIAL_BUFFER_SIZE;
        *lineptr = _realloc(*lineptr, *n, new_size);
        *n = new_size;
    }

    strcpy(*lineptr, buffer);
    free(buffer);
}

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
            size_t new_size = (*n == 0) ? INITIAL_BUFFER_SIZE : (*n) * 2;
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
