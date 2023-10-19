#ifndef MAIN_H

#define MAIN_H

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>


char *_getenv(const char *name);
int _unsetenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int pid_func(void);
int ppid(void);
char *_strtok(char *string, const char *delimiter);
void modify_env(char *buffer);
char *trim(char *str);
char *command();
void unset_env(char **args);
void set_env(char **args);
char *strtok_r_func();


typedef struct node {
	char *dir;
	struct node *next;
} node_t;

node_t *path_list_func(void);

/*alias our_aliases[] = {
	{"ls", "ls - color=auto"},
	{"ll", "ls -aLF"};
	{"la", "ls -A"};
	{NULL,NULL},
} our_aliases;*/


#endif 
