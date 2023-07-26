#include "sort.h"
/**
 * merge - merges the divided array
 * @array: array of integers
 * @tmp: temporary array
 * @low: lowest index
 * @mid: middle index
 * @high: highest index
*/
void merge(int *array, int *tmp, int low, int mid, int high)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + low, mid - low + 1);
	printf("[right]: ");
	print_array(array + mid + 1, high - mid);
	i = low;
	j = mid + 1;
	k = 0;
	while (i <= mid && j <= high)
	{
		if (array[i] < array[j])
			tmp[k++] = array[i++];
		else
			tmp[k++] = array[j++];
	}
	while (i <= mid)
		tmp[k++] = array[i++];
	while (j <= high)
		tmp[k++] = array[j++];
	for (i = low, k = 0; i <= high; i++, k++)
		array[i] = tmp[k];
	printf("[Done]: ");
	print_array(array + low, high - low + 1);
}
/**
 * divide - divides the array recursively
 * @array: array of integers
 * @tmp: temporary array
 * @low: lowest index
 * @high: highest index
*/
void divide(int *array, int *tmp, int low, int high)
{
	int mid;

	if (low >= high)
		return;
	mid = low + (high - low) / 2;
	divide(array, tmp, low, mid);
	divide(array, tmp, mid + 1, high);
	merge(array, tmp, low, mid, high);
}
/**
 * merge_sort - sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: array of integers
 * @size: size of the array
*/
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (array == NULL || size < 2)
		return;
	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return;

	divide(array, tmp, 0, (int)size - 1);
	free(tmp);
}
