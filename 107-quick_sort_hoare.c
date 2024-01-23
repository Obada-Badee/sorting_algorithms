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
 * hoare_sort - Use Hoare version of quick_sort
 * @array: The array to be sorted
 * @lo: The smallest index in the array
 * @hi: The highest index in the array
 * @size: The size of the array
 */
void hoare_sort(int *array, size_t lo, size_t hi, size_t size)
{
	size_t j = hi + 1, i = lo - 1;

	if (lo >= hi)
		return;
	while (1)
	{
		do {
			i++;
		} while (array[i] < array[hi]);
		do {
			j--;
		} while (array[j] > array[hi]);
		if (i >= j)
			break;
		swap(array + i, array + j);
		print_array(array, size);
	}
	hoare_sort(array, i, hi, size);
	hoare_sort(array, lo, i - 1, size);
}

/**
 * quick_sort_hoare - The quick_sort sorting algorithm with
 *		      hoare partition scheme
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array && size >= 2)
		hoare_sort(array, 0, size - 1, size);
}
