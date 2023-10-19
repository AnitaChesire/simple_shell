#include "main.h"

int main() 
{
    // Set an environment variable
    setenv("MY_VAR", "hello", 1);

    // Print the value of the environment variable
    printf("Before deletion: MY_VAR=%s\n", getenv("MY_VAR"));

    // Delete the environment variable
    int ret = _unsetenv("MY_VAR");
    if (ret == 0) {
        printf("Variable deleted successfully.\n");
    } else {
        printf("Variable not found.\n");
    }

    // Print the value of MY_VAR after deletion
    char *my_var = getenv("MY_VAR");
    if (my_var == NULL) {
        printf("After deletion: (MY_VAR is not set)\n");
    } else {
        printf("After deletion: MY_VAR=%s\n", my_var);
    }

    return 0;
}

