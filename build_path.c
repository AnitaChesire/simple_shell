#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * path_builder - a function to help in building the file path
 * @dir: the directories
 * @command: the command name
 * Return: the file path of the directories (or NULL on failure)
 */
char *path_builder(const char *dir, const char *command)
{
	size_t dir_length, cmd_len;
	char *the_file_path;

    if (dir == NULL || command == NULL) {
        return NULL;
    }

    dir_length = strlen(dir);
    cmd_len = strlen(command);

    the_file_path = (char *)malloc(dir_length + cmd_len + 2);

    if (the_file_path == NULL) {
        return NULL;
    }

    snprintf(the_file_path, dir_length + cmd_len + 2, "%s/%s", dir, command);

    return the_file_path;
}

