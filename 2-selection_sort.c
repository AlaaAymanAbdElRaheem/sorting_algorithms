#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 *            using the Selection sort algorithm
 * @array: the array
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, o, indx_of_min;
	int temp;

	for (o = 0; o < size - 1; o++)
	{
		indx_of_min = o;
		for (i = o + 1; i < size; i++)
		{
			if (array[i] < array[indx_of_min])
				indx_of_min = i;
		}
		if (indx_of_min != o)
		{
			temp =  array[o];
			array[o] = array[indx_of_min];
			array[indx_of_min] = temp;
			print_array(array, size);
		}
	}
}
