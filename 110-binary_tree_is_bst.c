#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst - checks if binary tree is BST
 * @tree: pointer to the root node of the tree to check
 * @min: Minimum value of a node on left
 * @max: Maximum value of a node on right
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst(tree->left, min, tree->n - 1) &&
		is_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - checks if binary tree is BST
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst(tree, INT_MIN, INT_MAX));
}
