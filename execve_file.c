#include "main.h"
int _strcmp(const char *s1, const char *s2);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
/**
* exec - function that executes a command
* @argv: an array containing the program command line arguments
* @program_name: the name of the program
*/
void exec(char **argv, char *program_name)
{
char *cmd = NULL, *true_cmd = NULL;
int line_num = 1, status;
pid_t pid;
if (argv)
{
cmd = argv[0];
if (_strcmp(cmd, "env") == 0)
{
env_func();
return;
}
else if (_strcmp(cmd, "setenv") == 0)
{
if (argv[1] == NULL || argv[2] == NULL || argv[3] != NULL)
{
fprintf(stderr, "%s: %d: usage: setenv VARIABLE\n", program_name, line_num);
return;
}
if (_setenv(argv[1], argv[2], 1) == -1)
{
perror("error in setenv");
return;
}
return;
}
else if (_strcmp(cmd, "unsetenv") == 0)
{
if (argv[1] == NULL || argv[2] != NULL)
{
fprintf(stderr, "%s: %d: usage: unsetenv VARIABLE\n", program_name, line_num);
return;
}
if (_unsetenv(argv[1]) == -1)
{
perror("There is an error in unsetenv");
return;
}
return;
}
true_cmd = path_func(cmd);
if (true_cmd == NULL)
{
fprintf(stderr, "%s: %d: %s: not found\n", program_name, line_num, argv[0]);
exit(2);
}
pid = fork();
if (pid == -1)
{
perror("There is an error in fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execve(true_cmd, argv, environ) == -1)
{
perror("execve");
exit(2);
}
}
else
{
if (waitpid(pid, &status, 0) == -1)
{
perror("waitpid");
exit(EXIT_FAILURE);
}
else if (WIFSIGNALED(status))
{
exit(WTERMSIG(status));
}
}
}
free(true_cmd);
}
/**
 * _strcmp - function that executes a command
 *@s1: first pointer
 *@s2: second pointer
 *Return: Always 0 (Success)
 */
int _strcmp(const char *s1, const char *s2)
{
while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
{
s1++;
s2++;
}
if (*s1 < *s2)
return (-1);
else if (*s1 > *s2)
return (1);
else
{
return (0);
}
}
/**
 * _setenv - sets environment variable
 * @name: name of variable
 * @value: value given
 * @overwrite: used to overwrite
 * Return: Always 0 (Success)
 */
int _setenv(const char *name, const char *value, int overwrite)
{
char *env_variable;
size_t size = strlen(name) + 1 + strlen(value) + 1;
if (getenv(name) != NULL && !overwrite)
return (0);
env_variable = (char *)malloc(size);
if (env_variable == NULL)
return (-1);
snprintf(env_variable, size, "%s=%s", name, value);
if (putenv(env_variable) != 0)
{
free(env_variable);
return (-1);
}
return (0);
}
/**
 * _unsetenv - unsets environment variable
 * @name: name of variable
 * Return: Always 0 (Success)
 */
int _unsetenv(const char *name)
{
if (unsetenv(name) != 0)
return (-1);
return (0);
}
