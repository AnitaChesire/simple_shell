#incude "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to count the digit length of a number
int count_digit_length(int num);
// Function to convert an integer to a string
char *int_to_string(int num);
// Function to create a custom error message and write it to stderr
int create_custom_error(char **args, int err);

/**
 * count_digit_length - Counts the digit length of a number.
 * @num: The number to measure.
 *
 * Return: The digit length.
 */
int count_digit_length(int num)
{
    unsigned int num1;
    int length = 1;

    if (num < 0)
    {
        length++;
        num1 = (unsigned int)(-num);
    }
    else
    {
        num1 = (unsigned int)num;
    }

    while (num1 > 9)
    {
        length++;
        num1 /= 10;
    }

    return length;
}

/**
 * int_to_string - Converts an integer to a string.
 * @num: The integer.
 *
 * Return: The converted string.
 */
char *int_to_string(int num)
{
    char *buffer;
    int length = count_digit_length(num);
    unsigned int num1;

    buffer = (char *)malloc(sizeof(char) * (length + 1));
    if (!buffer)
        return NULL;

    buffer[length] = '\0';

    if (num < 0)
    {
        num1 = (unsigned int)(-num);
        buffer[0] = '-';
    }
    else
    {
        num1 = (unsigned int)num;
    }

    length--;
    do {
        buffer[length] = (num1 % 10) + '0';
        num1 /= 10;
        length--;
    } while (num1 > 0);

    return buffer;
}

/**
 * create_custom_error - Writes a custom error message to stderr.
 * @args: An array of arguments.
 * @err: The error value.
 *
 * Return: The error value.
 */
int create_custom_error(char **args, int err)
{
    char *error_message = NULL;

    switch (err)
    {
    case -1:
        // Implement get_error_message_env(args) function here
        error_message = "Error message for -1";
        break;
    case 1:
        // Implement get_error_message_1(args) function here
        error_message = "Error message for 1";
        break;
    case 2:
        if (args[0][0] == 'e')
            // Implement get_error_message_2_exit(args) function here
            error_message = "Error message for 2 (exit)";
        else if (args[0][0] == ';' || args[0][0] == '&' || args[0][0] == '|')
            // Implement get_error_message_2_syntax(args) function here
            error_message = "Error message for 2 (syntax)";
        else
            // Implement get_error_message_2_cd(args) function here
            error_message = "Error message for 2 (cd)";
        break;
    case 126:
        // Implement get_error_message_126(args) function here
        error_message = "Error message for 126";
        break;
    case 127:
        // Implement get_error_message_127(args) function here
        error_message = "Error message for 127";
        break;
    }

    if (error_message) {
        write(STDERR_FILENO, error_message, strlen(error_message));
    }

    return err;
}

int main() {
    // Sample usage of create_custom_error
    char *args[] = {"exit", NULL};
    create_custom_error(args, 2);
    return 0;
}
