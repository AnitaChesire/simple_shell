#include "main.h"

/**
*/
char **slice(char **tokens, int start, int end) {
    char **result = NULL;
    int i, j;

    if (start < 0 || end < start) {
        return NULL;
    }

    result = (char **)malloc(sizeof(char *) * (end - start + 2));
    if (result == NULL) {
        return NULL;
    }

    for (i = start, j = 0; i <= end; i++, j++) {
        result[j] = strdup(tokens[i]);
    }
    result[j] = NULL;

    return result;
}

/*Returns the number of elements in the tokens array*/
int no_tokens(char **tokens) {
    int i;

    for (i = 0; tokens[i] != NULL; i++);
    return i;
}
