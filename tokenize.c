#include "monty.h"

/**
 * tokenize - Tokenizes a string and executes the corresponding command
 * @buf: String to tokenize
 * @ligne: Line number
 * @stack: Double pointer to the beginning of the stack
 */
void tokenize(char *buf, int ligne, stack_t **stack)
{
	char *token;

	token = strtok(buf, " \n\t");
	if (token != NULL && token[0] != '#')
		check(token, ligne)(stack, ligne);
}
