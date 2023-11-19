#include "sort.h"
/**
 * swap - a function that swaps two variables
 * @a: variable
 * @b: variable
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - a function that compares two elmts and swaps
 * @array: array of elmets to be sorted
 * @size:m size of the array
 *
 * Description: this is a function that compares two adacent elements
 * and swaps then untill the are in the intended order which could
 * be either ascending or decending order
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j = size;
	bool bubble = false;

	if (array == NULL || size < 2)
		return;

	while (bubble == false)
	{
		bubble = true;
		for (i = 0; i < j - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array + i, array + i + 1);
				print_array(array, size);
				bubble = false;
			}
		}
		j--;
	}
}
