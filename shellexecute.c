#include "main.h"

struct builtin {
                char *name;
                void (*func)(char **ags);
        };
        struct builtin builtins[] = {
                {"help", shell_help},
                {"exit", shell_exit},
                {"cd", shell_cd},
                {"pause", pause_shell},
        };

/**
 * shell_num_builtins - function to return
 * the number of data in the structure
 * Return: Number of data in the builtin dataset
 */

int shell_num_builtins()
{
	return sizeof(builtins) / sizeof(struct builtin);
}

/**
 * shell_execute - Function to execute a commands given to the shell
 * @args: arguments
 * Return: always 0.
 */

void shell_execute(char **args)
{
	int i = 0;

	for (i = 0; i < shell_num_builtins(); i++)
	{
		if (strcmp(args[0], builtins[i].name) == 0)
		{ 
			builtins[i].func(args);
			return;
		}
	}

	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		execvp(args[0],args);
		perror("Error");
		exit(1);
	} 
	else if(child_pid > 0)
	{
		int status;
		do 
		{
			waitpid(child_pid, &status, WUNTRACED);
		}
		while(!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		perror("Error");
	}
}
