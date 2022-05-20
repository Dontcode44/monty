#include "monty.h"

/**
 * file_to_open - Open a monty file from main arguments.
 * @monty_file: file to open.
 * @argv: arguments passed to main.
 * Return: the file opened.
 */
FILE *open_file(char *monty_file, char *argv[])
{
	monty_file = argv[1];
	fileopen = fopen(monty_file, "r");
	if (!fileopen)
	{
		fprintf(stderr, "Error: Can't open file %s\n", monty_file);
		exit(EXIT_FAILURE);
	}

	return (fileopen);
}
