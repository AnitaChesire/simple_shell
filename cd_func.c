#include "main.h"

int cd_func(char *argv[])
{
    char *home_dir = getenv("HOME");
    char *current_dir = getcwd(NULL, 0);
    char *previ_dir = getenv("OLDPWD");

    if (argv[0] == NULL || strcmp(argv[0], "~") == 0)
    {
        if (chdir(home_dir) == -1)
        {
            perror("chdir");
            free(current_dir);
            return -1;
        }
    }
    else if (strcmp(argv[0], "-") == 0)
    {
        if (previ_dir == NULL)
        {
            write(STDERR_FILENO, "OLDPWD not set\n", 16);
            free(current_dir);
            return -1;
        }
        if (chdir(previ_dir) == -1)
        {
            perror("chdir");
            free(current_dir);
            return -1;
        }
        write(STDOUT_FILENO, previ_dir, strlen(previ_dir));
        write(STDOUT_FILENO, "\n", 1);
    }
    else
    {
        if (chdir(argv[0]) == -1)
        {
            perror("chdir");
            free(current_dir);
            return -1;
        }
    }

    setenv("PWD", current_dir, 1);
    setenv("OLDPWD", current_dir, 1);
    free(current_dir);
    return 0;
}

