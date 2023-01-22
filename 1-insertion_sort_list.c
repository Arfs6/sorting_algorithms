#include <stddef.h>
#include <stdio.h>

#include "sort.h"

void swap(listint_t *l_node, listint_t *r_node);

/**
 * insertion_sort_list - sort a linked list using the insertion algorithm
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *next, *prev, *cur;

	if (!list)
		return;

	cur = *list;
	/* check for no items */
	if (!cur || !cur->next)
		return;

	/* loop through the list, starting at second item */
	cur = cur->next;
	do {
		/* since we might change cur, let's store the next item */
		next = cur->next;
		prev = cur->prev;

		/* keep swaping it with nodes greater than it. */
		while (prev != NULL)
		{
			if (prev->n > cur->n)
			{
				swap(prev, cur);
				/* update head if changed */
				if (cur->prev == NULL)
					*list = cur;
				print_list(*list);
				prev = cur->prev;
			}
			else
			{
				break;
			}
		}

		cur = next;
	} while (cur != NULL);
}

/**
 * swap - swaps two nodes in a lists
 * @l_node: left list node
 * @r_node: right list node
 */
void swap(listint_t *l_node, listint_t *r_node)
{
	listint_t *temp_next, *temp_prev;

	temp_prev = l_node->prev;
	temp_next = r_node->next;

	if (temp_prev != NULL)
		temp_prev->next = r_node;
	r_node->prev = temp_prev;

	if (temp_next != NULL)
		temp_next->prev = l_node;
	l_node->next = temp_next;

	l_node->prev = r_node;
	r_node->next = l_node;
}
