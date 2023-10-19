#include "main.h"

node_t *path_list_func(void)
{
	size_t path_len;
	char *path_copy;
	char *directory;
	node_t *new_node;
	node_t *head;

	/* get the PATH environmemt variable*/
	char *path_env = getenv("PATH");
	if (path_env == NULL)
	{
		return (NULL);
	}
	/* buffer to hold PATH string*/
	path_len = strlen(path_env);
	path_copy = malloc(path_len + 1);

	if (path_copy == NULL)
	{
		return (NULL);
	}
	strcpy(path_copy, path_env);

	/* initialize head of the linked list*/
	head = NULL;

	/* parsing the PATH string into individual directories*/
	directory = _strtok(path_copy, ":");
	while(directory != NULL)
	{
		/* allocate a new node for this directory*/
		new_node = malloc(sizeof(node_t));
		if (new_node == NULL)
		{
			return (NULL);
		}
		/*copy dir string into the new node*/
		new_node->dir= strdup(directory);
		if (new_node == NULL)
		{
			free(new_node);
			return (NULL);


		}
		/* add the new node to the linked list*/
		new_node->next = head;
		head = new_node;

		/*get the next directory in the PATH string*/

		directory = _strtok(NULL, ":");
	}

	/*free PATH buffer*/
	free(path_copy);
	return(head);

}
