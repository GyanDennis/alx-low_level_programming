#include "hash_tables.h"

/**
 * key_index - a function that gives you the index of a key
 *             stored in array of a hash table.
 *
 * @key: The key index of interest
 * @size: The size of the array of the hash table.
 *
 * Description: the function uses the  djb2 algorithm
 *
 * Return: The index of the key.
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
