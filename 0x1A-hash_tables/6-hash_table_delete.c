#include "hash_tables.h"

/**
 * hash_table_delete - a function that deletes a hash table.
 *
 * @ht: A pointer to a hash table.
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head;
	hash_node_t *node;
	/* iterate through the linked list of hash nodes of the hash table array*/
	hash_node_t *tmp_node;
	/*tracks the next node in the linked list before freeing the current node */
	unsigned long int i;

	head = ht;

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			node = ht->array[i];
			while (node != NULL)
			{
				tmp_node = node->next;
				free(node->key);
				free(node->value);
				free(node);
				node = tmp_node;
			}
		}
	}
	free(head->array);
	free(head);
}
