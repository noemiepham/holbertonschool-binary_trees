#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp;
	
	if (tree == NULL || tree->left == NULL)
		return (NULL);

	tree->parent = tree->left;
	tmp = tree->left->right;

	if (tmp != NULL)
	{
		tree->left = tree->parent->right;
		tmp->parent = tree;
	}
	else
		tree->left = NULL;
	tree->parent->right = tree;
	tree = tree->parent;

	return (tree);
}
