#include "sort.h"

/**
 * bubble_sort - The bubble sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, num_swaps;

	for (i = 0; i < size; i++)
	{
		num_swaps = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				array[j] ^= array[j + 1];
				array[j + 1] ^= array[j];
				array[j] ^= array[j + 1];
				print_array(array, size);
				num_swaps++;
			}
		}

		if (num_swaps == 0)
			break;
	}
}
