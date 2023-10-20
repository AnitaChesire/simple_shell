#include "shell.h"
/**
 * tokenize_words - A function that splits a string into words based
 * on a delimiter.
 * @string: string to be separated.
 * @del: A delimiter to be used for separating the string.
 * Return: string pointer to the splitted words.
 */
char **tokenize_words(char *string, const char *del)
{
	unsigned int old_word, new_word;
	char **word, **temp, *token;

	old_word = sizeof(char *);
	word = malloc(old_word);
	if (word != NULL)
	{
		new_word = 1;
		token = strtok(string, del);
		while (token)
		{
			if (token[0] == '#')
				break;
			temp = _realloc(word, old_word, (new_word + 1) * sizeof(char *));
			old_word = (new_word + 1) * sizeof(char *);
			if (temp == NULL)
				break;
			word = temp;
			++new_word;

			word[new_word - 2] = malloc(_strlen(token) + 1);
			if (word == NULL)
			{
				free(word);
				free(temp);
			}

			if (word[new_word - 2] != NULL)
			{
				_strcpy(word[new_word - 2], token);
			}
			token = strtok(NULL, del);
			temp = NULL;
		}
		word[new_word - 1] = NULL;
	}
	return (word);
}
