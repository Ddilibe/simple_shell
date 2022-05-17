#include "main.h"

/**
 * shell_cd - Function to change the working directory
 * @args: arguments
 * Return: always 0.
 */

void shell_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "shell: cd: missing argument\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("Shell: cd");
		}
	}
}

/**
 * pause_shell - Function to pause shell
 * Return: always 0.
 */
void pause_shell(char **args){
	if (args[0] != NULL)
	{
		printf("\n\nShell is now paused. Please press ENTER key to continue....\n\n");
	}
	else
	{
		printf("\n\nShell is now paused. Please press ENTER key to continue....\n\n");
	}
	char code = (char)getchar();
	while (code != '\n'){
		code = (char)getchar();
	}
}