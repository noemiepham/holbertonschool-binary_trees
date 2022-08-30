#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: is a pointer to the node to measure the depth
 * Return: the depth of a node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	if (tree->parent)
		depth = 1 + binary_tree_depth(tree->parent);

	return (depth);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor
 * @first: the first node
 * @second: the second node
 * Return: lowest common ancestor node or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	size_t depth_first = binary_tree_depth(first);
	size_t depth_second = binary_tree_depth(second);

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	if (depth_first < depth_second)
		return (binary_trees_ancestor(first, second->parent));
	
	else if (depth_first > depth_second)
		return (binary_trees_ancestor(first->parent, second));

	return (binary_trees_ancestor(first->parent, second->parent));
}
