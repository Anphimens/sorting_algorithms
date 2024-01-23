#include "sort.h"

/**
 * bubble_sort - sorts an array in ascending order with bubble method.
 * @array: array to sort.
 * @size: size of the array.
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, k;
	for (i = 0; i < size; i++)
	{
		for (k = 0; k < size - 1 - i; k++)
		{
			if (array[k] > array[k+1])
			{
				int j = array[k];
				array[k] = array[k + 1];
				array[k + 1] = j;
				print_array(array, size);
			}
		}
	}
}
