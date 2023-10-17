#include "shell.h"

int shellby_alias(char **args, char **front);
void set_alias(char *var_name, char *value);
void print_alias(alias_t *alias);
char **replace_aliases(char **args);

/**
 * shellby_alias - Builtin command that handles aliases.
 *
 * @args: An array of arguments.
 * @front: A double pointer to the beginning of args.
 *
 * Returns: 0 if successful, -1 if an error occurs.
 */
int shellby_alias(char **args, char **front)
{
    alias_t *temp = aliases;
    int ret = 0;

    if (!args[0])
    {
        // Print all aliases
        while (temp)
        {
            print_alias(temp);
            temp = temp->next;
        }
        return ret;
    }

    for (int i = 0; args[i]; i++)
    {
        temp = aliases;
        char *value = strchr(args[i], '=');

        if (!value)
        {
            // Print a specific alias
            while (temp)
            {
                if (strcmp(args[i], temp->name) == 0)
                {
                    print_alias(temp);
                    break;
                }
                temp = temp->next;
            }
            if (!temp)
                ret = create_error(args + i, 1);
        }
        else
            set_alias(args[i], value);
    }
    return ret;
}

/**
 * set_alias - Set an alias or update an existing alias.
 *
 * @var_name: Name of the alias.
 * @value: Value of the alias. It starts with '='.
 */
void set_alias(char *var_name, char *value)
{
    alias_t *temp = aliases;
    int len, j, k;
    char *new_value;

    *value = '\0';
    value++;

    len = strlen(value) - strspn(value, "'\"");
    new_value = (char *)malloc(sizeof(char) * (len + 1));

    if (!new_value)
        return;

    for (j = 0, k = 0; value[j]; j++)
    {
        if (value[j] != '\'' && value[j] != '"')
            new_value[k++] = value[j];
    }
    new_value[k] = '\0';

    while (temp)
    {
        if (strcmp(var_name, temp->name) == 0)
        {
            free(temp->value);
            temp->value = new_value;
            break;
        }
        temp = temp->next;
    }

    if (!temp)
        add_alias_end(&aliases, var_name, new_value);
}

/**
 * print_alias - Prints the alias in the format name='value'.
 *
 * @alias: Pointer to an alias.
 */
void print_alias(alias_t *alias)
{
    int len = strlen(alias->name) + strlen(alias->value) + 4;
    char *alias_string = (char *)malloc(sizeof(char) * (len + 1);

    if (!alias_string)
        return;

    strcpy(alias_string, alias->name);
    strcat(alias_string, "='");
    strcat(alias_string, alias->value);
    strcat(alias_string, "'\n");

    write(STDOUT_FILENO, alias_string, len);
    free(alias_string);
}

/**
 * replace_aliases - Replace arguments with their alias values.
 *
 * @args: 2D pointer to the arguments.
 *
 * Returns: 2D pointer to the arguments with aliases replaced.
 */
char **replace_aliases(char **args)
{
    if (strcmp(args[0], "alias") == 0)
        return args;

    alias_t *temp;

    for (int i = 0; args[i]; i++)
    {
        temp = aliases;

        while (temp)
        {
            if (strcmp(args[i], temp->name) == 0)
            {
                char *new_value = (char *)malloc(strlen(temp->value) + 1);

                if (!new_value)
                {
                    free_args(args, args);
                    return NULL;
                }

                strcpy(new_value, temp->value);
                free(args[i]);
                args[i] = new_value;
                break;
            }
            temp = temp->next;
        }
    }

    return args;
}
