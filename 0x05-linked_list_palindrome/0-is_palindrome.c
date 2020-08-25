#include "lists.h"
/**
 * is_palindrome - Verify if a linked list is palindrome
 * @head: pointer to head of linked list
 * Return: 1 if it's palindrome, 0 if it isn't
 */
int is_palindrome(listint_t **head)
{
	listint_t *h, *tail;
	int length, i, j;

	if (head && *head)
	{
		h = *head;
		/* Length */
		tail = h;
		while (tail->next)
		{
			length++;
			tail = tail->next;
		}
		for (i = 0; i < length; i++)
		{
			tail = h;
			for (j = i; j < length - 1; j++)
				tail = tail->next;
			if (h->n != tail->n)
				return (0);
			length--;
			h = h->next;
			if (i + 1 == length)
				return (1);
		}
	}
	return (0);
}
