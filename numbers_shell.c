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
