#include "main.h"

/**
 * shell_exit - Function to exit a shell
 * @args: arguments
 * Return: always 0.
 */

void shell_exit(char **args) 
{
	if (args[1] == NULL)
		exit(0);
	exit(0);
}
