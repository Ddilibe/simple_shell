#include "main.h"

/**
 * shell_help - Function to display the help menu
 * @args: arguments
 * Return: always 0.
 */

void shell_help(char **args)
{
	char *helptext = 
		"Shell - A simple shell built under the supervision of ALX."
		"The Following commands are the avaliable builtin commands:\n"
		" cd	Change the working directory.\n"
		" exit	Exit the shell.\n"
		" help	Print the help section.\n"
		" pause Pause the shell from futher activities\n";
	if (args[1] == NULL)
		printf("%s", helptext);
	else
		printf("%s", helptext);
}
