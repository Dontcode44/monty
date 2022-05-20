#include "monty.h"
/**
 * lines - Parse each line of the monty file.
 * @openfile: opened file.
 * Return: last line number on the monty file opened.
 */
FILE *lines(FILE *openfile)
{
	char *token = NULL;
	char buffer[BUFSIZ];
	unsigned int line_number = 1;
	stack_t *head = NULL;
	void (*get_opcode)(stack_t **, unsigned int);

	while (fgets(buffer, sizeof(buffer), openfile) != NULL)
	{
		token = strtok(buffer, DELIM);
		if (!token || token[0] == '#')
		{
			line_number++;
			continue;
		}
		get_opcode = get_func(token);
		if (get_opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			free_stack(head);
			fclose(fileopen);
			exit(EXIT_FAILURE);
		}
		get_opcode(&head, line_number);

		line_number++;
	}
	free_stack(head);

	return (fileopen);
}
