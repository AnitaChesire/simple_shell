#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <ctype.h>
#include <limits.h>

/*function parameters*/
pid_t fork_child(char *buffer);
char error_eof(ssize_t prompt, char *buffer);
void file_path(char *command);
char *strtok(char *str, const char *delim);
int _setenv(const char *name, const char *value, int overwrite);
char *_getenv(const char *name);
int _unsetenv(const char *name);
int pid_func(void);
char *custom_strtok(char *string, const char *delimiter);
void modify_env(char *buffer);
char *trim(char *str);
char *handle_comments(char *command);
void execute_command(const char *command);
char *adding_path(char **args);

/* advanced tasks*/
char *without_getline();
void exit_status(char *prompt);
int main(int ac __attribute__((unused)), char **av __attribute__((unused)));
int commands_reading(char **command);
char **command_tokens(char *command);
void free_the_tokens(char **tokens);
void exec(char **argv);

/* struct*/
typedef struct node
{
	char *dir;
	struct node *next;
} node_t;
#endif
