#include "main.h"
#define BUFSIZE 1024
/**
 *main - prints out unix shell cmd from user input
 *@argc: no. of arguments
 *@argv: pointer array arguments
 *Return: 0 if success and -1 on failure
 */
int main(int argc, char **argv)
{
	int status;
	char prompt[BUFSIZE], error_msg[BUFSIZE];
	pid_t pid;
	(void)argc;
	while (1)
	{
		/*user prompt*/
		printf("$ ");
		fflush(stdout);

		/*EOF*/
		if (!fgets(prompt, BUFSIZE, stdin))
		{
			printf("\n");
			break;
		}
		/*remove and replace new line*/
		prompt[strcspn(prompt, "\n")] = 0;

		argv = strtok_cmd(prompt);

		/*fork sec*/
		pid = fork();
		if (pid == -1)
		{
			perror("Error: fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			argv[0] = prompt;
			argv[1] = NULL;
			execve(prompt, argv, environ);
			snprintf(error_msg, BUFSIZE, "%s: execve failed", argv[0]);
			perror("error: execve failed");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
	return (0);
}
