#include "monty.h"

void push(stack_t **stack, unsigned int ligne)
{
	char *token2;
	int number;

	token2 = strtok(NULL, " \n\t");
	if (token2 != NULL)
	{
		if (not_int(token2))
		{
			dprintf(2, "L%d: usage: push integer\n", ligne);
			exit(EXIT_FAILURE);
		}
		else
		{
			number = atoi(token2);
			add_dnodeint(stack, number);
		}
	}
	else
	{
		dprintf(2, "L%d: usage: push integer\n", ligne);
		exit(EXIT_FAILURE);
	}
}

void pall(stack_t **stack, unsigned int ligne)
{
	(void) ligne;
	if (*stack != NULL)
		print_dlistint(*stack);
}

void pint(stack_t **stack, unsigned int ligne)
{
	(void) ligne;

	printf("%d\n", (*stack)->n);
}


void nop(stack_t **stack,unsigned int ligne)
{
	(void) stack;
	(void) ligne;
}
