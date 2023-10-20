#include "shell.h"
/**
 * begin - A function that handles the mode of the shell.
 * Description: Mode can be 1 or 0.
 * @ourtype: Structure of information about the shell.
 * Return: Nothing upon success.
 */
void begin(shellinfo_t *ourtype)
{
	initiate_prompt(ourtype);
}

/**
 * pattern_analysis - A function that collects a pattern and helps
 * users to analyze such pattern.
 * @ourtype: input parameter value.
 * @args: argument to analyze.
 * Return: void or nothing upon success.
 */
void pattern_analysis(shellinfo_t *ourtype, char **args)
{
	int k;

	for (k = 0; args[k] != NULL; k++)
	{
		args[k] = handle_pattern(ourtype, args[k]);
	}
}
