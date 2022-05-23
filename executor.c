/**
 * This file contains any function
 * that has to deal with the structure.
 * This is essentially because i have 
 * not found a way to make this structure 
 * use able in all the files from one direction
 */

#include "shelly.h"

struct builtin {
        char *name;
        void (*func)(char *ags);
};

struct builtin builtins[] = {
        {"help", shell_help},
        {"exit", shell_exit},
        {"cd", shell_cd},
        {"pause", pause_shell},
        {"pwd", printworkingdirectory},
        {"PATH", getpath},
    };

/**
 * shell_loop - Loop of shell
 * @datash: data relevant (av, input, args)
 *
 * Return: no return.
 */
 void shell_loop()
{
	int v, i;
	int loop, i_eof;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		char **them; //This here indicates a array to pointer syntax.
		them = malloc(BUFFER_LEN * sizeof(char));
		char *delimiters = " \n";
		printf(">>> ");
		input = read_line(&i_eof);
		if (i_eof != -1)
		{
			v = string_tokenizer(input,them, delimiters);
			shell_execute(*them);
		}
		else
		{
			printf(" Error didn't occur: %s\n",input );
		}
		free(them);
		free(input);
		// printf("\n");
	}
}

/**
 * shell_execute - Function used to run all the shell executor
 * @args: A list of arguments
 * Return: Always 0.
 */
void shell_execute(char *args)
{
	int i = 0;

	for (i = 0; i < shell_num_builtins(); i++)
	{
			// builtins[i].func(args);
		if (strcmp((&args[0]), builtins[i].name) == 0)
		{ 
			builtins[i].func(args);
			return;
		}
	}

	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		// printf("%s\n",args );
		system(args);
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


/**
 * read_line - reads the input string.
 *
 * @i_eof: return value of getline function
 * Return: input string
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}


/**
 * shell_num_builtins - function to return
 * the number of data in the structure
 * Return: Number of data in the builtin dataset
 */

int shell_num_builtins()
{
	return sizeof(builtins) / sizeof(struct builtin);
}