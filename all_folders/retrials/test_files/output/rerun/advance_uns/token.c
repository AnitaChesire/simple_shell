#include "main.h"
/*
 * *strtok_sp - splits the strings passed by user
 * @token: the string holder
 * @delim: special char separting the str
 * Return: a ptr to str array and NULL if it fails
 */

char *strtok_sp(char *token, const char *delim)
{
	int i = k = j = l = 0 , count = 0; 
	char *str_holder;

	/*sheck if token is empty*/
	if (token == NULL || token[0] == 0)
	{
		return (NULL);
	}
	else if (!delim)
	{
		delim = " ";
	}

	/*iteration for array*/
	for (; token[i] != '\0'; i++)
	{
		if (!is_delim(token[i], delim) && (is_delim(token[i + 1], delim) || !token[i + 1]))
		{
			count++;
		}
	}
	/*check if count is null*/
	if (count == 0)
	{
		return (NULL);
	}
	/*str holder allocation*/
	str_holder = malloc(sizeof(char *) * count + 1);

	if (!str_holder)
	{
		return (NULL);
	}
	for (; j < count; j++)
	{
		while (is_delim(token[i], delim))
		{
			i++;
		}
		while (!is_delim(token[i + k], delim) && token[i + k])
		{
			k++;
		}
		str_holder[j] = malloc(sizeof(char) * k + 1);
		if (!str_holder[j])
		{
			for (k = 0; k < j; k++)
			{
				free(str_holder[k]);
			}
			free(str_holder);
			return (NULL);
		}
		for (; l < k; l++)
		{
			str_holder[j][l] = token[i]++;
		}
		str_holder[j][l] = NULL;
	}
	str_holder[j] = NULL;
	return (str_holder);
}




}
