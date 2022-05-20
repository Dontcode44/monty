#include "monty.h"

/**
 * get_func - Select the opcode to execute.
 * @opcode: instruction to execute.
 * Return: nothing
 */
void (*get_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t list[] = {
		{"push", push}, {"pall", pall}, {NULL, NULL}
	};

	int i = 0;

	if (!opcode)
		return (NULL);

	while (list[i].opcode)
	{
		if (strcmp(opcode, list[i].opcode) == 0)
			return (list[i].f);
		i++;
	}

	return (NULL);
}
