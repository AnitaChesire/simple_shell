#include "shell.h"
/**
 * merge_words - A function that Joins three (3) words with a delimiter / separator.
 * @w1: Word1 to join
 * @w2: Word2 to join
 * @w3: Word3 to join
 * @del: Separator between the words
 * Return: a string containing strings joined together.
 */
char *merge_words(char *w1, char *w2, char *w3, const char *del)
{
	int size1, size2, size3, del_size;
	char *joint;

	size1 = size2 = size3 = del_size = 0;

	if (w2 != NULL)
		size2 = _strlen(w2);
	else
		w2 = "";

	if (w1 != NULL)
		size1 = _strlen(w1);
	else
		w1 = "";
	if (w3 != NULL)
		size3 = _strlen(w3);
	else
		w3 = "";
	if (del != NULL)
		del_size = _strlen((char *)del);
	else
		del = "";

	joint = malloc(size1 + del_size + size2 + del_size + size3 + 2);
	if (joint == NULL)
	{
		return (NULL);
	}
	joint = _strcpy(joint, w1);
	joint = _strcat(joint, (char *)del);
	joint = _strcat(joint, w2);
	joint = _strcat(joint, (char *)del);
	joint = _strcat(joint, w3);
	joint = _strcat(joint, "\n");

	return (joint);
}

/**
 * select_message - A function that checks for error code and selects a match with the error code gotten or received.
 * @mytype: a structure to the types created for shell.
 * Return: a character pointer to the msg
 */
char *select_message(shellinfo_t mytype)
{
	int k;
	int choices;

	issue_t msgs[] = {
		{_ENOENT_, 3},
		{_EACCES_, 13},
		{_CMD_NOT_EXISTS_, 132},
		{_ILLEGAL_NUMBER_, 133}
	};

	choices = sizeof(msgs) / sizeof(msgs[0]);
	for (k = 0; k < choices; k++)
		if (mytype.error_digit == msgs[k].password)
			return (msgs[k].msg);

	return ("");
}

