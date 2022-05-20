#include "monty.h"

FILE *fileopen = NULL;
/**
 * main - Program to interprete the command-line.
 * @argc: number of arguments passed to main.
 * @argv: arguments passed to main.
 *
 * Return: always 0 on success, otherwise EXIT_FAILURE.
 */
int main(int argc, char *argv[])
{
	char *monty_file = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fileopen = open_file(monty_file, argv);
	lines(fileopen);

	fclose(fileopen);
	return (0);
}