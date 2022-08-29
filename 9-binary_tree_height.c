#include "binary_trees.h"
#include <stdio.h>
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: is a pointer to the root node of tree measure the height
 * Return: height of tree. 0 is failure.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;
	size_t height;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
	{
		return (0);
	}

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	/* Find the height of both subtrees */
	if (left_height >= right_height)
		height = left_height + 1;
	else
		height = right_height + 1;

	/* and use the larger one */
return (height);
}
