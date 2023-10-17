#include "shell.h"

int token_len(char *str, char *delim);
int count_tokens(char *str, char *delim);
char **_strtok(char *line, char *delim);

/**
 * token_len - Finds the length of the token up to the delimiter.
 * @str: The string to search.
 * @delim: The delimiter character.
 *
 * Return: The length of the token up to the delimiter.
 */
int token_len(char *str, char delim)
{
    int len = 0;
    while (str[len] && str[len] != delim)
    {
        len++;
    }
    return len;
}
/**
 * count_tokens - Counts the number of delimited words in a string.
 * @str: The string to search.
 * @delim: The delimiter character.
 *
 * Return: The number of words in the string.
 */
int count_tokens(char *str, char delim)
{
    int tokens = 0;
    int is_token = 0;  // Flag to track if we're inside a token
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == delim)
        {
            is_token = 0; // We're outside a token
        }
        else if (!is_token)
        {
            is_token = 1; // We're inside a new token
            tokens++;
        }
    }
    return tokens;
}

/**
 * _strtok - Tokenizes a string.
 * @line: The string.
 * @delim: The delimiter character to tokenize the string by.
 *
 * Return: A pointer to an array containing the tokenized words.
 */
char **_strtok(char *line, char delim)
{
    char **ptr = NULL;
    int t, i, letters, index = 0, tokens = 0;

    tokens = count_tokens(line, delim);
    if (tokens == 0)
        return NULL;

    ptr = malloc(sizeof(char *) * (tokens + 1));
    if (!ptr)
        return NULL;

    t = 0;
    while (line[index] && t < tokens)
    {
        while (line[index] == delim)
            index++;

        letters = token_len(line + index, delim);

        ptr[t] = malloc(letters + 1);
        if (!ptr[t])
        {
            for (i = 0; i < t; i++)
                free(ptr[i]);
            free(ptr);
            return NULL;
        }

        strncpy(ptr[t], line + index, letters);
        ptr[t][letters] = '\0';

        index += letters;
        t++;
    }

    ptr[t] = NULL;
    return ptr;
}

