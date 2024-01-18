#include "monty.h"


/**
 * swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the beginning of the stack
 * @ligne: Line number where the swap operation is executed
 */
void swap(stack_t **stack, unsigned int ligne)
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

/**
 * add - Adds the top two elements of the stack
 * @stack: Double pointer to the beginning of the stack
 * @ligne: Line number where the add operation is executed
 */
void add(stack_t **stack, unsigned int ligne)
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

/**
 * sub - Subtracts the top element from the second top element in the stack
 * @stack: Double pointer to the beginning of the stack
 * @ligne: Line number where the subtraction operation is executed
 */
void sub(stack_t **stack, unsigned int ligne)
{
	int len, element1, element2;

	len = dlistint_len(*stack);

	if (len < 2)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", ligne);
		free(buf);
		exit(EXIT_FAILURE);
	}
	element1 = (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	element2 = (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	add_dnodeint(stack, element2 - element1);
}
