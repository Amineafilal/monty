#include "monty.h"

/**
 *  * add_dnodeint - adds a new node at the beginning
 *   * @head: head of the list
 *    * @n: value of the element
 *     * Return: the address of the new element
 *     */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *newnode = NULL;

	newnode = malloc(sizeof(dlistint_t));
	if (newnode == NULL)
	{
		dprintf(2, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	newnode->n = n;

	if (*head == NULL)
	{
		newnode->prev = NULL;
		newnode->next = *head;
	}
	else
	{
		newnode->prev = NULL;
		newnode->next = *head;
		(*head)->prev = newnode;
	}
	*head = newnode;
	return (newnode);
}

/**
 *  * print_dlistint - a function that prints all the elements
 *   *					of a dlistint_t list.
 *    *
 *     * @h: a pointer to the list
 *      *
 *       * Return: number of noded in the list
 *       */

size_t print_dlistint(const dlistint_t *h)
{
	int count = 0;

	if (h == NULL)
		return (count);
	while (h->prev)
		h = h->prev;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}
	return (count);
}

/**
 *  * free_dlistint - a function that frees a dlistint_t list.
 *   * @head: pointer to the head of the list
 *   */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *next = NULL;

	if (head == NULL)
		return;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
