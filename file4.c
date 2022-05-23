#include "shelly.h"

/*
 * main - Function to run the main shell code
 * argc - Number of arguments
 * argv - A list of arguments
 * Return: Always 0.
 */

int main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		printf("Accessing the file arguments\n");
		printf("The first: %s", argv[1]);
	}
	else
	{
		shell_loop();
		// printf("There is no file arguments to access\n");
	}
	return 0;
}