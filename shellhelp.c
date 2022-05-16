#include "main.h"

void shell_help(char **args)
{
	char *helptext = 
		"Shell - A simple shell built under the supervision of ALX."
		"The Following commands are the avaliable builtin commands:\n"
		" cd	Change the working directory.\n"
		" exit	Exit the shell.\n"
		" help	Print the help section.\n";
	if (args[0] == NULL)
		printf("%s", helptext);
	else
		printf("%s", helptext);
}
