#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * insert_node - Insert a new node in a singly linked list
 * @head: pointer to linked list
 * @number: number to be inserted
 * Return: pointer to new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current = *head, *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	if (head == NULL || current == NULL)
	{
	current = new;
	new->next = NULL;
	return (new);
	}
	if (current->next == NULL)
	{
		current->next = new;
		new->next = NULL;
		return (new);
	}
	if (number < current->n)
	{
		new->next = current;
		*head = new;
		return (new);
	}
	while (current->next)
	{
		if (number < current->next->n)
		{
			new->next = current->next;
			current->next = new;
			return (new);
		}
		current = current->next;
	}
	current->next = new;
	new->next = NULL;
	return (new);
}
