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
	char *fileopen = NULL;

	/*Checks number of arguments*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fileopen = open_file(fileopen, argv);
	lines (fileopen);

	fclose(fileopen);
	return (0);
}
