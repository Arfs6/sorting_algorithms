#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

/**
 * counting_sort - sort an array of integers using counting sort algorithm
 * @array: array to sort
 * @size: size of @array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, max = 0, idx = 0, tmp = 0;
	size_t i = 0, j = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; ++i)
		if (array[i] > max) /* finding max */
			max = array[i];

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return; /* insufficient memory */
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	for (i = 0; i < max + 1; ++i)
		count[i] = 0; /* initializing count array */

	for (i = 0; i < size; ++i)
		count[array[i]]++; /* setting count of each number */
	for (idx = 1; idx < max + 1; ++idx)
		count [idx] += count[idx-1];
	print_array(count, max + 1);

	for (i = 0; i < size; ++i)
	{
		output[count[array[i]] - 1] = array[i];
		--count[array[i]];
	}

	for (i = 0; i < size; ++i)
		array[i] = output[i];
	free(output), free(count);
}
