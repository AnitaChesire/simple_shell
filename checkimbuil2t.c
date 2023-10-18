#include "shell.h"

void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_history(void);


/**
 * help_env - Displays information on the shellby built-in command 'env'.
 */
void help_env(void)
{
    char *msg = "env: env\n\tPrints the current environment.\n";
    write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_setenv - Displays information on the shellby built-in command 'setenv'.
 */
void help_setenv(void)
{
    char *msg = "setenv: setenv [VARIABLE] [VALUE]\n"
                "\tInitializes a new environment variable or modifies an existing one.\n"
                "\tUpon failure, prints an error message to stderr.\n";
    write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_unsetenv - Displays information on the shellby built-in command 'unsetenv'.
 */
void help_unsetenv(void)
{
    char *msg = "unsetenv: unsetenv [VARIABLE]\n"
                "\tRemoves an environmental variable.\n"
                "\tUpon failure, prints an error message to stderr.\n";
    write(STDOUT_FILENO, msg, _strlen(msg));
}

