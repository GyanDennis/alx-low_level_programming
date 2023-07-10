#include "hash_tables.h
/**
 * shash_table_print_ext - prints a sorted hash table
 * @ht: hash table to print
 * @reverse: if true, print in reverse order
 *
 * Return: void
 */
void shash_table_print_ext(const shash_table_t *ht, int reverse)
{
	shash_node_t *tmp;
	char flag = 0; /* 0 before printing any data, 1 after*/

	if (ht == NULL || ht->array == NULL)
		return;

	printf("{");
	if (reverse)
		tmp = ht->stail;
	else
		tmp = ht->shead;

	while (tmp != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		flag = 1;
		if (reverse)
			tmp = tmp->sprev;
		else
			tmp = tmp->snext;
	}
	printf("}\n");
}

