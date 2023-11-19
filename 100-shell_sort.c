#include "sort.h"
/**
 * swap_shell_sort - Swaps the positions of two elements in an array
 * @array: Pointer to the array
 * @a: Index of the first element
 * @b: Index of the second element
 */
void swap_shell_sort(int *array, size_t a, size_t b)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}
/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm (Knuth sequence)
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
        size_t i, j;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for(i = gap; i < size; ++i)
		{
			for(j = i; j >= gap && array[j - gap] > array[j]; j -= gap)
			{
				swap_shell_sort(array, j, j - gap);
			}
		}

		print_array(array, size);

		gap /= 3;
	}
}
