#include "shell.h
"#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *error_message(int error_code, const char *name, const char *hist_str, const char *arg);

/**
 * error_message - Creates an error message for various error codes.
 * @error_code: The error code for which to generate an error message.
 * @name: The name associated with the error.
 * @hist_str: The history string.
 * @arg: The argument associated with the error.
 *
 * Return: The error message string.
 */
char *error_message(int error_code, const char *name, const char *hist_str, const char *arg)
{
    if (!name || !hist_str || !arg)
        return NULL;

    int len = strlen(name) + strlen(hist_str) + strlen(arg) + 24; // Adjust the length as needed
    char *error = (char *)malloc(sizeof(char) * (len + 1));

    if (!error)
        return NULL;

    strcpy(error, name);
    strcat(error, ": ");
    strcat(error, hist_str);
    strcat(error, ": ");
    strcat(error, arg);

    if (error_code == 126)
    {
        strcat(error, ": Permission denied\n");
    }
    else if (error_code == 127)
    {
        strcat(error, ": not found\n");
    }
    else
    {
        strcat(error, ": Unknown error\n");
    }

    return error;
}

int main()
{
    const char *name = "Program";
    const char *hist_str = "42";
    const char *arg = "file.txt";
    int error_code = 127;

    char *error_msg = error_message(error_code, name, hist_str, arg);

    if (error_msg)
    {
        printf("Error message: %s", error_msg);
        free(error_msg);
    }
    else
    {
        printf("Error message creation failed.\n");
    }

    return 0;
}
