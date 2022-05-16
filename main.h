#ifndef _MAIN_H_
#define _MAIN_H_
	
	/**
	 * Builtin GNU libraries
	 */
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <string.h>
	#include <sys/wait.h>
	#include <unistd.h>

	/**
	 * Builder Created Prototypes
	 */
	char *get_input();
	void shell_execute(char **arg);
	char **split_line(char *line);
	void shell_help(char **args);
	void shell_cd(char **args);
	void shell_exit(char **args);
#endif
