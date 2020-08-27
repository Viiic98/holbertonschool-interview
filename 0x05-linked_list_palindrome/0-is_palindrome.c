#include "lists.h"
/**
 * is_palindrome - Verify if a linked list is palindrome
 * @head: pointer to head of linked list
 * Return: 1 if it's palindrome, 0 if it isn't
 */
int is_palindrome(listint_t **head)
{
	listint_t *tail = *head;
	int array[4352], i, j = 0;

	if (*head == NULL || (tail && !tail->next))
		return (1);
	while (tail->next)
	{
		array[j] = tail->n, j++;
		tail = tail->next;
	}
	array[j] = tail->n;
	for (i = 0; i <= j / 2; i++, j--)
	{
		if (array[i] != array[j])
			return (0);
	}
	return (1);
}
