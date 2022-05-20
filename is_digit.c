#include "monty.h"
/**
 * str_isdigit - Check if a string is a digit.
 * @string: string to check.
 * Return: 1 if it is digit 0 if not.
 */
int is_digit(char *string)
{
	int i = 0;

	if (!string)
		return (0);

	if (string[i] == '-')
		i++;

	while (string[i])
	{
		if (is_digit(string[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}