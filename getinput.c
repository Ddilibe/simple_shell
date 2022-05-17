#include "main.h"

/**
 * get_input - Function to get the standard input
 * @void: an empty argument
 * Return: The Result
 */

char *get_input(void)
{
	char *line = NULL;
	size_t len = 0;

	getline(&line, &len, stdin);

	return (line);
}
