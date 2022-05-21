#include "monty.h"
/**
 * swap - swap between nodes positions
 *
 * @head: header of the stack
 * @line_number: number of lines
 */
void swap(stack_t **head, unsigned int line_number)
{
	int current = 0;

	if (!head || !*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*head), fclose(fileopen);
		exit(EXIT_FAILURE);
	}
	current = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = current;
}
/**
 * add - add nodes
 *
 * @head: header of the stack
 * @line_number: number of lines
 */
void add(stack_t **head, unsigned int line_number)
{
	if (!head || !*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, "add");
		free_stack(*head), fclose(fileopen);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n = (*head)->n + (*head)->next->n;
	pop(head, line_number);
}

/**
 * sub - Substract the value of two nodes.
 * @head: header of the stack.
 * @line_number: number of lines.
 */
void sub(stack_t **head, unsigned int line_number)
{
	if (!head || !*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, "sub");
		free_stack(*head), fclose(fileopen);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n -= (*head)->n;
	pop(head, line_number);
}
