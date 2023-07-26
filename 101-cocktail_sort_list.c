#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: the doubly linked list
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *head, *itr_node, *temp;

	if (list == NULL || *list == NULL  || (*list)->next == NULL)
		return;

	head = *list;
	itr_node = *list;
	while (swapped)
	{
		swapped = 0;
		while (itr_node->next != NULL)
		{
			if (itr_node->n > itr_node->next->n)
			{
				temp = itr_node->next;
				swapping(&head, itr_node, temp);
				swapped = 1;
				print_list(head);
				continue;
			}
			itr_node = itr_node->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (itr_node->prev != NULL)
		{
			if (itr_node->n < itr_node->prev->n)
			{
				temp = itr_node->prev;
				swapping(&head, temp, itr_node);
				swapped = 1;
				print_list(head);
				continue;
			}
			itr_node = itr_node->prev;
		}
	}
	*list = head;
}

/**
 * swapping - swap two nodes
 * @head: pointer to the head node
 * @node1: first node
 * @node2: second node
 * Return: void
*/
void swapping(listint_t **head, listint_t *node1, listint_t *node2)
{
	/*edge cases 1- node1 is the head*/
	if (node1->prev == NULL && node2->next != NULL)
	{
		node2->next->prev = node1;
		node1->next = node2->next;
		node2->prev = NULL;
		*head = node2;
	}
	/*edge case 2- node2 is the tail*/
	else if (node2->next == NULL && node1->prev != NULL)
	{
		node1->prev->next = node2;
		node2->prev = node1->prev;
		node1->next = NULL;
	}
	/*normal case*/
	else if (node1->prev != NULL && node2->next != NULL)
	{
		node1->prev->next = node2;
		node2->next->prev = node1;
		node1->next = node2->next;
		node2->prev = node1->prev;
	}
	else
	{
		node1->next = NULL;
		node2->prev = NULL;
		if (node2->prev == NULL)
			*head = node2;
	}
	node1->prev = node2;
	node2->next = node1;
}
