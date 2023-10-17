#include "shell.h"

void help(char *command);

/**
 * help - Displays help information for a specific shellby command.
 */
void help(char *command)
{
    if (command == NULL || strcmp(command, "help") == 0) {
        char *msg = "Shellby\nThese shell commands are defined internally.\n";
        write(STDOUT_FILENO, msg, strlen(msg));

        msg = "Type 'help' to see this list.\nType 'help [COMMAND]' to find out more about a specific command.\n";
        write(STDOUT_FILENO, msg, strlen(msg));

        msg = "  alias      - Handles aliases.\n";
        write(STDOUT_FILENO, msg, strlen(msg));
        msg = "  cd         - Changes the current directory.\n";
        write(STDOUT_FILENO, msg, strlen(msg));
        msg = "  exit       - Exits the shell.\n";
        write(STDOUT_FILENO, msg, strlen(msg));
        msg = "  env        - Displays environment variables.\n";
        write(STDOUT_FILENO, msg, strlen(msg));
        msg = "  setenv     - Sets an environment variable.\n";
        write(STDOUT_FILENO, msg, strlen(msg));
        msg = "  unsetenv   - Unsets an environment variable.\n";
        write(STDOUT_FILENO, msg, strlen(msg));
    } else if (strcmp(command, "alias") == 0) {
        char *msg = "alias: alias [NAME[='VALUE'] ...]\n\tHandles aliases.\n";
        // Display help information for the 'alias' command.
        write(STDOUT_FILENO, msg, strlen(msg));
    } else if (strcmp(command, "cd") == 0) {
        char *msg = "cd: cd [DIRECTORY]\n\tChanges the current directory.\n";
        // Display help information for the 'cd' command.
        write(STDOUT_FILENO, msg, strlen(msg));
    } else if (strcmp(command, "exit") == 0) {
        char *msg = "exit: exit [STATUS]\n\tExits the shell.\n";
        // Display help information for the 'exit' command.
        write(STDOUT_FILENO, msg, strlen(msg));
    } else if (strcmp(command, "env") == 0) {
        char *msg = "env: env\n\tDisplays environment variables.\n";
        // Display help information for the 'env' command.
        write(STDOUT_FILENO, msg, strlen(msg));
    } else if (strcmp(command, "setenv") == 0) {
        char *msg = "setenv: setenv [VARIABLE] [VALUE]\n\tSets an environment variable.\n";
        // Display help information for the 'setenv' command.
        write(STDOUT_FILENO, msg, strlen(msg));
    } else if (strcmp(command, "unsetenv") == 0) {
        char *msg = "unsetenv: unsetenv [VARIABLE]\n\tUnsets an environment variable.\n";
        // Display help information for the 'unsetenv' command.
        write(STDOUT_FILENO, msg, strlen(msg));
    } else {
        char *msg = "Unknown command: Use 'help' to see the list of available commands.\n";
        write(STDOUT_FILENO, msg, strlen(msg));
    }
}
