#ifndef DECK_H
#define DECK_H

#include <stddef.h>
#include <stdlib.h>

/**
 * enum kind_e - The kind of a playing card
 * @SPADE: The Spade kind
 * @HEART: The HEART kind
 * @CLUB: The CLUB kind
 * @DIAMOND: The DIAMOND kind
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
 * sort_deck - Sort a dick of cards
 * @deck: A Pointer to the list of cards
 */
void sort_deck(deck_node_t **deck);

#endif /* DECH_H */
