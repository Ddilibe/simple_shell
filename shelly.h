#ifndef _SHELLY_H_
#define _SHELLY_H_
	
	/* Preprocessor Variables */
	#define MAX_READ 4096
	#define TOK_BUFSIZE 1024
	#define BUFFER_LEN 1024 
	#define MAX_TOKENS 10

	/* GNU Builtin Libraries */
	#include <unistd.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <dirent.h>
	#include <unistd.h>
	#include <string.h>
	#include <stdbool.h>
	#include <sys/wait.h>

	/* Built Prototype */
	void printworkingdirectory(char *args);
	void changedirectory(char *path);
	char opendirectory(const char *argv);
	int _strlen(char *c);
	char readinginput();
	char *_strncpy(char *dest, char *src, int n);
	void shell_loop();
	char *read_line(int *i_eof);
	int string_tokenizer(char* str, char **tokens, char *delimiters);
	void shell_help(char *args);
	void shell_exit(char *args);
	void shell_cd(char *args);
	void pause_shell(char *args);
	void getpath(char *args);
	int shell_num_builtins();
	void shell_execute(char *args);
#endif
