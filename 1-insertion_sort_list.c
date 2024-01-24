#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;

    current = (*list)->next;

    while (current != NULL)
    {
        temp = current;

        while (temp->prev != NULL && temp->n < temp->prev->n)
        {
            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            temp->prev->next = temp->next;
            temp->next = temp->prev;
            temp->prev = temp->prev->prev;

            if (temp->prev != NULL)
                temp->prev->next = temp;

            if (temp->next == NULL)
                *list = temp;
            else
                temp->next->prev = temp;

            print_list(*list);
        }

        current = current->next;
    }
}
