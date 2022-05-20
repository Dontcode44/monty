#include "monty.h"

/**
 * push - Push an element to the stack.
 * @head: Header
 * @line_number: Line number
 * Return: nothing.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	unsigned int i, node;

	for (i = 0; i < strlen(fileopen); i++)

	{
		if (fileopen[i] == '-')
			i++;

		if (!isdigit(fileopen[i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n, line_number");
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}
	node = atoi(fileopen);
	new = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->next = *stack;
	new->prev = NULL;
	new->n = node;

	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
