#include "shell.h"

void handle_line(char **line, ssize_t read);
ssize_t get_new_len(char *line);
void logical_ops(char *line, ssize_t *new_len);

/**
 * handle_line - Partitions a line read from standard input as needed.
 * @line: A pointer to a line read from standard input.
 * @read: The length of line.
 *
 * Description: Spaces are inserted to separate ";", "||", and "&&".
 *              Replaces "#" with '\0'.
 */
void handle_line(char **line, ssize_t read)
{
    size_t i, j;
    char *old_line, *new_line;
    ssize_t new_len;

    new_len = get_new_len(*line);
    if (new_len == read - 1)
        return;

    new_line = malloc(new_len + 1);
    if (!new_line)
        return;

    j = 0;
    old_line = *line;

    for (i = 0; old_line[i]; i++)
    {
        new_line[j++] = old_line[i];
        if (old_line[i] == ';')
        {
            if (i != 0 && old_line[i - 1] != ' ')
                new_line[j++] = ' ';
            if (old_line[i + 1] != ' ' && old_line[i + 1] != ';')
                new_line[j++] = ' ';
        }
    }

    new_line[j] = '\0';

    free(*line);
    *line = new_line;
}

ssize_t get_new_len(char *line)
{
    size_t i;
    ssize_t new_len = 0;
    char current, next;

    for (i = 0; line[i]; i++)
    {
        current = line[i];
        next = line[i + 1];

        if (i != 0 && current == ';')
        {
            if (next == ';' && line[i - 1] != ' ' && line[i - 1] != ';')
            {
                new_len += 2;
                continue;
            }
            else if (line[i - 1] == ';' && next != ' ')
            {
                new_len += 2;
                continue;
            }
            if (line[i - 1] != ' ')
                new_len++;
            if (next != ' ')
                new_len++;
        }

        if (current == '&')
        {
            if (next == '&' && line[i - 1] != ' ')
                new_len++;
            else if (line[i - 1] == '&' && next != ' ')
                new_len++;
        }
        else if (current == '|')
        {
            if (next == '|' && line[i - 1] != ' ')
                new_len++;
            else if (line[i - 1] == '|' && next != ' ')
                new_len++;
        }

        new_len++;
    }

    return new_len;
}

