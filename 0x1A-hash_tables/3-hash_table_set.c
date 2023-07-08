#include "hash_tables.h"

/**
 * hash_table_set - a function that adds an element to the hash table
 *
 * @ht: A pointer to the hash table.
 * @key: The key to be  added - cannot be an empty string.
 * @value: The value key hold
 *
 * Return: 0 upon failure, Otherwise 1.
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node; /* Pointer to a new hash node */
	char *tmp_value; /* Temporary value for storing a copy of 'value' */
	unsigned long int index, i;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	tmp_value = strdup(value);
	if (tmp_value == NULL)
		return (0);

	/* Get the index using the key */
	index = key_index((const unsigned char *)key, ht->size);

	/* Iterate through the array at the index */
	i = index;
	while (ht->array[i])
	{       /* Check if the key already exists */
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = tmp_value;
			return (1);
		}
		i++; }
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(tmp_value);
		return (0); }
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0); }
	new_node->value = tmp_value;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
