#include "binary_trees.h"

/**
 * isBST - Check if a binary tree is BST
 * @tree: pointer to the root
 * @mini: min
 * @maxi: max
 * Return: 1 or 0 if itsnt
 */
int isBST(const binary_tree_t *tree, int mini, int maxi)
{
	if (tree == NULL)
		return (1);
	if (tree->n < mini || tree->n > maxi)
		return (0);
	return (isBST(tree->right, tree->n + 1, maxi) &&
		isBST(tree->left, mini, tree->n - 1));
}
/**
 * height - height of binary tree
 * @tree: pointer to the root
 * Return: height of the binary tree
 */
int height(const binary_tree_t *tree)
{
	int h_left, h_right;

	if (tree == NULL)
		return (0);

	h_left =  height(tree->left);
	h_right = height(tree->right);

	if (h_left > h_right)
		return (1 + h_left);
	else
		return (1 + h_right);
}
/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int h_l, h_r, diff;

	if (tree == NULL)
		return (1);
	if (!isBST(tree, INT_MIN, INT_MAX))
		return (0);
	h_l = height(tree->left);
	h_r = height(tree->right);
	diff = h_l > h_r ? h_l - h_r : h_r - h_l;
	if (diff <= 1 && binary_tree_is_avl(tree->left) &&
		binary_tree_is_avl(tree->right))
		return (1);
	return (0);
}
