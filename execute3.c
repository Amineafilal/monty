#include "monty.h"

/***/

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
