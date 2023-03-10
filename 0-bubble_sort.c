#include <stddef.h>

#include "sort.h"

/**
 * bubble_sort - sort an array using the bubble sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t idx = 0;
	int temp, sort;

	if (size <= 1 || array == NULL)
		return;

	while (TRUE)
	{
		sort = FALSE;
		for (idx = 1; idx < size; ++idx)
		{
			if (array[idx] < array[idx - 1])
			{
				temp = array[idx - 1];
				array[idx - 1] = array[idx];
				array[idx] = temp;
				sort = TRUE;
				print_array(array, size);
			}
		}

		if (sort == FALSE)
			break;
	}
}
