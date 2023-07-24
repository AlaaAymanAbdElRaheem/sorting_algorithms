#include "sort.h"
/**
 * swap_arr - swaps two elements in aray
 * @a: first number
 * @b: second number
*/
void swap_arr(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
/**
 * partition - partition the array into smaller subarrays
 * @array: array to sort
 * @low: lower bound of partition
 * @high: higher bound of partition
 * @size: size of array
 * Return: index of the pivot
*/
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	/*keep track of the curr pos of the pivot with i in the middle*/
	i = low;
	for (j = low; j < high; j++)
	{
		if (pivot > array[j])
		{
			if (array[i] != array[j])
			{
				swap_arr(&array[j], &array[i]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[high])
	{
		swap_arr(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}
/**
 * sort - sorting array recursivly using quick sort
 * @array: array to sort
 * @low: start of the partition
 * @high: end of the partition
 * @size: size of array
*/
void sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low >= high)
		return;

	pivot = partition(array, low, high, size);
	sort(array, low, pivot - 1, size);
	sort(array, pivot + 1, high, size);
}
/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array of integers
 * @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	sort(array, 0, (int)size - 1, size);
}
