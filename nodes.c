#include "monty.h"
/**
 * add_new_node - Adds a new node at the top
 *
 * @head: head of the dbl linked list
 * @data_node: value to insert in new node
 * Return: returns the new node
 */
stack_t *add_new_node(stack_t **head, int data_node)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		_free(*head), fclose(fileopen);
		exit(EXIT_FAILURE);
	}

	new_node->n = data_node;
	new_node->next = *head;
	new_node->prev = NULL;
	if (*head)
		(*head)->prev = new_node;
	*head = new_node;

	return (new_node);
}
/**
 * add_node_end - Adds a new node at the bottom
 *
 * @head: head of the dbl linked list
 * @data_node: value to insert in new node
 * Return: returns the new node
 */
stack_t *add_node_end(stack_t **head, int data_node)
{
	stack_t *new_node = NULL;
	stack_t *last = NULL;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		return (NULL);

	new_node->n = data_node;
	new_node->next = NULL;
	last = *head;
	if (*head == NULL)
		*head = new_node;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new_node;
		new_node->prev = last;
	}
	return (*head);
}
