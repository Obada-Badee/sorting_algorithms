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
 * sift_down - Perform the sift down operation on the heap
 * @array: The array to be sorted
 * @size: The actual size of the array
 * @init_size: The size of the unsorted part of the array
 * @root: The root of heap data structure
 */
void sift_down(int *array, int size, int init_size, int root)
{
	int largest = root, left, right;

	left = root * 2 + 1;
	right = left + 1;

	if (left < init_size && array[left] > array[largest])
		largest = left;
	if (right < init_size && array[right] > array[largest])
		largest = right;
	if (largest != root)
	{
		swap(array + largest, array + root);
		print_array(array, size);
		sift_down(array, size, init_size, largest);
	}
}
/**
 * heap_sort - The heap sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, size, i);

	for (i = size - 1; i >= 1; i--)
	{
		swap(array, array + i);
		print_array(array, size);
		sift_down(array, size, i, 0);
	}
}
