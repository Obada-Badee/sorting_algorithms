#ifndef DECK_H
#define DECK_H

#include <string.h>

/**
 * enum kind_e - The kind of a playing card
 * @SPADE: The Spade kind
 * @HEART: The Heart kind
 * @CLUB: The Club kind
 * @DIAMOND: The Diamond kind
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/**
 * sort_deck - Sort a deck of cards
 * @deck: The deck to be sorted
 *
 * Return:void
 */
void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
