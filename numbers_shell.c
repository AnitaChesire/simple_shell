#include "shell.h"
/**
 * is_numeric - A function that checks if a given parameter is a digit.
 * @number: Number to be checked.
 * Return: 1 if it is a number, 0 otherwise.
 */
int is_numeric(unsigned int number)
{
	return (number >= '0' && number <= '9');
}

/**
 * number - A function that counts the number of digits a given number has.
 * @num: The given number.
 * Return: The number of digits of the number counted.
 */
int number(int num)
{
	int k = 0;

	while (num != 0)
	{
		k++;
		num = num / 10;
	}

	return (k);
}

/**
 * handle_numbers - A function that helps the user control the
 * argument of exit builtin.
 * @ourtype: a pointer to the shell struct to access its types.
 * @argument: Argument of the builtin exit to be passed.
 * Return: 1 upon success, else return 0 which is negative.
 */
int handle_numbers(shellinfo_t *ourtype, char *argument)
{
	int tracer;

	tracer = _atoi(argument);

	if (tracer < 0 || has_letter(argument))
	{
		ourtype->code_stat = 2;
		ourtype->error_digit = 133;
		additional_error(ourtype, argument);
		return (0);
	}

	if (tracer > 255)
	{
		ourtype->code_stat = tracer % 256;
	}
	else
	{
		ourtype->code_stat = tracer;
	}

	return (1);
}
