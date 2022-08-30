#include "binary_trees.h"
/**
 * binany_child_hight - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: numero de leak of tree branch
 */
int binany_child_hight(const binary_tree_t *tree)
{
	ssize_t left_height;
	ssize_t right_height;

	if (tree == NULL)
		return (0);
	left_height = 1 + binany_child_hight(tree->left);

	right_height = 1 + binany_child_hight(tree->right);

	if (left_height < right_height)
		return (right_height);
	return (left_height);
}

/**
 * print_level - function that print every node of 1 level
 * @tree: Root node of tree to traverse
 * @level: level of the tree
 * @func: Pointer to a function call for each node
 */
void print_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_level(tree->left, level - 1, func);
		print_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height = binany_child_hight(tree);
	size_t level;

	if (tree == NULL || func == NULL)
		return;

	for (level = 1; level <= height; level++)
		print_level(tree, level, func);
}
