#include "main.h"

/**
 * main - Running the main file
 *
 * Return: Always 0
 */

int main(void)
{
	char *collect;

	while (true)
	{
		printf("$ ");
		collect = get_input();
		printf(collect);
	}

	free(collect);
	return (0);
}
