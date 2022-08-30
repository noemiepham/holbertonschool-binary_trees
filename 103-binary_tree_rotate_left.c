#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (tree == NULL || tree->right == NULL)
		return (NULL);

	tree->parent = tree->right;
	if (tree->right->left != NULL)
	{
		tree->right = tree->parent->left;
	}
	else
		tree->right = NULL;
	tree->parent->left = tree;

	tree = tree->parent;
	return (tree);
}
