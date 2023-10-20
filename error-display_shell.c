#include "main.h"
/**
 * display_error - A function that prints the standard error (2) message.
 * @message: Message to be printed is passed here.
 * Return: Number of bytes printed by the function.
 */
int display_error(char *message)
{
	return (output_to_fd(message, 2));
}

/**
 * additional_error - A function that prints the error message with
 * elaborate information about the error.
 * @ourtype: a structure that contains info about the shell and
 * also declares a type for this info.
 * @more: More info about the error message.
 * Return: Nothing (Error message printed)
 */
void additional_error(shellinfo_t *ourtype, char *more)
{
	char *msg, *num;
	char *au, *au2;
	int num_size, msg_size;
	int more_size;

	num = NULL;
	msg = select_message(*ourtype);
	num = stringify(ourtype->num_cmd);

	num_size = strlen(num);
	msg_size = strlen(ourtype->argv[0]);
	more_size = strlen(more);

	au = malloc(msg_size + num_size + 3);
	au = strcpy(au, ourtype->argv[0]);
	au = strcat(au, ": ");
	au = strcat(au, num);

	au2 = malloc(_strlen(msg) + more_size + 3);
	au2 = strcpy(au2, msg);
	au2 = strcat(au2, ": ");
	au2 = strcat(au2, more);

	msg = merge_words(au, ourtype->cmd, au2, ": ");
	display_error(msg);

	free(msg);
	free(num);
	free(au);
	free(au2);
}
