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
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}
