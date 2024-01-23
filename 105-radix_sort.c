#include "sort.h"

/**
 * c_sort - The counting sort algorithm
 * @array: The array to be sorted
 * @output: A helper array
 * @size: The size of the array
 * @exp: The exponent of 10 used to sort the array
 */
void c_sort(int *array, int *output, size_t size, size_t exp)
{
	size_t i;
	int j, count[10] = {0};

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;
	for (j = 1; j < 10; j++)
		count[j] += count[j - 1];

	for (j = size - 1; j >= 0; j--)
	{
		i = (array[j] / exp) % 10;
		count[i]--;
		output[count[i]] = array[j];
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - The radix sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	int max = 0, *output;

	if (array == NULL || size < 2)
		return;

	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	for (i = 1; (max / i) > 0; i *= 10)
	{
		c_sort(array, output, size, i);
		print_array(array, size);
	}

	free(output);
}
