#include "sort.h"

void swap(int *array, int i, int j)
{
	if (i != j)
	{
		array[i] ^= array[j];
		array[j] ^= array[i];
		array[i] ^= array[j];
	}
}


int lomuto_partition(int *array, int low, int high, size_t __attribute__((unused)) size)
{
	int pivot = array[high];
	int j;
	int i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array, i, j);
		}
	}

	swap(array, i + 1, high);
	return (i + 1);

}

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;
	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		print_array(array, size);
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}


void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}
