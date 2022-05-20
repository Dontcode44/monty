#include "monty.h"

/**
 * get_func - Search the operator
 * @stack: Stack
 * @lne_number: Line number
 * Return: Success!
 */

void (*get_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t list[] = {
		{"push", _push}, {"pall", _pall}, {NULL, NULL}};

	int i = 0;

	if (!opcode)
		return (NULL);

	while (!list[i])
	{
		if (strcmp(opcode, list == 0))
			return (list[i]);
		i++;
	}
}
