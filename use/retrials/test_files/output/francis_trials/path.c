#include "main.h"
/**
 */
/*function*/
void execmd(char **argv)
{
        pid_t pid;
        int status;
	char *path, *ret, *dir, *file_path;

        if (argv)
        {
                pid = fork();

                if (pid == -1)
                {
                        perror("Error: couldn't fork");
                        exit(EXIT_FAILURE);
                }
                else if(pid == 0)
                {
			path = getenv("PATH");
			ret = malloc(strlen(path) + 1);
			strcpy(ret, path);

			dir = strtok(ret, ":");
			while (dir != NULL)
			{
				file_path = malloc(strlen(dir) + strlen(argv[0]) + 2);
				sprintf(file_path, "%s%s", dir, argv[0]);
				if (access(file_path, X_OK) == 0)
				{
					execve(argv[0], argv, NULL);
					perror("Error: couldn't exec command");
					exit(EXIT_FAILURE);
				}
				free(file_path);
				dir = strtok(NULL, ":");
                        }
                        free(ret);
			fprintf(stderr, "Error: cmd not found");
			exit(EXIT_FAILURE);
		}
                else
                {
			waitpid(pid, &status, WUNTRACED);
		}
        }
}
