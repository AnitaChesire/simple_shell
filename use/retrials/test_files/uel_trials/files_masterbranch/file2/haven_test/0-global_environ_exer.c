 #include "main.h"
     
 /**
  * main- print env with global variable environ
  *
  */

extern  char **environ;

int glob_environ(void)
{
	int e = 0;

	while (environ[e] != NULL)
	{
		printf("%s\n", environ[e++]);
	}
	return (0);
}               
