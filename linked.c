#include "shell.h"

alias_t *add_alias_end(alias_t **head, const char *name, const char *value);
void free_alias_list(alias_t *head);
list_t *add_node_end(list_t **head, const char *dir);
void free_list(list_t *head);

/**
 * add_alias_end - Adds a node to the end of an alias_t linked list.
 * @head: A pointer to the head of the alias_t list.
 * @name: The name of the new alias to be added.
 * @value: The value of the new alias to be added.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 */
alias_t *add_alias_end(alias_t **head, const char *name, const char *value)
{
	alias_t *current;
	alias_t *new_node;

    new_node = malloc(sizeof(alias_t));
    if (!new_node) {
        return NULL;
    }

    new_node->name = _strdup(name);
    new_node->value = _strdup(value);
    new_node->next = NULL;

    if (!new_node->name || !new_node->value) {
        free(new_node->name);
        free(new_node->value);
        free(new_node);
        return NULL;
    }

    if (*head == NULL) {
        *head = new_node;
    } else {
        current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }

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
list_t *add_node_end(list_t **head, const char *dir)
{
	list_t *current;
	list_t *new_node;

    new_node = malloc(sizeof(list_t));
    if (!new_node) {
        return NULL;
    }

    new_node->dir = _strdup(dir);
    new_node->next = NULL;

    if (!new_node->dir) {
        free(new_node);
        return NULL;
    }

    if (*head == NULL) {
        *head = new_node;
    } else {
        current = *head;
        while (current->next) {
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

