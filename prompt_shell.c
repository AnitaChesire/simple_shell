#include "shell.h"
/**
 * get_input - A function that serves as the prompt for the simple
 * shell program.
 * @ourtype: defined struct of shell general information as defined
 * in the header file.
 */
void get_input(shellinfo_t *ourtype)
{
	if (ourtype->it_mode == 0)
	{
		return;
	}

	display("$ ");
}

/**
 * initiate_prompt - A function that represents the main loop of the
 * interactive prompt.
 * @ourtype: Struct of shell general information.
 * Return: Buffer obtained from stdin or NULL if EOF was found.
 */
void initiate_prompt(shellinfo_t *ourtype)
{
	char *buffer, **args, *env_path;

	signal(SIGINT, signature_handler);
	while (1)
	{
		get_input(ourtype);

		env_path = get_env("PATH");
		is_curr_path(env_path, ourtype);

		ourtype->env = env_path;
		buffer = parse_prompt();
		if (buffer == NULL)
		{
			display(ourtype->it_mode == 1 ? "exit\n" : "");
			free(env_path);
			break;
		}
		ourtype->num_cmd++;
		if (buffer[0] != '\n')
		{
			args = tokenize_words(buffer, " \t\n");

			ourtype->the_arguments = args;
			ourtype->buf = buffer;
			pattern_analysis(ourtype, args);
			evaluate(args, ourtype, buffer);

			release_memory_pointer((void *) args);
		}
		release_memory((void *) buffer);
		release_memory((void *) env_path);
	}

}

/**
 * parse_prompt - A function that uses the getline function to read
 * the line of the prompt.
 * Description: it will also handle the end of file initiated by
 * pressing ctrl D.
 * Return: Buffer readed or NULL after freeing the read prompt if EOF
 */
char *parse_prompt(void)
{
	char *buffer = NULL;
	int rapt;
	size_t size;

	rapt = getline(&buffer, &size, stdin);

	if (rapt == EOF)
	{
		release_memory((void *) buffer);
		return (NULL);
	}

	return (buffer);
}
