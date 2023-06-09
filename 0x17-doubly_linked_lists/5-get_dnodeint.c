#include "lists.h"
/**
 * get_dnodeint_at_index - get node at index
 * @head: head node
 * @index: index
 *
 * Return: pointer to node, NULL if not exists
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count;

	for (count = 0; count < index && head != NULL; count++)
	{
		head = head->next;
	}

	return (head);
}
