#include "sort.h"
/**
 * _calloc - allocates memory for an array, using malloc,
 * and initializes it to zero
 * @size: size of array
 * @elem_size: size of each element
 * Return: pointer to allocated memory
*/
void *_calloc(unsigned int size, unsigned int elem_size)
{
	char *ptr;
	unsigned int i;

	if (size == 0)
		return (NULL);

	ptr = malloc(size * elem_size);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		ptr[i] = 0;

	return (ptr);
}

/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: void
*/
void counting_sort(int *array, size_t size)
{
	/* step 1: determine the max element */
	int max = 0, *count, *sorted;
	int i;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	/* step 2: init array of max + 1 */
	count = _calloc(max + 1, sizeof(int));
	/* step 3: freq the elements */
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;

	/* step 4: accumulate the sum */
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);
	/* step 5: put each element in its position */
	sorted = _calloc(size, sizeof(int));
	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	/* step 6: copy sorted array in the original one */
	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];
	/* step 7: free memory */
	free(count);
	free(sorted);
}
