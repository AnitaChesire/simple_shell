#include "main.h"


int main(void)
{
	char input[100] = "Hello,World!This is a test string.";
	char* token;

    // tokenize the input string and print each token
    //
    token = _strtok(input, " ,.!"); // use multiple delimiters
    while (token != NULL) {
        printf("%s\n", token);
	token = _strtok(NULL, " ,.!");
    }

    return 0;



}
