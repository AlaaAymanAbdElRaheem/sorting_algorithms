#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: the doubly linked list
 */

void cocktail_sort_list(listint_t **list)
{
	int swap = 1;
	listint_t *head, *itr_node;

	if (list == NULL || *list == NULL)
		return;

	head = *list;
	itr_node = *list;

	while (swap)
	{
		swap = 0;
		while (itr_node->next != NULL)
		{
			if (itr_node->n > itr_node->next->n)
			{
				swap_next(itr_node);
				swap = 1;
				print_list(head);
				continue;
			}
			itr_node = itr_node->next;
		}
		if (swap == 0)
			break;
		swap = 0;
		while (itr_node->prev != NULL)
		{
			if (itr_node->n < itr_node->prev->n)
			{
				swap_prev(&head, itr_node);
				swap = 1;
				print_list(head);
				continue;
			}
			itr_node = itr_node->prev;
		}
	}
	*list = head;
}

/**
 * swap_next - swaps the current node with the next
 * @itr_node: current node
 */

void swap_next(listint_t *itr_node)
{
	listint_t *temp;

	temp = itr_node->next;

	if (itr_node->prev != NULL)
		itr_node->prev->next = temp;
	if (temp->next != NULL)
		temp->next->prev = itr_node;
	temp->prev = itr_node->prev;
	itr_node->next = temp->next;
	itr_node->prev = temp;
	temp->next = itr_node;
}

/**
 * swap_prev - swaps the current node with the prev node
 * @head: pointer to the head node
 * @itr_node: current node
 */

void swap_prev(listint_t **head, listint_t *itr_node)
{
	listint_t *temp;

	temp = itr_node->prev;

	if (itr_node->next)
		itr_node->next->prev = temp;
	if (temp->prev)
		temp->prev->next = itr_node;
	temp->next = itr_node->next;
	itr_node->next = temp;
	itr_node->prev = temp->prev;
	temp->prev = itr_node;

	if (itr_node->prev == NULL)
		*head = itr_node;
}
