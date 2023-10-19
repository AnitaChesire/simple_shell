#include "main.h"

char *_strtok(char *string, const char *delimiter)
{
        static char *command = NULL;
        static int token_position = 0;
        char *token_result;
        int a = 0;
        const char *pointer;


        if (string != NULL)
        {
                command = string;
                token_position = 0;
        }
        else if (command == NULL)
        {
                return (NULL);
        }


        /* the 1 is for the null terminating character*/
        token_result = (char *)malloc(strlen(command) + 1);

        /* memory allocation not successful*/
        if (!token_result)
        {
                return (NULL);
        }

        for (; command[a] != '\0'; a++)
        {
                pointer = delimiter;
                while(*pointer != '\0')
                {
                        if (command[a] == *pointer)
                        {
                                token_result[token_position] = '\0';
                                token_position = 0;
                                command = command + a + 1;
                                return (token_result);
                        }
                        pointer++;
                }
                token_result[token_position++] = command[a];
        }
        /* last character set to '\0' to null terminate the last token*/
        token_result[token_position] = '\0';
        /* to indicate there is no more tokens to extract*/
        command = NULL;
        return (token_result);

}
