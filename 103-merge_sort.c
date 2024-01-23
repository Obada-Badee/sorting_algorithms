#include "sort.h"

/**
 * copy_array - Swap two elements
 * @src: The source array
 * @dest: The destination array
 * @size: The number of elements to be copied
 */
void copy_array(int *src, int *dest, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		dest[i] = src[i];
}

/**
 * merge - Merge two sorted lists
 * @a: The array to be sorted
 * @b: The array that will store the result
 * @begin: The smallest index in the array
 * @mid: The middle index
 * @end: The size of the array
 */
void merge(int *a, int *b, size_t begin, size_t mid, size_t end)
{
	size_t i = begin, j = mid, k;

	for (k = begin; k < end; k++)
	{
		if (i < mid && (j >= end || a[i] <= a[j]))
		{
			b[k] = a[i];
			i++;
		}
		else
		{
			b[k] = a[j];
			j++;
		}
	}
}


/**
 * split_merge - Split the array into lists of one element
 *		 and merge these lists into a sorted list
 * @a: The array to be sorted
 * @b: The array that will store the result
 * @begin: The smallest index in the array
 * @end: The size of the array
 */
void split_merge(int *a, int *b, size_t begin, size_t end)
{
	int mid;

	if (end - begin <= 1)
		return;

	mid = (begin + end) / 2;
	split_merge(a, b, begin, mid);
	split_merge(a, b, mid, end);

	printf("Merging...\n[left]: ");
	print_array((a + begin), mid - begin);
	printf("[right]: ");
	print_array((a + mid), end - mid);

	merge(a, b, begin, mid, end);
	copy_array(b + begin, a + begin, end - begin);

	printf("[Done]: ");
	print_array((b + begin), end - begin);
}
/**
 * merge_sort - The merge_sort sorting algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *copy;

	if (array == NULL && size < 2)
		return;
	copy = malloc(size * sizeof(int));
	if (copy == NULL)
		return;
	split_merge(array, copy, 0, size);
	free(copy);
}
