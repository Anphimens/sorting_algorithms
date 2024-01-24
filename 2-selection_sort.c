#include "sort.h"

/**
 * selection_sort - sorts an array of ints using selection sort method.
 * @array: array of int
 * @size: size of the array.
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int store, min_val;
	bool min_found;
	size_t i, j = 0;
	if (size <= 1)
	{
		print_array(array, size);
		return;
	}
	minval = i;
	min_found = false;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
			if (array[minval] > array[j])
			{
				minval = j;
				min_found = true;
			}
		if (min_found)
		{
			array[i] ^= array[minval];
			array[minval] ^= array[i];
			array[i] ^= array[minval];

			print_array(array, size);
		}
	}
}
