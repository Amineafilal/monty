#include "monty.h"

/***/

void tokenize(char *buf, int ligne, stack_t **stack)
{
	char *token;

	token = strtok(buf, " \n\t");
	if (token != NULL && token[0] != '#')
		check(token, ligne)(stack, ligne);
}
