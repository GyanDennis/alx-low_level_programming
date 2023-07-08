#include "hash_tables.h"

/**
 * hash_table_print - a function that prints a hash table.
 *
 * @ht: A pointer to the hash table to be printed
 *
 * Description: the key/value are printed in the order that
 * they appear in the array of hash table
 *
 */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int idx = 0;
	unsigned char comma_flag = 0;

	if (!ht)
		return;

	printf("{");
	while (idx < ht->size)
	{
		if (ht->array[idx] != NULL)
		{
			if (comma_flag == 1)
				printf(", ");

			node = ht->array[idx];
			while (node != NULL)
			{
				printf("'%s': '%s'", node->key, node->value);
				node = node->next;
				if (node != NULL)
					printf(", ");
			}
			comma_flag = 1;
		}
		idx++;
	}
	printf("}\n");
}
