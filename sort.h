#ifndef SORT_H
#define SORT_H

/* "Header files" */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>


/* "Structs" */
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* "Printing funtions" */
/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size);
/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list);

/* "Sorting Algorithms" */
/**
 * bubble_sort - The bubble sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size);
/**
 * insertion_sort_list - The insertion sort algorithm
 * @list: The list to be sorted
 */
void insertion_sort_list(listint_t **list);
/**
 * selection_sort - The selection sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size);

#endif /* SORT_H */
