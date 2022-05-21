#include "monty.h"

/**
 * get_func - Select the opcode to execute.
 * @opcode: instruction to execute.
 * Return: no return.
 */
void (*get_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t op_list[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"nop", nop}, {"pop", pop}, {"swap", swap},
		{"add", add}, {"sub", sub}, {"div", div},
		{"mul", mul}, {"mod", mod}, {NULL, NULL}
		};

	int i = 0;

	if (!opcode)
		return (NULL);

	while (op_list[i].opcode)
	{
		if (strcmp(opcode, op_list[i].opcode) == 0)
			return (op_list[i].f);
		i++;
	}

	return (NULL);
}
