#include "main.h"

int main() {
    char str[] = "hello world, this is a test string!";
    char *token;
    
    token = custom_strtok(str, " ,!");
    while (token != NULL) {
        printf("%s\n", token);
        token = custom_strtok(NULL, " ,!");
    }
    
    return 0;
}
