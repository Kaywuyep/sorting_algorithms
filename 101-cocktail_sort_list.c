#include "sort.h"
/**
 * swap_nodes - Swaps a node with its previous node in a doubly linked list
 * @list: Pointer to the head of the doubly linked list
 * @node: Pointer to the node to be swapped with its previous node
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *prev, *prev_prev, *next;

	if (node == NULL || node->prev == NULL)
		return;

	prev = node->prev;
	prev_prev = prev->prev;
	next = node->next;

	if (prev_prev != NULL)
	{
		prev_prev->next = node;
	}
	else
	{
		*list = node;
	}

	node->prev = prev_prev;
	node->next = prev;
	prev->prev = node;
	prev->next = next;

	if (next != NULL)
	{
		next->prev = prev;
	}
}
/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm.
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start = *list;
	listint_t *end = NULL;

	if (list == NULL || *list == NULL)
		return;

	do {
		swapped = 0;

		while (start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start->next);
				print_list(*list);
				swapped = 1;
			}
			else
				start = start->next;
		}

		if (swapped == 0)
			break;

		swapped = 0;
		end = start;

		while (start->prev != NULL)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(list, start);
				print_list(*list);
				swapped = 1;
			}
			else
				start = start->prev;
		}
	} while (swapped);
}
