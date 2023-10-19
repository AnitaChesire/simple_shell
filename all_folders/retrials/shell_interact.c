#include "main.h"
/**
 * execute - executes the cmd that users enter
 * @command: for non interactive mode
 * @argv: arguments entered by user
 */
void execute(char *command, char **argv)
{
	pid_t pid;
	int status;
	char *path, *path_copy, *path_token, *path_command;

	/*handle exit task 4*/
	if (strcmp(command, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}

	if (strcmp(command, "env") == 0)
	{
		char **env = environ;
		while (*env)
		{
			printf("%s\n", *env++);
		}
		return;
	}

	/*fork*/
	pid = fork();
	if (pid == -1)
	{
		perror("Error: couldnt fork\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(command, argv, environ);
		
		/*task 3: PATH*/
		path = getenv("PATH");
		path_copy = strdup(path);
		path_token = strtok(path_copy, ":");
		path_command = (char *)malloc(strlen(path_token) + strlen(command) + 2);
		while (path_token != NULL)
		{
			sprintf(path_command, "%s%s", path_token, command);
			execve(path_command, argv, environ);
			path_token = strtok(NULL, ":");
		}
		printf("Error: %s command not found\n", command);
		exit(EXIT_FAILURE);
	}
	else
	{
		do{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
