#include <stdio.h>
#include <stddef.h>

#include "sort.h"

void sort(int *array, ssize_t low, ssize_t high, ssize_t ssize);
ssize_t partition(int *array, ssize_t low, ssize_t high, ssize_t ssize);
void swap(int *l_int, int *r_int);

/**
 * quick_sort - sort an array using the quick sort algorithm.
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	ssize_t _size;

	if (size < 2)
		return;
	if (array == NULL)
		return;

	_size = (ssize_t)size;
	sort(array, 0, _size - 1, _size);
}

/**
 * sort - recursively sorts an array using quick sort.
 * @array: array to sort
 * @low: lower index range
 * @high: higher index range
 */
void sort(int *array, ssize_t low, ssize_t high, ssize_t size)
{
	ssize_t pivot_idx;
	printf("sort %li, %li\n", low, high);

	if (low >= high)
		return;

	/* divide and get index of division */
	pivot_idx = partition(array, low, high, size);

	/* conquer from left, then right */
	sort(array, low, pivot_idx - 1, size);
	sort(array, pivot_idx + 1, high, size);
	return;
}

/**
 * partition - divides an array into two. First half should be lower than the
 * pivot point. The pivot should be the last item in the array. i.e. array[high]
 * @array: array to divide.
 * @low: lower index to start with.
 * @high: higher index to stop at.
 *
 * Return: The pivot point in the array.
 */
ssize_t partition(int *array, ssize_t low, ssize_t high, ssize_t size)
{
	ssize_t pivot_idx = 0; /* this should point to the pivot point. */
	ssize_t i = 0;
	int pivot;

	pivot = array[high];
	pivot_idx = low;

	/* loop from low to 1 index from high */
	for (i = low; i < high; ++i)
	{
		if (array[i] <= pivot)
		{ /* it is in the wrong half, swap it and increase pivot index */
			pivot_idx++;
			swap(array + pivot_idx - 1, array + i);
			print_array(array, size);
		}
	}

	/* swap the number in the pivot point with the pivot number */
	swap(array + pivot_idx, array + high);

	printf("return %li\n", pivot_idx);
	return (pivot_idx);
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
