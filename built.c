#include "shell.h"

void help(char *command);

/**
 * help - Displays help information for a specific shellby command.
 */
void help(char *command)
{
    char *msg = NULL;

    if (command == NULL || strcmp(command, "help") == 0) {
        msg = "Shellby\nThese shell commands are defined internally.\n";
        msg += "Type 'help' to see this list.\nType 'help [COMMAND]' to find out more about a specific command.\n";
        msg += "  alias      - Handles aliases.\n";
        msg += "  cd         - Changes the current directory.\n";
        msg += "  exit       - Exits the shell.\n";
        msg += "  env        - Displays environment variables.\n";
        msg += "  setenv     - Sets an environment variable.\n";
        msg += "  unsetenv   - Unsets an environment variable.\n";
    }
    else if (strcmp(command, "alias") == 0) {
        msg = "alias: alias [NAME[='VALUE'] ...]\n\tHandles aliases.\n";
    }
    else if (strcmp(command, "cd") == 0) {
        msg = "cd: cd [DIRECTORY]\n\tChanges the current directory.\n";
    }
    else if (strcmp(command, "exit") == 0) {
        msg = "exit: exit [STATUS]\n\tExits the shell.\n";
    }
    else if (strcmp(command, "env") == 0) {
        msg = "env: env\n\tDisplays environment variables.\n";
    }
    else if (strcmp(command, "setenv") == 0) {
        msg = "setenv: setenv [VARIABLE] [VALUE]\n\tSets an environment variable.\n";
    }
    else if (strcmp(command, "unsetenv") == 0) {
        msg = "unsetenv: unsetenv [VARIABLE]\n\tUnsets an environment variable.\n";
    }
    else {
        msg = "Unknown command: Use 'help' to see the list of available commands.\n";
    }

    write(STDOUT_FILENO, msg, strlen(msg));
}
