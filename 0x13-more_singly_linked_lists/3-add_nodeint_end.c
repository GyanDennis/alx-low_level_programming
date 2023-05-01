0x13. C - More singly linked lists

0x13. C - More singly linked lists

lists.h


#ifndef LISTS_H

#define LISTS_H


#include <stdio.h>

#include <stdlib.h>


/**

 * struct listint_s - singly linked list

 * @n: integer

 * @next: points to the next node

 *

 * Description: singly linked list node structure

 * for alx project

 */

typedef struct listint_s

{

        int n;

        struct listint_s *next;

} listint_t;


size_t print_listint(const listint_t *h);

size_t listint_len(const listint_t *h);

listint_t *add_nodeint(listint_t **head, const int n);

listint_t *add_nodeint_end(listint_t **head, const int n);

void free_listint(listint_t *head);

void free_listint2(listint_t **head);

int pop_listint(listint_t **head);

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index);

int sum_listint(listint_t *head);

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n);

int delete_nodeint_at_index(listint_t **head, unsigned int index);

listint_t *reverse_listint(listint_t **head);

size_t print_listint_safe(const listint_t *head);

size_t free_listint_safe(listint_t **h);

listint_t *find_listint_loop(listint_t *head);


#endif

0-print_listint.c


#include "lists.h"


/**

 * print_listint - prints all the elements of a linked list

 * @h: linked list of type listint_t to print

 *

 * Return: number of nodes

 */

size_t print_listint(const listint_t *h)

{

        size_t num = 0;


        while (h)

        {

                printf("%d\n", h->n);

                num++;

                h = h->next;

        }


        return (num);

}


















1-listint_len.c


#include "lists.h"


/**

 * listint_len - returns the number of elements in a linked lists

 * @h: linked list of type listint_t to traverse

 *

 * Return: number of nodes

 */

size_t listint_len(const listint_t *h)

{

        size_t num = 0;


        while (h)

        {

                num++;

                h = h->next;

        }


        return (num);

}



















2-add_nodeint.c


#include "lists.h"


/**

 * add_nodeint - adds a new node at the beginning of a linked list

 * @head: pointer to the first node in the list

 * @n: data to insert in that new node

 *

 * Return: pointer to the new node, or NULL if it fails

 */

listint_t *add_nodeint(listint_t **head, const int n)

{

        listint_t *new;


        new = malloc(sizeof(listint_t));

        if (!new)

                return (NULL);


        new->n = n;

        new->next = *head;

        *head = new;


        return (new);

}
















3-add_nodeint_end.c


#include "lists.h"


/**

 * add_nodeint_end - adds a node at the end of a linked list

 * @head: pointer to the first element in the list

 * @n: data to insert in the new element

 *

 * Return: pointer to the new node, or NULL if it fails

 */

listint_t *add_nodeint_end(listint_t **head, const int n)

{

        listint_t *new;

        listint_t *temp = *head;


        new = malloc(sizeof(listint_t));

        if (!new)

                return (NULL);


        new->n = n;

        new->next = NULL;


        if (*head == NULL)

        {

                *head = new;

                return (new);

        }


        while (temp->next)

                temp = temp->next;


        temp->next = new;


        return (new);

}

