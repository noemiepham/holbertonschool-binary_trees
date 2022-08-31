#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array:  pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: pointer to the root node of the created BST, or NULL
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tmp = NULL;
	size_t i;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		bst_insert(&tmp, array[i]);
	}
	return (tmp);
}
