#include "shell.h"

int num_len(int num);
char *_itoa(int num);
int create_error(char **args, int err);

/**
 * num_len - Counts the digit length of a number.
 */
int num_len(int num)
{
    int len = 1;
    unsigned int num1 = (num < 0) ? -num : num;

    while (num1 > 9)
    {
        len++;
        num1 /= 10;
    }

    if (num < 0)
        len++;

    return len;
}

/**
 * _itoa - Converts an integer to a string.
 */
char *_itoa(int num)
{
    int len = num_len(num);
    unsigned int num1 = (num < 0) ? -num : num;
    char *buffer = malloc(len + 1);

    if (!buffer)
        return NULL;

    buffer[len--] = '\0';

    if (num < 0)
        buffer[0] = '-';

    do {
        buffer[len--] = (num1 % 10) + '0';
        num1 /= 10;
    } while (num1 > 0);

    return buffer;
}

/**
 * create_error - Writes a custom error message to stderr.
 */
int create_error(char **args, int err)
{
    const char *error_message = NULL;

    switch (err)
    {
        case -1:
            error_message = error_env(args);
            break;
        case 1:
            error_message = error_1(args);
            break;
        case 2:
            if (*(args[0]) == 'e')
                error_message = error_2_exit(++args);
            else if (strpbrk(args[0], ";&|"))
                error_message = error_2_syntax(args);
            else
                error_message = error_2_cd(args);
            break;
        case 126:
            error_message = error_126(args);
            break;
        case 127:
            error_message = error_127(args);
            break;
    }

    if (error_message)
    {
        write(STDERR_FILENO, error_message, _strlen(error_message));
        free((char *)error_message);
    }

    return err;
}

