#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: doubly linked list of integers
 * Return: void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *temp1, *curr;


	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	temp1 = (*list)->next;
	while (temp1 != NULL)
	{
		curr = temp1;
		while (curr->prev != NULL && curr->n < curr->prev->n)
		{
			swap(curr->prev, curr);
			if (curr->prev == NULL)
				*list = curr;
			print_list(*list);
		}
		temp1 = temp1->next;
	}
}

/**
 * swap - swap two nodes
 * @node1: first node
 * @node2: second node
 * Return: void
*/
void swap(listint_t *node1, listint_t *node2)
{
	/*edge cases 1- node1 is the head*/
	if (node1->prev == NULL && node2->next != NULL)
	{
		node2->next->prev = node1;
		node1->next = node2->next;
		node2->prev = NULL;
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
	node1->prev = node2;
	node2->next = node1;
}
