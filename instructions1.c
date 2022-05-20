#include "monty.h"

/**
 * push - Push an element to the stack list.
 * @head: list into push.
 * @line_number: line number of the file.
 * Return: nothing.
 */
void push(stack_t **head, unsigned int line_number)
{
	char *token = NULL;
	int data_node = 0;

	token = strtok(NULL, DELIM);

	if (is_digit(token))
	{
		data_node = atoi(token);
		add_new_node(head, data_node);
	}
	else
	{
		free_stack(*head), fclose(fileopen);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - Print all the values on the stack list.
 * @head: list into push.
 * @line_number: line number of the file.
 * Return: nothing.
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *current = NULL;
	(void)(line_number);

	if (!head)
		return;

	current = *head;
	while (current)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - Print the value at the top of the stack list.
 * @head: list into push.
 * @line_number: line number of the file.
 * Return: nothing.
 */
void pint(stack_t **head, unsigned int line_number)
{
	if (!head || !*head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*head)->n);
}

/**
 * nop - Print the value at the top of the stack list.
 * @head: list into push.
 * @line_number: line number of the file.
 * Return: nothing.
 */
void nop(stack_t **head, unsigned int line_number)
{
	(void)(**head);
	(void)(line_number);
}
