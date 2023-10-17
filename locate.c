#include "shell.h"

char *get_location(const char *command);
list_t *get_path_dir(const char *path);

/**
 * custom_strjoin - Concatenates two strings with a delimiter.
 * @str1: The first string.
 * @str2: The second string.
 * @delimiter: The delimiter to insert between the strings.
 *
 * Return: A newly allocated string containing the concatenated result.
 */
char *custom_strjoin(const char *str1, const char *str2, char delimiter)
{
    size_t len1 = _strlen(str1);
    size_t len2 = _strlen(str2);
    char *result = malloc(len1 + len2 + 2);
    
    if (result)
    {
        _strcpy(result, str1);
        result[len1] = delimiter;
        _strcpy(result + len1 + 1, str2);
    }
    
    return result;
}

/**
 * custom_strsplit - Splits a string into an array of substrings based on a delimiter.
 * @str: The string to split.
 * @delimiter: The delimiter character.
 *
 * Return: An array of strings (char *) or NULL on failure.
 */
char **custom_strsplit(const char *str, char delimiter)
{
    size_t i, j, k, num_tokens;
    char **tokens = NULL;

    if (str == NULL)
        return NULL;

    num_tokens = 1;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == delimiter)
            num_tokens++;
    }

    tokens = malloc(sizeof(char *) * (num_tokens + 1));
    if (tokens == NULL)
        return NULL;

    i = 0;
    j = 0;
    num_tokens = 0;

    while (str[i] != '\0')
    {
        if (str[i] == delimiter)
        {
            tokens[num_tokens] = malloc(j + 1);
            if (tokens[num_tokens] == NULL)
            {
                for (i = 0; i < num_tokens; i++)
                    free(tokens[i]);
                free(tokens);
                return NULL;
            }

            for (k = 0; k < j; k++)
                tokens[num_tokens][k] = str[i - j + k];
            tokens[num_tokens][j] = '\0';
            num_tokens++;
            j = 0;
        }
        else
        {
            j++;
        }

        i++;
    }

    tokens[num_tokens] = malloc(j + 1);
    if (tokens[num_tokens] == NULL)
    {
        for (i = 0; i <= num_tokens; i++)
            free(tokens[i]);
        free(tokens);
        return NULL;
    }

    for (k = 0; k < j; k++)
        tokens[num_tokens][k] = str[i - j + k];
    tokens[num_tokens][j] = '\0';

    tokens[num_tokens + 1] = NULL;
    return tokens;
}

char *get_location(const char *command)
{
	struct stat st;
	list_t *dirs;
	char *temp;
	char *path

    path = _getenv("PATH");
    if (!path || !(*path))
        return NULL;

    dirs = get_path_dir(path);

    while (dirs)
    {
        temp = custom_strjoin(dirs->dir, command, '/');
        if (!temp)
        {
            free_list(dirs);
            return NULL;
        }

        
        if (stat(temp, &st) == 0)
        {
            free_list(dirs);
            return temp;
        }

        free(temp);
        dirs = dirs->next;
    }

    free_list(dirs);

    return NULL;
}

list_t *get_path_dir(const char *path)
{
	list_t *head;
	int index, i;
	char **dirs;

    dirs = custom_strsplit(path, ':');
    if (!dirs)
        return NULL;

    head = NULL;

    for (index = 0; dirs[index]; index++)
    {
        if (add_node_end(&head, dirs[index]) == NULL)
        {
            free_list(head);
            for (i = 0; dirs[i]; i++)
                free(dirs[i]);
            free(dirs);
            return NULL;
        }
        free(dirs[index]);
    }

    free(dirs);

    return head;
}

