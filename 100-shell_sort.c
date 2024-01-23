#include "sort.h"

/**
 * shell_sort - The shell sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, gap = 1;

	if (size < 2)
		return;
	while (gap < (int)size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; ((int)j >= gap) &&
					(array[j - gap] > tmp); j -= gap)
				array[j] = array[j - gap];

			array[j] = tmp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
