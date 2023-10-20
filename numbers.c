#include "shell.h"

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

/**
 * _atoi - A function converts a string to an integer.
 * @s: input string value.
 * Return: integer.
 */
int _atoi(char *s)
{
	int result = 0;
	int sign = 1; /*Positive by default*/
	int k = 0;

	/*Handle negative numbers*/
	if (s[0] == '-')
	{
		sign = -1;
		k++;
	}

	/*Iterate through the string and convert to integer*/
	while (s[k] != '\0')
	{
		if (s[k] >= '0' && s[k] <= '9')
		{
			result = result * 10 + (s[k] - '0');
		}
		else
		{
			/*Invalid character found, break the loop*/
			break;
		}
		k++;
	}

	return (result * sign);
}
