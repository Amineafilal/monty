#include "monty.h"

/**
 * delete_dnodeint_at_index -  a function that deletes the node at index
 * index of a dlistint_t linked list.
 * @head: pointer to the head of the list
 * @index: index of the node to delete
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *h1;
	dlistint_t *h2;
	unsigned int i;

	h1 = *head;

	if (h1 != NULL)
		while (h1->prev != NULL)
			h1 = h1->prev;

	i = 0;

	while (h1 != NULL)
	{
		if (i == index)
		{
			if (i == 0)
			{
				*head = h1->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				h2->next = h1->next;

				if (h1->next != NULL)
					h1->next->prev = h2;
			}

			free(h1);
			return (1);
		}
		h2 = h1;
		h1 = h1->next;
		i++;
	}

	return (-1);
}

/**
 * add_dnodeint_end - a function that adds a new node at the end
 *						of a dlistint_t list.
 * @head: pointer to the list
 * @n: data of the new node
 * Return: the address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *lastnode = NULL;

	lastnode = malloc(sizeof(dlistint_t));
	if (lastnode == NULL)
		return (NULL);

	lastnode->n = n;
	lastnode->next = NULL;

	if (*head == NULL)
	{
		*head = lastnode;
		lastnode->prev = NULL;
		return (lastnode);
	}
	while ((*head)->next)
	{
		*head = (*head)->next;
	}

	lastnode->prev = *head;
	(*head)->next = lastnode;
	return (lastnode);

}

/**
 * get_dnodeint_at_index - a function that returns the nth node
 *					of a dlistint_t linked list.
 * @head: pointer to the list
 * @index: position of the node to return
 * Return: pointer to the node to find
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (head == NULL)
		return (NULL);

	while (head->prev)
		head = head->prev;
	while (head)
	{
		if (i == index)
			return (head);
		head = head->next;
		i++;
	}
	return (NULL);
}
