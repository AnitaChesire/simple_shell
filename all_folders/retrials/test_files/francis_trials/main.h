#ifndef MAIN_H

#define MAIN_H

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

extern char **environ;

char *_getenv(const char *name);
int _unsetenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int pid_func(void);
int ppid(void);
char *custom_strtok(char *string, const char *delimiter);
void modify_env(char *buffer);
char *trim(char *str);
char *handle_comments(char *command);
void execute_command(const char *command);
char *adding_path(char **args);
char **tokenize(char *line, const char *delimiter, int *num_tokens);


int main(int ac __attribute__((unused)), char **av __attribute__((unused)));
int commands_reading(char **command);
char **command_tokens(char *command);
void free_the_tokens(char **tokens);
void exec(char **argv);
char *path_func(const char *command);
char *join(char **array, const char *delimiter);
char **split_func(const char *str, const char *delim);
void env_func(void);
char *without_getline(void);
void exit_status(char *prompt);

/*trials*/
void execmd(char **argv);



#endif
