#include "binary_trees.h"

/**
 * count - return 0 if full
 * @node: the root
 * Return: return 0 if full
*/

int count(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (node->left && node->right)
		return (0);
	if (!node->left && !node->right)
		return (0);
	return (1);
}

/**
 * test_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 * Return: 0 if the tree is not full else if the tree is full
*/

int test_tree_is_full(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (0);

	left = count(tree) + test_tree_is_full(tree->left);
	right = count(tree) + test_tree_is_full(tree->right);


	return ((left + right));
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 * Return: 0 if the tree is not full 1 if the tree is full
*/


int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (test_tree_is_full(tree) != 0)
		return (0);
	return (1);
}
