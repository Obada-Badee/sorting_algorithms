#include "deck.h"

/**
 * swap - Swap two nodes in place
 * @first: The first node
 * @second: The second node
 */
void swap(deck_node_t *first, deck_node_t *second)
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
 * kind - Find the kind of a card
 * @node: A pointer to the place of the card in a deck if cards
 *
 * Return: The kind of a card
 */
int kind(deck_node_t *node)
{
	return (node->card->kind);
}

/**
 * value - Find the value of a card
 * @node: A pointer to the place of the card in a deck if cards
 *
 * Return: The value of a card
 */
int value(deck_node_t *node)
{
	if (strcmp(node->card->value, "Ace") == 0)
		return (1);
	if (*(node->card->value) > 49 && *(node->card->value) < 58
			&& *((node->card->value) + 1) == '\0')
		return (*(node->card->value) - 48);
	if (strcmp(node->card->value, "10") == 0)
		return (10);
	if (strcmp(node->card->value, "Jack") == 0)
		return (11);
	if (strcmp(node->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_kind_value - Use insertion sort to sort a deck of cards
 * @list: The list to be sorted
 * @cmp_type: If set to 0 sort by value - otherwise sort by kind
 */
void insertion_sort_kind_value(deck_node_t **list, int cmp_type)
{
	deck_node_t *tmp, *prev, *current = NULL;

	if (list && *list)
		current = (*list)->next;
	while (current)
	{
		prev = current->prev;
		if ((cmp_type && kind(current) >= kind(prev)) ||
				(!cmp_type && value(current) >= value(prev)))
		{
			current = current->next;
			continue;
		}

		tmp = current;
		current = current->next;
		while ((cmp_type && prev && kind(tmp) < kind(prev))
				|| (!cmp_type && prev && value(tmp) < value(prev)))
		{
			swap(prev, tmp);
			if (tmp->prev == NULL)
				*list = tmp;
			prev = tmp->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards
 * @deck: The deck to be sorted
 *
 * Return:void
 */
void sort_deck(deck_node_t **deck)
{
	if (deck && *deck && (*deck)->next)
	{
		insertion_sort_kind_value(deck, 0);
		insertion_sort_kind_value(deck, 1);
	}
}
