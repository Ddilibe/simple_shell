#include "main.h"

struct thing {
	char *name;
};

struct thing things[] = {
	{";"},
	{"&&"},
	{"||"}
};

/**
 * shell_help - Function to display the help menu
 * @args: arguments
 * Return: always 0.
 */

void shell_help(char **args)
{
	char *helptext = 
		" Shell - A simple shell built under the supervision of ALX.\n"
		" The Following commands are the avaliable builtin commands:\n"
		" cd	Change the working directory.\n"
		" exit	Exit the shell.\n"
		" help	Print the help section.\n"
		" pause Pause the shell from futher activities\n";

	if (args[1] == NULL)
		printf("%s", helptext);
	else
		printf("%s", helptext);
}

/**
 * semicolon - Function to check for semicolon
 * @arg: Arguments
 * Return: Return 1 if semicolon and 0 in no semicolon
 */
int semicolon(char **args)
{
	int w = 0;
	char a = ';';

	while (**(args)+w != a)
	{
		w++;
		if (**(args)+w == a)
		{
			return (w);
		}
		else
		{
			continue; 
		}
	}
}

/**
 * shell_display - To display what has been written
 * @args: argument
 * Return: always 0.
 */

void shell_display(char **args)
{
	int i = 0;
	char **che;
	char f;
	**che = f;

	for (i = 0; args[i] != NULL; i++)
	{
		if (strcmp(args[i], things[i].name) == 0)
		{ 
			i++;
			f = **(args + i);
			shell_execute(che);
			return;
		}
		else
		{
			printf("%s\n", args[i]);
		}
	}
}

/**
 * shell_extra - Function to use and get
 * and prevent things from happening
 * Return: the size of the things struct
 */
int shell_extra()
{
	return sizeof(things) / sizeof(struct thing);
}
