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

#define COMMAND_MAX_LENGTH 1024

extern char **environ;

char *_getenv(const char *name);
int _unsetenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int pid_func(void);
int ppid(void);
char *custom_strtok(char *string, const char *delimiter);
void modify_env(char *buffer);
char *handle_comments(char *command);
char *find_file_path(char *path, char *cmd);

int main(int ac __attribute__((unused)), char **av __attribute__((unused)));
char *path_func(char *cmd);
char *path_builder(const char *dir, const char *command);
void exec(char **argv, char *program_name);
char **tokenize_command(char *command);
void env_func(void);
char **strtok_cmd(char *command);
int isatty(int fd);
int cd_func(char *argv[]);
size_t _strlen(const char *str);
int custom_strcmp(const char *s1, const char *s2);

#endif
