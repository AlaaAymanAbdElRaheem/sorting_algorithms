#include "sort.h"

/**
 * heap_sort - sorts array of int in ascending order using Heap sort algorithm
 * @array: array that will be sorted
 * @size: the size of the array
*/

void heap_sort(int *array, size_t size)
{
	int i, temp;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, i, size, size);
	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, 0, i, size);
	}
}

/**
 * heapify - make an array a max heap
 * @array: the array
 * @start_index: the started point
 * @stop: the point thah the heapify will stop
 * @size: size of the array
*/

void heapify(int *array, int start_index, size_t stop, size_t size)
{
	int largest = start_index, temp;
	int first_child = 2 * start_index + 1;
	int second_child = 2 * start_index + 2;

	if (first_child < (int) stop && array[first_child] > array[largest])
		largest = first_child;
	if (second_child < (int) stop && array[second_child] > array[largest])
		largest = second_child;
	if (largest != start_index)
	{
		temp = array[start_index];
		array[start_index] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		heapify(array, largest, stop, size);
	}
}
