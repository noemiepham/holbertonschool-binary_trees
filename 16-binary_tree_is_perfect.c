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
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: numero de leak of tree branch
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height;
	int right_height;

	if (tree == NULL)
		return (0);
	left_height = binany_child_hight(tree->left);
	right_height = binany_child_hight(tree->right);
	return (left_height - right_height);
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 is perfect, 0 is not.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int perfect;

	perfect = binary_tree_balance(tree);

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left != NULL && tree->right != NULL &&
	    perfect == 0)
		return (binary_tree_is_perfect(tree->left) &&
			   binary_tree_is_perfect(tree->right));
	return (0);
}
