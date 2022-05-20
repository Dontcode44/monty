#include "monty.h"
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
