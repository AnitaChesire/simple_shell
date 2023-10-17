#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

char *create_error_message(const char *format, ...);

/**
 * create_error_message - Creates an error message with variable arguments.
 * @format: The format string for the error message.
 * @...: Variable arguments to be inserted into the format string.
 *
 * Return: The error string.
 */
char *create_error_message(const char *format, ...)
{
    char *error = NULL;
    va_list args;

    va_start(args, format);
    int len = vsnprintf(NULL, 0, format, args);
    va_end(args);

    if (len < 0) {
        return NULL; // Handle vsnprintf error
    }

    error = (char *)malloc(len + 1); // Allocate memory for the error message
    if (!error) {
        return NULL; // Handle memory allocation failure
    }

    va_start(args, format);
    vsnprintf(error, len + 1, format, args);
    va_end(args);

    return error;
}

char *create_error_env(const char *name, int hist, const char *arg)
{
    char hist_str[32];
    snprintf(hist_str, sizeof(hist_str), "%d", hist);

    char *error = create_error_message("%s: %s: %s: Unable to add/remove from environment\n", name, hist_str, arg);

    return error;
}

char *create_error_1(const char *alias)
{
    return create_error_message("alias: %s not found\n", alias);
}

char *create_error_2_exit(const char *name, int hist, const char *illegalNum)
{
    char hist_str[32];
    snprintf(hist_str, sizeof(hist_str), "%d", hist);

    char *error = create_error_message("%s: %s: exit: Illegal number: %s\n", name, hist_str, illegalNum);

    return error;
}

char *create_error_2_cd(const char *name, int hist, const char *cdPath)
{
    char hist_str[32];
    snprintf(hist_str, sizeof(hist_str), "%d", hist);

    char *error = NULL;

    if (cdPath[0] == '-') {
        error = create_error_message("%s: %s: cd: Illegal option %s\n", name, hist_str, cdPath);
    }
    else {
        error = create_error_message("%s: %s: cd: can't cd to %s\n", name, hist_str, cdPath);
    }

    return error;
}

char *create_error_2_syntax(const char *name, int hist, const char *unexpected)
{
    char hist_str[32];
    snprintf(hist_str, sizeof(hist_str), "%d", hist);

    char *error = create_error_message("%s: %s: Syntax error: \"%s\" unexpected\n", name, hist_str, unexpected);

    return error;
}

int main() {
    // Example usage of the error functions
    const char *name = "myshell";
    int hist = 42;
    const char *arg = "arg1";
    const char *alias = "myalias";
    const char *illegalNum = "abc";
    const char *cdPath = "-option";
    const char *unexpected = "invalid";

    char *error1 = create_error_env(name, hist, arg);
    char *error2 = create_error_1(alias);
    char *error3 = create_error_2_exit(name, hist, illegalNum);
    char *error4 = create_error_2_cd(name, hist, cdPath);
    char *error5 = create_error_2_syntax(name, hist, unexpected);

    printf("Error 1: %s\n", error1);
    printf("Error 2: %s\n", error2);
    printf("Error 3: %s\n", error3);
    printf("Error 4: %s\n", error4);
    printf("Error 5: %s\n", error5);

    free(error1);
    free(error2);
    free(error3);
    free(error4);
    free(error5);

    return 0;
}
