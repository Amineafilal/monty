#include "monty.h"

/**
 * check - Check the command and return the corresponding function pointer
 * @com: Command string to check
 * @ln: Line number where the command is found
 * Return: Pointer to the corresponding function
 */

void (*check(char *com, unsigned int ln))(stack_t **stack, unsigned int ligne)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"sub", sub},
		{"add", add},
		{"_div", _div},
		{"nop", nop},
		{"nop", nop},
	};

	while (i < 9)
	{
		if (!strcmp(com, opcodes[i].opcode))
		{
			return (opcodes[i].f);
		}
		i++;
	}

	dprintf(2, "L%d: unknown instruction %s\n", ln, com);
	exit(EXIT_FAILURE);
	return (opcodes[i].f);
}
