#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
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
