#include <stdio.h>
#include <stddef.h>

#include "sort.h"

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

/**
 * sort_right - sorts the list to the right
 * @list: list to sort
 *
 * Return: TRUE: a swap happended
 * FALSE: no swap happened
 */
int sort_right(listint_t **list)
{
	listint_t *node, *next;
	int sort = FALSE;

	node = *list;

	while (node->next)
	{
		next = node->next;
		if (node->n > next->n)
		{
			swap(node, next);
			sort = TRUE;
			print_list(*list);
			if (next->prev == NULL)
				*list = next; /* updating list head if it changes */
			next = node; /* swapped next to the position of node, so next is now node */
		}

			node = next;
	}

	return (sort);
}

/**
 * sort_left - sort the list to the left
 * @list: list to sort.
 *
 * Return: TRUE: swap happened
 * FALSE: no swap
 */
int sort_left(listint_t **list)
{
	listint_t *node;
	int sort = FALSE;

	/* take node to tail */
	node = *list;
	while (node->next != NULL)
		node = node->next;

			while (node->prev != NULL)
			{
				if (node->n < node->prev->n)
				{
					swap(node->prev, node);
					sort = TRUE;
					if (node->prev == NULL)
						*list = node;
					print_list(*list);
				}
				else
					node = node->prev;
			}

			return (sort);
}

/**
 * cocktail_sort_list - sort a doubly linked list using the cocktail shaker
 * algorithm.
 * @list: list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	if (list == NULL || (*list)->next == NULL)
		return;

	while (TRUE)
	{
		if (sort_right(list) == FALSE)
			break;
		else if (sort_left(list) == FALSE)
			break;
	}
}
