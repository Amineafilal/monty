#include "monty.h"

/**
 * mod - Computes the remainder of the division
 * @stack: Double pointer to the beginning of the stack
 * @ligne: Line number where the modulo operation is executed
 */

void mod(stack_t **stack, unsigned int ligne)
{
	int len, element1, element2;

	len = dlistint_len(*stack);

	if (len < 2)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", ligne);
		exit(EXIT_FAILURE);
	}
	element1 = (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	if (element1 == 0)
	{
		dprintf(2, "L%d: division by zero\n", ligne);
		exit(EXIT_FAILURE);
	}
	element2 = (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	add_dnodeint(stack, element2 % element1);
}

/**
 * pchar - prints the char at the top of the stack.
 * @stack: Double pointer to the beginning of the stack
 * @ligne: Line number where the modulo operation is executed
 */
void pchar(stack_t **stack, unsigned int ligne)
{
	int stack_len, ch;
	char character;

	stack_len = dlistint_len(*stack);
	if (stack_len == 0)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", ligne);
		exit(EXIT_FAILURE);
	}
	ch = (*stack)->n;
	if (ch < 32 || ch > 126)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", ligne);
		exit(EXIT_FAILURE);
	}
	character = ch;
	printf("%c\n", character);
}
