#include "monty.h"
/**
 * lines - tokenize the string
 * @fileopen: file
 *Return: Success!
 */
char *buffer;
unsigned int line_number = 1;
void (*get_opcode)(stack_t **, unsigned int);
stack_t *current_stack = NULL;
char *token = NULL;

FILE lines(FILE *fileopen)
{
	while (fgets(buffer, sizeof(buffer), fileopen) != NULL)
	{
		token = strtok(buffer, DELIM);
		if (!token)
			fprintf("L %s: unknown instruction %s\n", line_number, token);
		get_opcode = get_func(token[0]);
		get_opcode(current_stack, line_number);
		line_number++;
	}
	return (*fileopen);
}
