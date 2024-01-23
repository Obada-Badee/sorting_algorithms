#include "sort.h"

/**
 * counting_sort - The counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int j, max = 0, *output, *count;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = calloc((max + 1), sizeof(int));
	output = malloc(size * sizeof(int));
	if (count == NULL || output == NULL)
		return;
	for (i = 0; i < size; i++)
		count[array[i]] += 1;
	for (j = 1; j <= max; j++)
		count[j] += count[j - 1];

	print_array(count, max + 1);

	for (i = 0; i < size; i++)
	{
		j = array[i];
		count[j]--;
		output[count[j]] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
