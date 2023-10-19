#include "main.h"

/**
 * 
 *exec fucntion - execute a program
 * 
 */

int main (void)
{
	int execute;
	pid_t pid;

	/* first argument - path of program to be executed
	 * second argument - string to represent the arguments
	 * to be passed to the program (we pass  "." to  the "ls" program to
	 * list the files in the current directory)
	 * third argument- NULL as we dont need to modify the environment
	 * in any way
	 */

	char *argv[] = {"/bin/ls", ".", NULL};

	pid = fork();

	if (pid == -1)
	{
		return (-1);

	}
	if (pid == 0) /* child process success*/
	{
		execute = execve(argv[0], argv, NULL);

		if (execute == -1)
		{
			perror("There is an error");
		}

	}
	/* refer to manual part of overwriting upon  process beig executed*/
	else /* parent process taking over after child exits*/
	{
		wait(NULL);
		printf("Execve is successful");
	}
	return (0);




}
