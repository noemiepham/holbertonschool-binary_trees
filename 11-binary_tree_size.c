#include "binary_trees.h"
/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: is a pointer to the root node of the tree
 * Return: The size of a binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size;
	size_t right_size;
	size_t size;

	if (tree == NULL)
		return (0);
	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	size = left_size + right_size + 1;

	return (size);
}
