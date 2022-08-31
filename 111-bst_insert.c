#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *newnode = NULL;

	if (tree == NULL || (*tree) == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	newnode = *tree;

	while (newnode)
	{
		if (newnode->n == value)
			return (NULL);

		if (newnode->n < value)
		{
			if (newnode->right == NULL)
			{
				newnode->right = binary_tree_node(newnode, value);
				return (newnode->right);
			}
			newnode = newnode->right;
		}
		if (newnode->n > value)
		{
			if(newnode->left == NULL)
			{
				newnode->left = binary_tree_node(newnode, value);
				return (newnode->left);
			}
			newnode = newnode->left;
		}
	}
	return (NULL);
}
