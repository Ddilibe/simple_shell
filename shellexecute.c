#include "main.h"
struct builtin {
                char *name;
                void (*func)(char **ags);
        };
        struct builtin builtins[] = {
                {"help", shell_help},
                {"exit", shell_exit},
                {"cd", shell_cd},
        };

int shell_num_builtins()
{
	return sizeof(builtins) / sizeof(struct builtin);
}

void shell_execute(char **args)
{
	int i = 0;
	pid_t child_pid = fork();

	for (i = 0; i < shell_num_builtins(); i++)
	{
		if (strcmp(args[0], builtins[i].name) == 0)
		{ 
			builtins[i].func(args);
			return;
		}
	}


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
