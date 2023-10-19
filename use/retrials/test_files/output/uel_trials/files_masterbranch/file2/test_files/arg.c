#include "main.h"

int arg_func(int ac, char **av)
{
	char *buffer;
	size_t buffer_size = 32;
	size_t command;

	
	(void)ac;

	buffer = (char *) malloc(buffer_size * sizeof(char));

	if (buffer == NULL)
	{
		perror("unable to allocate memory");
		return (-1);
	}
	if (strcmp(av[0], "exit") == 0)
	{
		printf("i exist");
		return 0;
	}

	printf("enter command, and use exit to exit the program\n");
	while (1)
	{
		printf("/$: Enter command here: ");
		fflush(stdin);
		command = getline(&buffer, &buffer_size, stdin);

		printf("%s", buffer);
	}
	
	free(buffer);
	return(command);
}
