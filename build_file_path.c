#include "main.h"
/**
* path_builder - Build the file path using a directory and a command.
* @dir: The directory.
* @command: The command name.
* Return: The constructed file path.
*/
char *path_builder(const char *dir, const char *command)
{
int dir_length = strlen(dir);
int cmd_length = strlen(command);
char *file_path = malloc(dir_length + cmd_length + 2);
if (file_path == NULL)
{
perror("malloc failed in path_builder");
exit(EXIT_FAILURE);
}
sprintf(file_path, "%s/%s", dir, command);
return (file_path);
}
