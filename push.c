#include "monty.h"
/**
 * push - pushes an element onto the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number in the file
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *n_node;

	if (!stack)
	{
		fprintf(stderr, "L%u: Stack not initialized\n", line_number);
		exit(EXIT_FAILURE);
	}

	n_node = malloc(sizeof(stack_t));
	if (!n_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (!isdigit(instruction->opcode[0]) && instruction->opcode[0] != '-')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n_node->n = atoi(instruction->opcode);
	n_node->prev = NULL;
	n_node->next = *stack;

	if (*stack)
		(*stack)->prev = n_node;

	*stack = n_node;
}
