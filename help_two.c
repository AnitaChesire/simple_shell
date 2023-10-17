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
    char *new_line = malloc((2 * read) + 1);
    if (!new_line)
    {
        free(*line);
        return;
    }

    char previous = ' ', current, next;
    size_t j = 0;

    for (size_t i = 0; i < read; i++)
    {
        current = (*line)[i];
        next = (i < read - 1) ? (*line)[i + 1] : ' ';

        if (current == ';' || current == '&' || current == '|')
        {
            if (previous != ' ')
                new_line[j++] = ' ';
            new_line[j++] = current;
            if (next != ' ')
                new_line[j++] = ' ';
        }
        else if (current == '#')
        {
            new_line[j++] = '\0';
            break;
        }
        else
        {
            new_line[j++] = current;
        }

        previous = current;
    }

    new_line[j] = '\0';
    free(*line);
    *line = new_line;
}

/**
 * get_new_len - Gets the new length of a line partitioned
 *               by ";", "||", "&&", or "#".
 * @line: The line to check.
 *
 * Return: The new length of the line.
 *
 * Description: Cuts short lines containing '#' comments with '\0'.
 */
ssize_t get_new_len(char *line)
{
    ssize_t new_len = 0;
    char previous = ' ', current, next;

    for (size_t i = 0; line[i]; i++)
    {
        current = line[i];
        next = (line[i + 1]) ? line[i + 1] : ' ';

        if (current == '#' && previous == ' ')
        {
            line[i] = '\0';
            break;
        }
        else if (current == ';' || current == '&' || current == '|')
        {
            if (previous != ' ')
                new_len++;
            if (next != ' ')
                new_len++;
        }
        else
        {
            new_len++;
        }

        previous = current;
    }

    return new_len;
}

/**
 * logical_ops - Checks a line for logical operators "||" or "&&".
 * @line: A pointer to the character to check in the line.
 * @new_len: Pointer to new_len in get_new_len function.
 */
void logical_ops(char *line, ssize_t *new_len)
{
    char previous = *(line - 1);
    char current = *line;
    char next = *(line + 1);

    if ((current == '&' && next == '&' && previous != ' ') ||
        (current == '|' && next == '|' && previous != ' '))
    {
        (*new_len)++;
    }
}

