#include "sort.h"
/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 *              algorithm with Knuth sequence
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;
	gap = 1;

	for (gap = 1; gap < size; gap = 3 * gap + 1)
		;

	for(gap = (gap - 1) / 3; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = temp;
		}
		print_array(array, size);
	}
}
