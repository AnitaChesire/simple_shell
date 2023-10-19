#include "main.h"

/**
 * 
 *exec -fucntion to execute a program
 * 
 */

int exec(int ac, char *argv[])
{
	int execute;
	pid_t pid;
	char *av[] = {"/bin/ls", ".", NULL};

	(void) ac;

	/* first argument - path of program to be executed
	 * second argument - string to represent the arguments
	 * to be passed to the program (we pass  "." to  the "ls" program to
	 * list the files in the current directory)
	 * third argument- NULL as we dont need to modify the environment
	 * in any way
	 */

	pid = fork();

	if (pid == -1)
	{
		return (-1);

	}
	if (pid == 0) /* child process success*/
	{
		execute = execve(argv[0], av, NULL);

		if (execute == -1)
		{
			perror("There is an error");
		}

	}
	/* refer to manual part of overwriting upon  process being executed*/
	else /* parent process taking over after child exits*/
	{
		wait(NULL);
		printf("Execve is successful");
	}
	return (0);




}
