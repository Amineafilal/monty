#include "monty.h"

/***/


void (*check(char *comands, unsigned int ligne))(stack_t **stack, unsigned int ligne)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"nop", nop},
	};

	while (i < 7)
	{
		if (!strcmp(comands, opcodes[i].opcode))
		{
			return(opcodes[i].f);
		}
		i++;
	}

	dprintf(2, "L%d: unknown instruction %s\n", ligne, comands);
	exit(EXIT_FAILURE);
	return(opcodes[i].f);
}
