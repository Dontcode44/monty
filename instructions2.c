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

/**
 * mul - multiply second node and top node
 * @head: top of list
 * @line_number: line of command
 */
void mul(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n *= (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}
/**
 * div - divide second node from top node
 * @head: top of list
 * @line_number: line of command
 */
void div(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0 || (*head)->next->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
	}
	(*head)->next->n /= (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}
