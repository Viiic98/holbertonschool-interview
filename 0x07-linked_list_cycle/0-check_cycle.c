#include "lists.h"
/**
* check_cycle - Check if a linked list has a cycle in it
* @list: pointer to linked list
* Return: 1 if has a cycle 0 if it hasn't
*/
int check_cycle(listint_t *list)
{
	listint_t *a = list, *b = list;

	if (list == NULL)
		return (0);
	while (a->next && b->next && b->next->next)
	{
		a = a->next;
		b = b->next->next;
		if (a == b)
			return (1);
	}
	return (0);
}
