#include "hash_tables.h"

/**
 * hash_table_get - a function that retrieves a value associated with a key
 *                 in a hash table.
 *
 * @ht: A pointer to the hash table.
 * @key: The key to get the of
 *
 * Return: NULL if key couldn’t be found
 *         Otherwise - the value associated with key in ht.
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;
	unsigned long int idx;

	if (!ht || !key || *key == '\0')
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);
	if (idx >= ht->size)
		return (NULL);

	node = ht->array[idx];
	while (node && strcmp(node->key, key) != 0)
		node = node->next;

	if (node == NULL)
		return (NULL);
	else
		return (node->value);
}
