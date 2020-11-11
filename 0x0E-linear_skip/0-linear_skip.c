#include "search.h"
/**
 * linear_skip- searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 * Return: pointer on the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *exp;

	if (list == NULL)
		return (NULL);
	current = list;
	exp = current->express;
	while (exp != NULL)
	{
		printf("Value checked at index [%zu] = [%d]\n", exp->index, exp->n);
		if (value > exp->n)
		{
			current = exp;
			exp = exp->express;
		}
		else
			break;
	}
	if (exp == NULL)
	{
		exp = current;
		while (exp->next)
			exp = exp->next;
	}
	printf("Value found between indexes [%zu] and [%zu]\n", current->index,
								exp->index);
	while (current != NULL)
	{
		printf("Value checked at index [%zu] = [%d]\n", current->index, current->n);
		if (value == current->n || current->next == NULL)
			break;
		current = current->next;
	}
	if (current->n != value)
		return (NULL);
	return (current);
}
