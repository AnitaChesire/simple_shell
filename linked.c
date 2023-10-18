#include "shell.h"
#include <string.h>

/*
 * alias_t *alias_end - Adds a node to the end of an alias_t linked list.
 * @head: A pointer to the head of the alias_t list.
 * @name: The name of the new alias to be added.
 * @value: The value of the new alias to be added.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 */
alias_t *add_alias_end(alias_t **head, char *name, char *value)
{
	alias_t *last;

    alias_t *new_node = malloc(sizeof(alias_t));

    if (!new_node)
        return NULL;

    new_node->next = NULL;
    new_node->name = strdup(name);
    if (!new_node->name)
    {
        free(new_node);
        return NULL;
    }
    new_node->value = strdup(value);

    if (*head)
    {
        last = *head;
        while (last->next != NULL)
            last = last->next;
        last->next = new_node;
    }
    else
        *head = new_node;

    return new_node;
}

/**
 * add_node_end - Adds a node to the end of a list_t linked list.
 * @head: A pointer to the head of the list_t list.
 * @dir: The directory path for the new node to contain.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 */
list_t *add_node_end(list_t **head, char *dir)
{
    list_t *new_node = malloc(sizeof(list_t));

    if (!new_node)
        return NULL;

    new_node->dir = dir;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        list_t *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }

    return new_node;
}

/**
 * free_alias_list - Frees an alias_t linked list.
 * @head: The head of the alias_t list.
 */
void free_alias_list(alias_t *head)
{
	 alias_t *temp;

    while (head) {
        temp = head;
        head = head->next;
        free(temp->name);
        free(temp->value);
        free(temp);
    }
}

/**
 * free_list - Frees a list_t linked list.
 * @head: The head of the list_t list.
 */
void free_list(list_t *head)
{
	list_t *temp;

    while (head) {
        temp = head;
        head = head->next;
        free(temp->dir);
        free(temp);
    }
}

