#include "binary_trees.h"

/**
 * binary_tree_nodes - function that count the node in binary tree
 * @tree: pointer to the root node of the tree to count the nodes
 * Return: Number of nodes or o if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t s = 0;

	if (tree == NULL)
		return (0);

	if (tree->left || tree->right)
		s = binary_tree_nodes(tree->right) + 1 + binary_tree_nodes(tree->left);
	else
		return (0);

	return (s);
}
