#include "monty.h"

/**
 * free_stack - Free all from stack
 * @stack: Stack
 */
void free_stack(stack_t **stack)
{
	stack_t *tofree;

	if (*stack == NULL)
		return;

	tofree = stack;
	if (stack != NULL)
	{
		free_stack(tofree->next);
		free(tofree);
	}
}
