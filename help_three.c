#include "shell.h"

void free_args(char **args, char **front);
char *get_pid(void);
char *get_env_value(const char *var);
void variable_replacement(char **line, int *exe_ret);

/**
 * free_args - Frees up memory taken by args.
 * @args: A null-terminated double pointer containing commands/arguments.
 * @front: A double pointer to the beginning of args.
 */
void free_args(char **args, char **front)
{
    char **temp = args;

    while (*temp) {
        free(*temp);
        temp++;
    }

    free(front);
}

/**
 * get_pid - Gets the current process ID.
 *
 * Return: The current process ID as a string or NULL on failure.
 */
char *get_pid(void)
{
    char *pid = _itoa(getpid());
    return pid;
}

/**
 * get_env_value - Gets the value corresponding to an environmental variable.
 * @var: The environmental variable to search for.
 *
 * Return: If the variable is not found - an empty string.
 *         Otherwise - the value of the environmental variable.
 */
char *get_env_value(const char *var)
{
    char *value = getenv(var);
    if (value == NULL) {
        return "";
    }
    return value;
}

/**
 * variable_replacement - Handles variable replacement.
 * @line: A double pointer containing the command and arguments.
 * @exe_ret: A pointer to the return value of the last executed command.
 *
 * Description: Replaces $$ with the current PID, $? with the return value
 *              of the last executed program, and environmental variables
 *              preceded by $ with their corresponding value.
 */
void variable_replacement(char **line, int *exe_ret)
{
    char *old_line = *line;
    char *var, *value, *pid, *ret;
    int k, i, j;
     char *new_line = malloc(2 * _strlen(old_line) + 1);

    if (new_line == NULL) {
        return;
    }

    i = 0;
    j = 0;

    while (old_line[i]) {
        if (old_line[i] == '$' && old_line[i + 1]) {
            if (old_line[i + 1] == '$') {
                pid = get_pid();
                _strcpy(&new_line[j], pid);
                j += _strlen(pid);
                free(pid);
                i += 2;
            } else if (old_line[i + 1] == '?') {
                ret = _itoa(*exe_ret);
                _strcpy(&new_line[j], ret);
                j += _strlen(ret);
                free(ret);
                i += 2;
            } else {
                k = i + 1;
                while (old_line[k] && old_line[k] != '$' && old_line[k] != ' ') {
                    k++;
                }
                var = strndup(&old_line[i + 1], k - i - 1);
                value = get_env_value(var);
                _strcpy(&new_line[j], value);
                j += _strlen(value);
                free(var);
                i = k;
            }
        } else {
            new_line[j] = old_line[i];
            i++;
            j++;
        }
    }

    new_line[j] = '\0';
    free(*line);
    *line = new_line;
}

