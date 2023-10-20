#include "shell.h"
/**
 * sub_env - A function used for replacing env variables.
 * @ourtype: input as parameter.
 * @envi_var: environment variable input.
 * Return: pointer to the string.
 */
char *sub_env(shellinfo_t *ourtype, char *envi_var)
{
	char *envi;

	(void) ourtype;

	envi = get_env(envi_var);
	if (envi != NULL)
	{
		return (envi);
	}

	return (NULL);
}

/**
 * subtitute_value - A Function that helps with replacing a pattern value.
 * @ourtype: a struct parameter called info.
 * @id: identifires the position of the value.
 * @str: string input.
 * Return: pointer the string.
 */
char *subtitute_value(shellinfo_t *ourtype, int *id, char *str)
{
	char *paramt;
	int k, old_str, new_str;

	k = *id;
	k++;

	paramt = exchange(ourtype, id, str + k);
	if (paramt == NULL)
	{
		str = _strcpy(str, "");

		return (str);
		;
	}

	old_str = _strlen(str);
	new_str = _strlen(paramt) + 1;
	str = _realloc(str, old_str, new_str);
	str = _strcpy(str, paramt);

	release_memory(paramt);
	*id = k;

	return (str);
}

/**
 * handle_pattern - A function that handles patterns and serves as a
 * helper function.
 * @ourtype: a shell struct parameter.
 * @words: a pointer to a string passed as parameter.
 * Return: a pointer to a string.
 */
char *handle_pattern(shellinfo_t *ourtype, char *words)
{
	int k;

	for (k = 0; words[k] != '\0'; k++)
	{
		if (words[k] == '$' && words[k + 1] != '\0')
		{
			words = subtitute_value(ourtype, &k, words);
		}
	}

	return (words);
}
