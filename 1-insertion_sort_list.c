#include "sort.h"

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
 * insertion_sort_list - The insertion sort algorithm
 * @list: The list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *prev, *current = NULL;

	if (list && *list)
		current = (*list)->next;
	while (current)
	{
		prev = current->prev;
		if (current->n >= prev->n)
		{
			current = current->next;
			continue;
		}

		tmp = current;
		current = current->next;
		while (prev && tmp->n < prev->n)
		{
			swap(prev, tmp);
			if (tmp->prev == NULL)
				*list = tmp;
			print_list(*list);
			prev = tmp->prev;
		}
	}
}
