#include "monty.h"

/***/

void swap(stack_t **stack,unsigned int ligne)
{
	int len, element1, element2;

	len = dlistint_len(*stack);

	if (len < 2)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", ligne);
		exit(EXIT_FAILURE);
	}
	element1 = (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	element2 = (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	add_dnodeint(stack, element1);
	add_dnodeint(stack, element2);
}


void add(stack_t **stack,unsigned int ligne)
{
	int len, element1, element2;

	len = dlistint_len(*stack);

	if (len < 2)
	{
		dprintf(2, "L%d: can't add, stack too short\n", ligne);
		free(buf);
		exit(EXIT_FAILURE);
	}
	element1 = (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	element2 = (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	add_dnodeint(stack, element1 + element2);
}
