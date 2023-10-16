#include "main.h"

/**
 * custom_strtok - a custom strtok function
 * @string: the string to be tokenized
 * @delimiter: the delimiter
 * @reset: a flag to reset the internal state
 * Return: tokenized string
 */

char *custom_strtok(char *string, const char *delimiter, int reset)
{
    static char *the_final_token;

    if (reset) {
        the_final_token = NULL;
        return NULL;
    }

    if (string == NULL) {
        string = the_final_token;
    }

    if (string == NULL) {
        return (NULL);
    }

    string += strspn(string, delimiter);

    if (*string == '\0') {
        return (NULL);
    }

    if (*string == ';') {
        *the_final_token++ = *string++;
        *the_final_token = '\0';
        return (the_final_token - 1);
    }

    the_final_token = string + strcspn(string, delimiter);
    if (*the_final_token != '\0') {
        *the_final_token++ = '\0';
    }

    return (string);
}

