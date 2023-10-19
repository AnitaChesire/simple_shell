#include "main.h"

/**
 * split_func- a helper function that splits a strijg into tokens
 *
 */

char **split_func(const char *str, const char *delim)
{
	size_t counter_tokens = 0;
	char **the_tokens = NULL;
	char *str_duplicate, *token, *duplicate_token;
	char **tokens;

	/* we make a copy as custom_strtok modifies the string*/
	str_duplicate = strdup(str);
	token = custom_strtok(str_duplicate, delim);

	while (token != NULL)
	{
		counter_tokens++;
		token = custom_strtok(NULL, delim);
	}
	the_tokens = malloc(sizeof(char *) * (counter_tokens + 1));
	if (the_tokens == NULL)
	{
		exit(EXIT_FAILURE);
	}

	/* this second time tokens copied to array*/
	counter_tokens = 0;
	str_duplicate = strdup(str);
	token = custom_strtok(str_duplicate, delim);
	while (token != NULL)
	{
		duplicate_token = strdup(token);
		if (duplicate_token == NULL)
		{
			exit(EXIT_FAILURE);
		}
		the_tokens[counter_tokens] = duplicate_token;
		counter_tokens++;
		token = custom_strtok(NULL, delim);
	}
	/* for the NULL terminator*/
	the_tokens[counter_tokens] = NULL; 

	free(str_duplicate);
	return (the_tokens);

}
