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
	dlistint_t *node;
	dlistint_t *tail;

	node = malloc(sizeof(dlistint_t));
	if (node == NULL)
		return (NULL);

	node->n = n;

	if (*head == NULL)
	{
		node->prev = NULL;
		node->next = NULL;
		*head = node;
	}
	else
	{
		tail = *head;
		while (tail->next != NULL)
				tail = tail->next;
		tail->next = node;
		node->prev = tail;
		node->next = NULL;
	}
	return (node);
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
	dlistint_t *ptr;

	if (head == NULL)
		return (NULL);

	ptr = head;
	while (ptr)
	{
		if (i == index)
			return (ptr);
		ptr = ptr->next;
		i++;
	}
	return (NULL);
}
