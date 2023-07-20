#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 *           using the Bubble sort algorithm
 * @array: the array needed to be sorted
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t o, i;
	int flag, temp;

	if (array == NULL || size == 0)
		return;

	for (o = 0; o < size - 1; o++)
	{
		flag = 0;
		for (i = 0; i < size - 1 - o; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}
