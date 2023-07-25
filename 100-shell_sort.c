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
 * shell_sort - sorts an array of integers in ascending order using the
 * Shell sort algorithm, using the Knuth sequence
 * @array: array of integers
 * @size: size of the array
*/
void shell_sort(int *array, size_t size)
{
	int gap = 1, i, j;

	while (gap < (int)size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (i = gap; i < (int)size; i++)
		{
			for (j = i; j >= gap && array[j] < array[j - gap]; j -= gap)
				swap_arr(&array[j], &array[j - gap]);
		}
		print_array(array, size);
		gap /= 3;
	}
}
