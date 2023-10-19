#ifndef MAIN_H
#define MAIN_H

/*header libs*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include <fcntl.h>

/*function prototypes*/
extern char **environ;
/*char user_input(my_shell *);
int free_me(void **ptr);
char *strtok_sp(char *token, const char *delim);
unsigned int is_delim(char s, char *delim);
char *_strncpy(char *destination, char *source, int n);
char *my_strchr(char *src, char l);
char *my_strncat(char *destination, char *source, int n);
int my_atoi(char *str);
int shell_interactive(my_shell *);*/
/*main files*/
int main(int argc, char **argv);
/*void execute(char *command, char **argv);*/
void execute(char **args, int input_fd, int output_fd);
void execute_pipe(char **cm1, char **cm2);
void print_env();
char *get_cmd_path(char *cmd, char *env_path);
char **slice(char **tokens, int start, int end);
int no_tokens(char **tokens);

/*errors function*/
/*Size division*/
#define BUFSIZE 1024

/*struct division*/
typedef struct unix_info
{
	char *environ;
	char *args;
	char argv;
	char *path_line;
	char env;
	int status;
	int argc;
	int *ptr;
	int readfd;
} my_shell;

typedef struct built_funct
{
	char *type;
	int (*func)(my_shell *);
} simple_command;
#endif
