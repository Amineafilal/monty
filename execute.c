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

	print_dlistint(*stack);
}

void pint(stack_t **stack, unsigned int ligne)
{
	int len;

	(void) ligne;
	len = dlistint_len(*stack);
	if (len == 0)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", ligne);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

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

void nop(stack_t **stack,unsigned int ligne)
{
	(void) stack;
	(void) ligne;
}
