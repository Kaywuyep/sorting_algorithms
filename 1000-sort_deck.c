#include "deck.h"

/**
 * _strcmp - compare two strings
 * @str1: string
 * @str2: string
 * Return: 1 if str1 and str2 are equal, 0 if they are not equal
 */
int _strcmp(const char *str1, char *str2)
{
	size_t i = 0;

	if (str1 == NULL)
		return (0);
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str1[i] == '\0' && str2[i])
		return (0);
	return (1);
}

/**
 * get_card_position - return the position based on the card
 * @node: represent the card
 * Return: return the card position
 */
int get_card_position(deck_node_t *node)
{
	int card_value;

	card_value = (*node).card->value[0] - '0';
	if (card_value < 50 || card_value > 57)
	{
		if (_strcmp((*node).card->value, "Ace") == 1)
			card_value = 1;
		else if (_strcmp((*node).card->value, "10") == 1)
			card_value = 10;
		else if (_strcmp((*node).card->value, "Jack") == 1)
			card_value = 11;
		else if (_strcmp((*node).card->value, "Queen") == 1)
			card_value = 12;
		else if (_strcmp((*node).card->value, "King") == 1)
			card_value = 13;
	}
	card_value += (*node).card->kind * 13;
	return (card_value);
}

/**
 * swap_cards - swap a card with its previous one
 * @current_card: card to be swapped
 * @deck: card deck
 * Return: return a pointer to the card that was entered
 */
deck_node_t *swap_cards(deck_node_t *current_card, deck_node_t **deck)
{
	deck_node_t *previous_card = current_card->prev, *current = current_card;

	previous_card->next = current->next;
	if (current->next)
		current->next->prev = previous_card;
	current->next = previous_card;
	current->prev = previous_card->prev;
	previous_card->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*deck = current;
	return (current);
}

/**
 * insertion_sort_deck - function that sorts a doubly linked deck
 * of integers in ascending order using the Insertion sort algorithm
 * @deck: double linked deck to sort
 */
void insertion_sort_deck(deck_node_t **deck)
{
	int prev_card_value, current_card_value;
	deck_node_t *current_node;

	if (deck == NULL || (*deck)->next == NULL)
		return;

	current_node = (*deck)->next;

	while (current_node)
	{
		/* preparing the previous card value */
		if (current_node->prev)
		{
			prev_card_value = get_card_position((current_node->prev));
			current_card_value = get_card_position(current_node);
		}

		while ((current_node->prev) && (prev_card_value > current_card_value))
		{
			prev_card_value = get_card_position((current_node->prev));
			current_card_value = get_card_position(current_node);
			current_node = swap_cards(current_node, deck);
		}
		current_node = current_node->next;
	}
}

/**
 * sort_deck - sort a deck you put in using
 * insertion sort algorithm
 * @deck: deck
 */
void sort_deck(deck_node_t **deck)
{
	insertion_sort_deck(deck);
}
