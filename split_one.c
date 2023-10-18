#include "shell.h"

int token_len(char *str, char *delim);
int count_tokens(char *str, char *delim);
char **_strtok(char *line, char *delim);

/**
 * _strtok - Tokenizes a string.
 * @line: The string.
 * @delim: The delimiter character to tokenize the string by.
 *
 * Return: A pointer to an array containing the tokenized words.
 */
char **_strtok(char *line, char *delim)
{
    char **ptr = NULL;
    int tokens = 0;
    int index = 0;
    int word_len;

    while (line[index]) {
        while (line[index] && line[index] == *delim)
            index++;

        if (!line[index])
            break;

         word_len = 0;
        while (line[index + word_len] && line[index + word_len] != *delim)
            word_len++;

        if (word_len > 0) {
            ptr = realloc(ptr, (tokens + 1) * sizeof(char *));
            ptr[tokens] = malloc(word_len + 1);
            if (!ptr) 
	    {
                      return NULL;
            }
            strncpy(ptr[tokens], &line[index], word_len);
            ptr[tokens][word_len] = '\0';
            tokens++;
        }

        index += word_len;
    }

    ptr = realloc(ptr, (tokens + 1) * sizeof(char *));
    ptr[tokens] = NULL;

    return ptr;
}

/**
 * token_len - Locates the delimiter index marking the end
 *             of the first token contained within a string.
 * @str: The string to be searched.
 * @delim: The delimiter character.
 *
 * Return: The delimiter index marking the end of
 *         the intitial token pointed to be str.
 */

int token_len(char *str, char *delim)
{
    int index = 0, len = 0;

    for (index = 0; str[index] && str[index] != *delim; index++) {
        len++;
    }

    return len;
}

/**
 * count_tokens - Counts the number of delimited
 *                words contained within a string.
 * @str: The string to be searched.
 * @delim: The delimiter character.
 *
 * Return: The number of words contained within str.
 */

int count_tokens(char *str, char *delim)
{
    int tokens = 0;
    int index = 0;

    while (str[index]) {
        while (str[index] == *delim)
            index++;

        if (str[index] != '\0') {
            tokens++;
            index += token_len(str + index, delim);
        }
    }

    return tokens;
}

