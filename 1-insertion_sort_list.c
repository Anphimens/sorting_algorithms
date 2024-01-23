#include "sort.h"

/**
 * insertion_sort_list - sorts a list using insertion sort.
 * @list - linked list of ints.
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *nextnode;
	if (!(*list) || (*list)->next == NULL)
		return;
	sorted = NULL;
	current = (*list);
	while (current != NULL)
	{
		
		nextnode = current->next;
		while (sorted != NULL && sorted->n < current->n)
			sorted = sorted->next;
		if(sorted == NULL)
		{
			current->next = sorted;
			current->prev = NULL;
			/*if (sorted != NULL)
				sorted->prev = current;*/
			sorted = current;
		}
		else
		{
			if (sorted->prev != NULL)
				sorted->prev->next = current;
			current->prev = sorted->prev;
			current->next = sorted;
			sorted->prev = current;
			if (current->prev == NULL)
				sorted = current;
		}
		print_list(*list);
		current = nextnode;
	}
	(*list) = sorted;
}
