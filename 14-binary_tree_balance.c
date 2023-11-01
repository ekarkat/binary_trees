#include "binary_trees.h"


/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: Height of the tree, or 0 if tree is NULL
*/

size_t binary_tree_height(const binary_tree_t *tree)
{

	int max;
	int left = 0;
	int right = 0;

	if (!tree)
		return (0);


	left = 1 + binary_tree_height(tree->left);
	right = 1 + binary_tree_height(tree->right);

	if (!tree->left && !tree->right)
		return (0);

	if (left <= right)
		max = right;
	if (right < left)
		max = left;

	return (max);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: balance of the tree, or 0 if tree is NULL
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	int balance;
	int left = 0;
	int right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left = 1 + binary_tree_height(tree->left);
	else
		left = 0;
	if (tree->right)
		right = 1 + binary_tree_height(tree->right);
	else
		right = 0;
	if (!tree->left && !tree->right)
		return (0);

	balance = left - right;
	return (balance);
}
