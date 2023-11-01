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
/**
 * binary_tree_is_perfect -  checks if a binary tree is perfect
 * @tree: the tree root
 * Return: return 0 or 1
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if ((binary_tree_balance(tree) == 0) && (binary_tree_is_full(tree) == 1))
		return (1);
	return (0);
}