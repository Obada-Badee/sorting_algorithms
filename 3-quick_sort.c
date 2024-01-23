#include "sort.h"

/**
 * swap - Swap two elements
 * @first: The first element
 * @second: The second element
 */
void swap(int *first, int *second)
{
	if (first == NULL || second == NULL)
		return;
	*first ^= *second;
	*second ^= *first;
	*first ^= *second;
}

/**
 * lomuto_quick_sort - Use Nico Lomuto's version of quick_sort
 * @array: The array to be sorted
 * @lo: The smallest index in the array
 * @hi: The highest index in the array
 * @size: The size of the array
 */
void lomuto_quick_sort(int *array, size_t lo, size_t hi, size_t size)
{
	size_t j, i = lo;

	if (lo >= hi)
		return;
	for (j = lo; j <= hi; j++)
	{
		if (array[j] > array[hi])
			continue;
		if (i != j && array[i] != array[j])
		{
			swap(array + i, array + j);
			print_array(array, size);
		}
		if (j != hi)
			i++;
	}
	lomuto_quick_sort(array, i + 1, hi, size);
	if (i != 0)
		lomuto_quick_sort(array, lo, i - 1, size);
}

/**
 * quick_sort - The quick_sort sorting algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array && size >= 2)
		lomuto_quick_sort(array, 0, size - 1, size);
}
