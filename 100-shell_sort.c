#include <stdio.h>
#include "sort.h"

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

/**
 * getGap - Returns the starting gap.
 * @size: size of array
 *
 * Return: gap to start with
 */
size_t getGap(size_t size)
{
	size_t gap = 1;

	while ((gap * 3 + 1) < size)
		gap = gap * 3 + 1;

	return (gap);
}

/**
 * sort - sort a sub section or gap in the list
 * @array: array to sort
 * @size: size of array
 * @gap: gap to skip
 */
void sort(int *array, size_t size, size_t gap)
{
	size_t idx = 0, gap_idx;

	/**
	 * the idx variable loops through the array starting from the second
	 * segment.
	 * The gap_idx jumps through each segment, starting from one segment
	 * behind idx and swaps the numbers at the index.
	 */
	for (idx = gap; idx < size; ++idx)
	{
		/* set the gap idx. it should move gap times */
		gap_idx = idx - gap;
		while (TRUE)
		{
			if (array[gap_idx + gap] < array[gap_idx])
				swap(array + gap_idx, array + gap_idx + gap);
			else /* already in place */
				break;
			if (gap_idx > gap)
				gap_idx -= gap;
			else
				break;
		}
	}

}

/**
 * shell_sort - sort an array using the shell sort algo
 * @array: array to sort
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap;

	if (!array || size < 2)
		return;

	gap = getGap(size);

	for (gap = gap; gap > 0; gap = gap / 3)
	{
		sort(array, size, gap);
		print_array(array, size);
	}

}
