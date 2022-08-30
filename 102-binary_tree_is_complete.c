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

	if (tree == NULL)
		return (0);
	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return (left_size + right_size + 1);
}

/**
 * iscomplete - function that check if the tree is complete
 * @tree: pointer to the root node of the tree
 * @i: Index of node
 * @size: Number of node
 * Return: 0 if false, 1 if true
 */
int iscomplete(const binary_tree_t *tree, int i, int size)
{
	if (tree == NULL)
		return (1);

	if (i >= size)
		return (0);

	return (iscomplete(tree->left, 2 * i + 1, size) &&
		iscomplete(tree->right, 2 * i + 2, size));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if false, 1 if true
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int size = binary_tree_size(tree);
	int index = 0;

	if (tree == NULL)
		return (0);

	if (iscomplete(tree, index, size) == 0)
		return (0);

	return (1);
}
