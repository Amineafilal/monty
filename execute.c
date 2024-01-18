#include "monty.h"

/**
 * push - Pushes an element onto the stack
 * @stack: Double pointer to the beginning of the stack
 * @ligne: Line number where the push operation is executed
 */
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
/**
 * pall - Prints all the elements in the stack
 * @stack: Double pointer to the beginning of the stack
 * @ligne: Line number (unused in this function)
*/
void pall(stack_t **stack, unsigned int ligne)
{
	(void) ligne;

	print_dlistint(*stack);
}

/**
 * pint - Prints the value at the top of the stack
 * @stack: Double pointer to the beginning of the stack
 * @ligne: Line number where the pint operation is executed
 */
void pint(stack_t **stack, unsigned int ligne)
{
	int len;

	len = dlistint_len(*stack);
	if (len == 0)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", ligne);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the beginning of the stack
 * @ligne: Line number where the pop operation is executed
*/
void pop(stack_t **stack,unsigned int ligne)
{
	stack_t *ptr = *stack;
	
	if (ptr != NULL)
	{
		*stack = ptr->next;
		ptr->prev = NULL;
		ptr->next = NULL;
		free(ptr);
	}
	else
	{
		dprintf(2, "L%d: can't pop an empty stack\n", ligne);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop - Does nothing
 * @stack: Double pointer to the beginning of the stack (unused)
 * @ligne: Line number where the nop operation is executed (unused)
*/
void nop(stack_t **stack,unsigned int ligne)
{
	(void) stack;
	(void) ligne;
}
