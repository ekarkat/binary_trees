#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: Height of the tree, or 0 if tree is NULL
*/

size_t binary_tree_size(const binary_tree_t *tree)
{

	int left = 0;
	int right = 0;

	if (!tree)
		return (0);



	left = left + binary_tree_size(tree->left);
	right = right + binary_tree_size(tree->right);

	if (!tree->left && !tree->right)
		return (1);

	return ((left + right) + 1);
}
