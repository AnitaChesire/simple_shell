#include <stdio.h>
#include "main.h"

int main(void) {
    node_t *path_list = path_list_func();

    if (path_list == NULL) {
        printf("No directories found in PATH environment variable.\n");
    } else {
        printf("Directories in PATH:\n");
        node_t *current = path_list;
        while (current != NULL) {
            printf("%s\n", current->dir);
            current = current->next;
        }
    }

    return 0;
}

