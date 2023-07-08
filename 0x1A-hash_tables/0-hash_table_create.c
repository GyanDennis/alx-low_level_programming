#include "hash_tables.h"

/**
 * hash_table_create - a function that creates a hash table.
 *
 * @size: The size of the array
 *
 * Return: pointer to the newly created hash table
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table; /* Pointer to the hash table */
	unsigned long int i;

	table = malloc(sizeof(hash_table_t)); /* Allocate memory for the hash table */
	if (table == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}

	table->size = size; /* Set the size of the hash table */

	/* Allocate memory for the array of hash nodes */
	table->array = malloc(sizeof(hash_node_t *) * size);

	if (table->array == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}

	i = 0;
	while (i < size)
	{
		table->array[i] = NULL;
		/* to ensures there's no existing references or dangling pointers*/
		i++;
	}
	return (table);
}
