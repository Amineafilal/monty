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
	int value;
	int len;
	char ascii;

	len = dlistint_len(*stack);
	if (len == 0)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", ligne);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n;
	if (value < 32 || value > 126)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", ligne);
		exit(EXIT_FAILURE);
	}
	ascii = value;
	printf("%c\n", ascii);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: Double pointer to the beginning of the stack
 * @ligne: Line number where the modulo operation is executed
 */

void pstr(stack_t **stack, unsigned int ligne)
{
	int value;
	char ascii;
	stack_t *ptr;

	(void) ligne;
	ptr = *stack;
	while (ptr != NULL && ptr->n != 0 && ptr->n >= 32 && ptr->n <= 126)
	{
		value = ptr->n;
		ascii = value;
		printf("%c", ascii);
		ptr = ptr->next;
	}
	putchar('\n');
}

/**
 * rotl - The opcode rotr rotates
 *			the stack to the bottom.
 * @stack : Double pointer to the beginning of the stack
 * @ligne : variable
 * Return: if code fails.
 */

void rotl(stack_t **stack, unsigned int ligne)
{
	int len, value;

	(void) ligne;
	len = dlistint_len(*stack);
	if (len >= 2)
	{
		value = (get_dnodeint_at_index(*stack, 0))->n;
		delete_dnodeint_at_index(stack, 0);
		add_dnodeint_end(stack, value);
	}
	else
		return;
}

/**
 * rotr - check code.
 * @stack : Double pointer to the beginning of the stack
 * @ligne : Line number where the modulo operation is executed
 * Return: if code fails.
 */

void rotr(stack_t **stack, unsigned int ligne)
{
	int len, value;

	(void) ligne;
	len = dlistint_len(*stack);
	if (len >= 2)
	{
		value = (get_dnodeint_at_index(*stack, len - 1))->n;
		delete_dnodeint_at_index(stack, len - 1);
		add_dnodeint(stack, value);
	}
	else
		return;
}
