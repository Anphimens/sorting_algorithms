# include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *start;

	if (!(*list) || (*list)->next == NULL)
		return;
	current = (*list);
	if (current->prev != NULL)
		current = current->prev;

	while (current != NULL)
	{
		if (current->prev == NULL && current->n > current->next->n)
		{
			start = current->next;
			current->next = current->next->next;
			current->next->prev = current;
			current->prev = start;
			start->next = current;
			start->prev = NULL;
			current = start;
			(*list) = start;
		}
		else if (current->prev != NULL && current->n > current->next->n)
		{
			temp = current->next;
			temp->next = current->next->next;
			temp->prev = current->prev;

			current->prev = temp;
			current->next = temp->next;
			temp->next = current;
			current = temp;
			current->prev->next = temp;
			/*print_list(*list);*/
		}
		else
		{
			current = current->next;
			continue;
		}
		while (current->prev != NULL)
			current = current->prev;
		(*list) = current;
		print_list(*list);
	}
}
