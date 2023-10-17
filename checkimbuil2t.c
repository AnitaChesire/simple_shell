#include "shell.h"

// Function prototypes
void displayHelp(const char *command, const char *description);

/**
 * help_env - Displays information on the 'env' command.
 */
void help_env(void)
{
    const char *msg = "env: env\n"
                     "\tPrints the current environment.\n";
    displayHelp("env", msg);
}

/**
 * help_setenv - Displays information on the 'setenv' command.
 */
void help_setenv(void)
{
    const char *msg = "setenv: setenv [VARIABLE] [VALUE]\n"
                     "\tInitializes a new environment variable or modifies an existing one.\n"
                     "\tUpon failure, prints a message to stderr.\n";
    displayHelp("setenv", msg);
}

/**
 * help_unsetenv - Displays information on the 'unsetenv' command.
 */
void help_unsetenv(void)
{
    const char *msg = "unsetenv: unsetenv [VARIABLE]\n"
                     "\tRemoves an environmental variable.\n"
                     "\tUpon failure, prints a message to stderr.\n";
    displayHelp("unsetenv", msg);
}

/**
 * displayHelp - Helper function to display command-specific help.
 * @param command: The name of the command.
 * @param description: The description of the command.
 */
void displayHelp(const char *command, const char *description)
{
    const char *helpHeader = "%s: %s\n";
    write(STDOUT_FILENO, helpHeader, command, command);
    write(STDOUT_FILENO, description, _strlen(description));
}
