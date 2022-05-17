#include "main.h"

/**
 * main - Running the main file
 * @void: an empty argument
 * Return: Always 0
 */

int main(void)
{
	char *collect;
	char **verart;

	while (true)
	{
		printf("$ ");
		collect = get_input();
		verart = split_line(collect);

		if (verart[0] != NULL)
		{
			shell_execute(verart);
		}
		free(collect);
		free(verart);
	}
	return (0);
}
