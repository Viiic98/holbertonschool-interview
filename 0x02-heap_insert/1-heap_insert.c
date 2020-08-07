#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * verify - Verify if the value of actual n is greater than n of parent
 * @node: node to evaluate
 * Return: 1 if is greater or 0 if it isn't
 */
int verify(heap_t *node)
{
	if (node->n > node->parent->n)
		return (1);
	else
		return (0);
}
/**
 * swap - Swaps two node values
 * @node: Node to be swaped
 * Return: Node with the value swapped
 */
heap_t *swap(heap_t *node)
{
	int tmp;

	if (node->parent == NULL)
		return (NULL);
	tmp = node->n;
	node->n = node->parent->n;
	node->parent->n = tmp;

	return (node->parent);
}
/**
 * which_node - Verify where a node can be inserted
 * @root: pointer to node root
 * Return: Structure ver_node (node, childs and deep)
 */
ver_node *which_node(heap_t *root)
{
	heap_t *tail = root;
	ver_node *left, *right, *r;

	if (tail->left && tail->right)
	{
		left = which_node(tail->left);
		left->deep += 1;
		right = which_node(tail->right);
		right->deep += 1;
		if (left->deep <= right->deep)
			return (left);
		else
			return (right);
	} else if (tail->left == NULL && tail->right == NULL)
	{
		r = malloc(sizeof(ver_node));
		r->node = tail;
		r->childs = 2;
		r->deep = 0;
		return (r);
	} else if (tail->left != NULL && tail->right == NULL)
	{
		r = malloc(sizeof(ver_node));
		r->node = tail;
		r->childs = 1;
		r->deep = 0;
		return (r);
	}
	return (NULL);
}
/**
 * insert_node - Insert a node in a given node
 * @node: Parent node
 * @new: node to be inserted
 * Return: Anything
 */
void insert_node(heap_t *node, heap_t *new)
{
	heap_t *tmp = node;

	if (tmp->left == NULL)
	{
		tmp->left = new;
		new->parent = tmp;
	} else if (tmp->right == NULL)
	{
		tmp->right = new;
		new->parent = tmp;
	}
}
/**
 * heap_insert - Heap insertion
 * @root: pointer to root node
 * @value: value of the new node
 * Return: Pointer to new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *tmp = *root;
	ver_node *ver_n;

	new = binary_tree_node(NULL, value);
	if (root == NULL)
	{
		*root = new;
	}
	else
	{
		if (*root == NULL)
			*root = new;
		else
		{
			ver_n = which_node(*root);
			tmp = ver_n->node;
			insert_node(tmp, new);
			if (new->parent)
			{
				while (verify(new) == 1)
				{
					new = swap(new);
					if (new->parent == NULL)
						break;
				}
				return (new);
			}
			return (tmp);
		}
	}
	return (new);
}
