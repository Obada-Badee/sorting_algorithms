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
 * bitonic_merge - Merge two betonic sequences
 * @array: The array to be sorted
 * @dir: The direction of ordering the sequence
 * @low: The lowest index in the sequence
 * @cnt: The number of elements in the sequence
 */
void bitonic_merge(int *array, int dir, int low, int cnt)
{
	int k = cnt / 2, i;

	if (cnt <= 1)
		return;

	for (i = low; i < low + k; i++)
		if (dir == (array[i] > array[i + k]))
			swap(array + i, array + i + k);

	bitonic_merge(array, dir, low, k);
	bitonic_merge(array, dir, low + k, k);
}

/**
 * make_bitonic - Transform the sequence into betonic sequence
 * @array: The array to be sorted
 * @dir: The direction of ordering the sequence
 * @low: The lowest index in the sequence
 * @cnt: The number of elements in the sequence
 * @size: The size of the array
 */
void make_bitonic(int *array, int dir, int low, int cnt, size_t size)
{
	int k = cnt / 2;

	if (cnt <= 1)
		return;

	if (dir)
		printf("Merging [%d/%ld] (UP):\n", cnt, size);
	else
		printf("Merging [%d/%ld] (DOWN):\n", cnt, size);

	print_array(array + low, cnt);

	make_bitonic(array, 1, low, k, size);
	make_bitonic(array, 0, low + k, k, size);

	bitonic_merge(array, dir, low, cnt);
	if (dir)
		printf("Result [%d/%ld] (UP):\n", cnt, size);
	else
		printf("Result [%d/%ld] (DOWN):\n", cnt, size);

	print_array(array + low, cnt);
}

/**
 * bitonic_sort - The bitonic_sort sorting algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	make_bitonic(array, 1, 0, size, size);
}
