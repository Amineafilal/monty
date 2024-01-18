#include "monty.h"

/***/


void (*check(char *comands))(stack_t **stack, unsigned int ligne)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"kamal", nop},
	};

	while (i < 3)
	{
		if (!strcmp(comands, opcodes[i].opcode))
		{
			return(opcodes[i].f);
		}
		i++;
	}
	return(opcodes[i].f);
}
