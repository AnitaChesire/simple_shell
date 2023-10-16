#include "main.h"

/**
 * path_func - function that finds the PATH for a command
 * @cmd: the command to be searched
 * Return: the file PATH (or NULL if not found)
 */
char *path_func(char *cmd)
{
    struct stat path_buffer;
    char *the_path = NULL;
    char *the_path_token = NULL;

    the_path = getenv("PATH");

    char *the_path_dup, *the_file_path;

    if (the_path != NULL)
    {
        the_path_dup = strdup(the_path);

        if (the_path_dup == NULL)
        {
            perror("strdup");
            return NULL;
        }

        the_path_token = custom_strtok(the_path_dup, ":");

        while (the_path_token != NULL)
        {
            the_file_path = path_builder(the_path_token, cmd);

            if (the_file_path == NULL)
            {
                free(the_path_dup);
                return NULL;
            }

            if (stat(the_file_path, &path_buffer) == 0) /* if file path exists */
            {
                free(the_path_dup);
                return the_file_path;
            }
            else /* if not exist */
            {
                free(the_file_path);
                the_file_path = NULL;
                the_path_token = custom_strtok(NULL, ":"); /* find the next dir */
            }
        }

        free(the_path_dup);
    }

    return NULL; /* If no path is found for the command */
}

