/**
 * This file will contain all the
 * builtin commands that has the 
 * hightest call by any user.
 * This is all in an effort to 
 * regulate and stop thw confusion 
 * that the developer is going through.
 * This file would not be frequently opened
 *  because the command here would be 
 * verifyed and tested before being kept here
 */

#include "shelly.h"

/*
 * getpath - Function to print path
 * @args: a list of arguments
 * Return: always 0.
 */
void getpath(char *args)
{
	printf("%s\n", getenv("PATH"));
}

/**
 * shell_help - Function to display the help menu
 * @args: arguments
 * Return: always 0.
 */
void shell_help(char *args)
{
    char *helptext = 
        " Shell - A simple shell built under the supervision of ALX.\n"
        " The Following commands are the avaliable builtin commands:\n"
        " cd    Change the working directory.\n"
        " exit  Exit the shell.\n"
        " help  Print the help section.\n"
        " pause Pause the shell from futher activities\n"
        " PATH  To get the environ of PATH\n"
        " pwd   To print the working directory\n";

    if ((args + 1) == NULL)
        printf("%s", helptext);
    else
        printf("%s", helptext);
}

/**
 * shell_exit - Function to exit a shell
 * @args: arguments
 * Return: always 0.
 */

void shell_exit(char *args) 
{
    if ((&args[1]) == NULL)
        exit(0);
    exit(0);
}

/**
 * shell_cd - Function to change the working directory
 * @args: arguments
 * Return: always 0.
 */

void shell_cd(char *args)
{
    if (strcmp((args+1) == "")==0)
    {
        fprintf(stderr, "shell: cd: missing argument\n");
    }
    else
    {
        if (chdir(args + 1) != 0)
        {
            perror("Shell: cd");
        }
    }
}


/**
 * pause_shell - Function to pause shell
 * @args: list of arguments
 * Return: always 0.
 */
void pause_shell(char *args)
{
    if ((args + 0) != NULL)
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