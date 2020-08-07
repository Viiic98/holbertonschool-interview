#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_node - Creates a binary tree node
 * @parent: Parent of the binary tree
 * @value: value of the new node
 * Return: Pointer to the new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t) + 1);
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
