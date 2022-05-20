#include "monty.h"

/**
 * free_stack - Free all from stack
 * @head: list
 * Return nothing
 */
void free_stack(stack_t *head)
{
	stack_t *node = head;

	while (head)
	{
		node = node->next;
		free(head);
		head = node;
	}
}
