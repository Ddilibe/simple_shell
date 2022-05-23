/**
 * This file will contain all the
 * builtin commands that has the 
 * hightest call by any user.
 * This is all in an effort to 
 * regulate and stop thw confusion 
 * that the developer is going through.
 * This file would not be frequently opened
 *  because the command here would be 
 * verifyed and tested before being kept here.
 * This is the second file that the builtin 
 * commands are kept in
 */

#include "shelly.h"

/*
 * printworkingdirectory - Function to print working directory
 * Return: a pointer to a working directory
 */
void printworkingdirectory(char *arg)
{
	char *cwdbuf;
	size_t size = 1024;

	getcwd(cwdbuf, size);
	if (cwdbuf == NULL)
	{
		printf("Working Directory Exceeds File Size\n");
	}
	else
		printf("%s\n", cwdbuf);
}

/*
 * changedirectory - Function to change a directory
 * Return: 1 or 0
 */
void changedirectory(char *path)
{
	const char *men = path;
	int c = chdir(men);
	if (c != 0)
		perror("c");
}

/*
 * opendirectory - Function to open a new directroy
 * @argv: File to be opened
 * Return: Error on error
 */

char opendirectory(const char *argv) 
{
	DIR *path = opendir(argv);
	if (path == NULL)
		printf("Error on Opening Directory %s\n",argv[1] );
}
