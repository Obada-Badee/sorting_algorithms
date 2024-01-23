#include "sort.h"
#include <stdio.h>

/**
 * swap - Swap two nodes in place
 * @first: The first node
 * @second: The second node
 */
void swap(listint_t *first, listint_t *second)
{
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
	if (second->prev)
		second->prev->next = second;
	first->prev = second;
}

/**
 * cocktail_sort_list - The cocktail sort algorithm
 * @list: The list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = *list;
	while (1)
	{
		swapped = 0;
		while (current->next)
		{
			if (current->n > current->next->n)
			{
				swapped = 1;
				swap(current, current->next);
				if (current->prev->prev == NULL)
					*list = current->prev;
				print_list(*list);
				continue;
			}
			current = current->next;
		}
		while (current->prev)
		{
			if (current->n < current->prev->n)
			{
				swapped = 1;
				swap(current->prev, current);
				if (current->prev == NULL)
					*list = current;
				print_list(*list);
				continue;
			}
			current = current->prev;
		}
		if (swapped == 0)
			break;
	}
}
