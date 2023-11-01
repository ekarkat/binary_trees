#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: Height of the tree, or 0 if tree is NULL
*/

size_t binary_tree_leaves(const binary_tree_t *tree)
{

	int left = 0;
	int right = 0;

	if (!tree)
		return (0);

	left = left + binary_tree_leaves(tree->left);
	right = right + binary_tree_leaves(tree->right);

	if (!tree->left && !tree->right)
		return (1);

	return ((left + right));
}
