#include "sort.h"

/**
 * selection_sort - sorts an array of ints using selection sort method.
 * @array: array of int
 * @size: size of the array.
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int store;
	size_t i, j = 0;
	if (size <= 1)
	{
		print_array(array, size);
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
			if (array[i] > array[j])
			{
				store = array[j];
				array[j] = array[i];
				array[i] = store;
			}
		print_array(array, size);
	}
}
