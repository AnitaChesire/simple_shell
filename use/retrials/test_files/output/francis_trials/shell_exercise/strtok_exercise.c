#include "main.h"


/**
 *
 *
 *
 */



int main (void)
{
	char *token, *str, *source = "my name is uel,kariuki ,testing,this";
	/* hard coded string value to test the function and it works well*/
	/* to get input directly from user getline function is */
	/* needed from Francis and then update the *source variable to */
	/*  *source = getline(); */

	char *delim;

	/* test if delimiter is either space or comma or both*/
	delim = " ,"; 

	str = malloc(sizeof(char) * strlen(source));
	strcpy(str, source);

	token = strtok(str, delim);

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);

	}
	return (0);


}



