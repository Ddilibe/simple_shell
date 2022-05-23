/**
 * This file contains those functions
 * thst has to do with string manipulation
 * or copying string or anything thing that has to do with string
 */ 



#include "shelly.h"

/**
 * split_line - Function to split
 * the inputed commands into arguments
 * @line: Inputed argument
 * Return: Return the argumented inputs
 */
int string_tokenizer(char* str, char **tokens, char *delimiter)
{	
	int tokens_count = 0;
	char* token = strtok(str, delimiter);
	while (token != NULL){
		(tokens[tokens_count]) = token;
		tokens_count++;
		token = strtok(NULL, delimiter);
	}
	tokens[tokens_count++] = NULL;
	return tokens_count;
}

/**
 * _strncpy - copies a string
 * @dest: destination.
 * @src: source.
 * @n: amount of bytes from src.
 * Return: the pointer to dest.
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < n; i++)
		dest[i] = '\0';

	return (dest);
}

/**
 * _strlen - returns the length of a string.
 * @s: input string.
 * Return: length of a string.
 */
int _strlen(char *s)
{
	int count = 0;

	while (*(s + count) != '\0')
		count++;
	return (count);
}