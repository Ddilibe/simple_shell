#include "main.h"

char **split_line(char *line)
{
	int length = 0;
	int size = 16;
	char **tokens = malloc(size * sizeof(char*));

	char *retrict = " \t\r\n";
	char *token = strtok(line, retrict);

	while (token != NULL)
	{
		tokens[length] = token;
		length++;

		if (length >= size)
		{
			size = (int)(size * 1.5);
			tokens = realloc(tokens, size * sizeof(char *));
		}
		token = strtok(NULL, retrict);
	}

	tokens[length] = NULL;
	return tokens;
}
