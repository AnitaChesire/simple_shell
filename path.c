#include "main.h"
/**
* path_func - Finds the PATH for a given command.
* @cmd: The command to search for in PATH.
* Return: The full file path of the command, or NULL if not found.
*/
char *path_func(char *cmd)
{
struct stat path_buffer;
struct stat cmd_buffer;
char *path = getenv("PATH");
char *path_copy = NULL;
char *token = NULL;
char *result = NULL;
char *file_path;
if (path == NULL)
return (NULL);
path_copy = strdup(path);
if (path_copy == NULL)
{
exit(EXIT_FAILURE);
}
token = custom_strtok(path_copy, ":");
while (token != NULL)
{
file_path = path_builder(token, cmd);
if (stat(file_path, &path_buffer) == 0)
{
result = strdup(file_path);
if (result == NULL)
{
exit(EXIT_FAILURE);
}
free(file_path);
free(path_copy);
return (result);
}
free(file_path);
token = custom_strtok(NULL, ":");
}
if (stat(cmd, &cmd_buffer) == 0)
{
result = strdup(cmd);
}
free(path_copy);
return (result);
}
