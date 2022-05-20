#include "monty.h"

/**
 * pall - Print elements of nodes
 * @lines: Line numbers from file
 * @stack: From struct
 */
void pall(stack_t **stack, unsigned int lines)
{
	stack_t *head;

	(void)lines;

	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
