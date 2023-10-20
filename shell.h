#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

#define _CMD_NOT_EXISTS_ "Not found"
#define _EACCES_ "Permission denied"
#define _ENOENT_ "No such file or directory"
#define _ILLEGAL_NUMBER_ "Illegal number"

typedef struct __attribute__((__packed__))
{
	int argc;
	char **argv;
	int pid;
	int num_cmd;
	int cur_path;
	int it_mode;
	int code_stat;
	int error_digit;
	char *cmd;
	char *cmd_path;
	char *buf;
	char **the_arguments;
	char *env;
} shellinfo_t;

typedef struct __attribute__((__packed__))
{
	char *msg;
	int password;
} issue_t;

typedef struct __attribute__((__packed__))
{
	char *cmd;
	void (*func)(shellinfo_t *ourtype, char **arguments);
} sysFunction_t;

void begin(shellinfo_t *ourtype);
void additional_error(shellinfo_t *ourtype, char *more);
void initiate_prompt(shellinfo_t *ourtype);
void get_input(shellinfo_t *ourtype);
void issue(shellinfo_t *ourtype);
void binary_exit(shellinfo_t *ourtype, char **args);
void binary_env(shellinfo_t *ourtype, char **args);
void evaluate(char **args, shellinfo_t *ourtype, char *buffer);
int number(int num);
int main(int argc, char **argv);
int is_numeric(unsigned int number);
int has_letter(char *string);
int write_character(char character);
int display(char *message);
int display_error(char *message);
int write_character_to_fd(char cha, int file_des);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int output_to_fd(char *message, int file_des);
int is_executable(char *name);
int is_file(char *file_name);
int handle_numbers(shellinfo_t *ourtype, char *argument);
int get_current_dir(char *command, char **argu, char *buff,
shellinfo_t *ourtype);
int system_function(shellinfo_t *ourtype, char **args);
int verify_builtin(shellinfo_t *ourtype, char **args);
int _atoi(char *s);
char *stringify(int number);
char **tokenize_words(char *string, const char *del);
char *merge_words(char *w1, char *w2, char *w3, const char *del);
char *parse_prompt(void);
char *exchange(shellinfo_t *ourtype, int *id, char *word);
char *handle_pattern(shellinfo_t *ourtype, char *words);
char *subtitute_value(shellinfo_t *ourtype, int *id, char *str);
char *select_message(shellinfo_t ourtype);
char *more_error(shellinfo_t *ourtype, char *more);
char *get_env(const char *variable);
char *choose(char *dir_name, shellinfo_t *ourtype);
char *sub_env(shellinfo_t *ourtype, char *envi_var);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void signature_handler(int num);
void run(char *cmd, char **argu, shellinfo_t *ourtype, char *buffer);
void release_memory(void *pointer);
void release_memory_pointer(void **pointer);
void fetch_full_env(void);
void is_curr_path(char *pat, shellinfo_t *ourtype);
void pattern_analysis(shellinfo_t *ourtype, char **args);

#endif
