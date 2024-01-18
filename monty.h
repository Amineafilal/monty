#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

extern char *buf;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct stack_s dlistint_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void tokenize(char *buf, int ligne, stack_t **stack);
void (*check(char *com, unsigned int ln))(stack_t **stack, unsigned int ligne);
void push(stack_t **stack, unsigned int ligne);
void nop(stack_t **stack, unsigned int ligne);
void pint(stack_t **stack, unsigned int ligne);
int not_int(char *s);
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
size_t print_dlistint(const dlistint_t *h);
void pall(stack_t **stack, unsigned int ligne);
void free_dlistint(dlistint_t *head);
void pop(stack_t **stack, unsigned int ligne);
size_t dlistint_len(const dlistint_t *h);
void swap(stack_t **stack, unsigned int ligne);
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);
void add(stack_t **stack, unsigned int ligne);
void sub(stack_t **stack, unsigned int ligne);
void _div(stack_t **stack, unsigned int ligne);
void mul(stack_t **stack, unsigned int ligne);
void mod(stack_t **stack, unsigned int ligne);
void pchar(stack_t **stack, unsigned int ligne);
void pstr(stack_t **stack, unsigned int line_number);

#endif
