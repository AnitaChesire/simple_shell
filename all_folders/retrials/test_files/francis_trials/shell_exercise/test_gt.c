#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main() {
    char *line;
    while ((line = without_getline()) != NULL) {
        printf("read line: %s\n", line);
        free(line);
    }
    return 0;
}
