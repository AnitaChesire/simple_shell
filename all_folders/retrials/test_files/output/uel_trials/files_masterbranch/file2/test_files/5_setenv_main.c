#include <stdlib.h>
#include <stdio.h>

int main() {
    // set the value of the environment variable "MY_VAR" to "Hello, World!"
    setenv("MY_VAR", "Hello, World!", 1);

    // retrieve the value of "MY_VAR" and print it
    char* value = getenv("MY_VAR");
    printf("Value of MY_VAR: %s\n", value);

    return 0;
}

