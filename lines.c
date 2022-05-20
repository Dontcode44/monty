#include "monty.h"
/**
 * lines - tokenize the lines
 * @fileopen: monty file
 * Return FILE
 */
FILE *lines(FILE *fileopen)
{
	char *token = NULL;
	char buffer[BUFSIZ];
	unsigned int line_number = 1;
	void (*get_opcode)(stack_t **, unsigned int);
	stack_t *head = NULL;

	while (fgets(buffer, sizeof(buffer), fileopen) != NULL)
	{
		token = strtok(buffer, DELIM);
		if (!token || token[0] == ' ')
		{
			line_number++;
			continue;
		}

		get_opcode = get_func(token);
		get_opcode(&head, line_number);

		line_number++;
	}
	return (fileopen);
}
