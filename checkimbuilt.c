#include "shell.h"

void help_all(void);
void help_alias(void);
void help_cd(void);
void help_exit(void);
void help_help(void);

/**
 * help_all - Displays all possible built-in shellby commands.
 */
void help_all(void)
{
    char *msg =
        "Shellby\nThese shell commands are defined internally.\n"
        "Type 'help' to see this list.\nType 'help name' to find out "
        "more about the function 'name'.\n\n"
        "  alias    \talias [NAME[='VALUE'] ...]\n"
        "  cd       \tcd [DIRECTORY]\n"
        "  exit     \texit [STATUS]\n"
        "  env      \tenv\n"
        "  setenv   \tsetenv [VARIABLE] [VALUE]\n"
        "  unsetenv \tunsetenv [VARIABLE]\n";

    write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_alias - Displays information on the shellby built-in command 'alias'.
 */
void help_alias(void)
{
    char *msg =
        "alias: alias [NAME[='VALUE'] ...]\n"
        "    Handles aliases.\n\n"
        "    alias: Prints a list of all aliases, one per line, in the format NAME='VALUE'.\n"
        "    alias name [name2 ...]: prints the aliases name, name2, etc. one per line, in the form NAME='VALUE'.\n"
        "    alias NAME='VALUE' [...]: Defines an alias for each NAME whose VALUE is given. If NAME is already an alias, replace its value with VALUE.\n";

    write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_cd - Displays information on the shellby built-in command 'cd'.
 */
void help_cd(void)
{
    char *msg =
        "cd: cd [DIRECTORY]\n"
        "    Changes the current directory of the process to DIRECTORY.\n\n"
        "    If no argument is given, the command is interpreted as cd $HOME. If the argument '-' is given, the command is interpreted as cd $OLDPWD.\n\n"
        "    The environment variables PWD and OLDPWD are updated after a change of directory.\n";

    write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_exit - Displays information on the shellby built-in command 'exit'.
 */
void help_exit(void)
{
    char *msg =
        "exit: exit [STATUS]\n"
        "    Exits the shell.\n\n"
        "    The STATUS argument is the integer used to exit the shell. If no argument is given, the command is interpreted as exit 0.\n";

    write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_help - Displays information on the shellby built-in command 'help'.
 */
void help_help(void)
{
    char *msg =
        "help: help\n"
        "    See all possible Shellby built-in commands.\n\n"
        "    help [BUILTIN NAME]\n"
        "    See specific information on each built-in command.\n";

    write(STDOUT_FILENO, msg, _strlen(msg));
}

