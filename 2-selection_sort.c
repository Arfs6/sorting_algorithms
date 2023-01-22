#include <stdio.h>
#include <stddef.h>

#include "sort.h"

void swap(int *l_int, int *r_int);

/**
 * selection_sort - sort an array using the selection sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min_int, sort;

	i = j = 0;

	if (size < 2 || array == NULL)
		return; /* already sorted */

	/* loop through the array stopping at size-1 */
	for (i = 0; i < size - 1; ++i)
	{
		min_int = array + i;
		sort = FALSE;
		/* now find and swap the lowest integer */
		for (j = i + 1; j < size; ++j)
			if (array[j] < *min_int)
			{
				sort = TRUE;
				min_int = array + j;
			}

		/* swap the found max integer */
		if (sort == TRUE)
		{
			swap(&(array[i]), min_int);
			print_array(array, size);
		}
	}
}

/**
 * swap - swaps to integers
 * @l_int: left integer
 * @r_int: right integer
 */
void swap(int *l_int, int *r_int)
{
	int temp;

	temp = *l_int;
	*l_int = *r_int;
	*r_int = temp;
}
