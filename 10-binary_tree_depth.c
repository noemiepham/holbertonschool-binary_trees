#include "binary_trees.h"
/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: is a pointer to the node to measure the depth
 * Return: the depth of a node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{

	size_t left_depth;
	size_t right_depth;
	size_t depth;
	/* Root being null means tree doesn't exist */
	if (tree == NULL || tree->parent == NULL)
		return (0);
	/* Get the depth of the left and right subtree */
	/* using recursion. */

	left_depth = binary_tree_depth(tree->parent);
	right_depth = binary_tree_depth(tree->parent);

	/* Choose the larger one and add the root to it. */

	if (left_depth > right_depth)
		depth = left_depth + 1;
	else
		depth = right_depth + 1;
	return (depth);
}
