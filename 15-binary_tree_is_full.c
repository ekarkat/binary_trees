#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 * Return: 0 if the tree is not full else if the tree is full
*/

int binary_tree_is_full(const binary_tree_t *tree)
{
	int left;
	int right;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	right = binary_tree_is_full(tree->right);
	left = binary_tree_is_full(tree->left);

	if (left == 0 || right == 0)
		return (0);
	return (1);
}
