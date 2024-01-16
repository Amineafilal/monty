#include "monty.h"
/**
 * pall - prints all the values on the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number in the file
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *cur = *stack;

	(void)line_number;

	while (cur)
	{
		printf("%d\n", cur->n);
		cur = cur->next;
	}
}
