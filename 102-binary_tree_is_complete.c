#include "binary_trees.h"

/**
 * is_leef - check if leaf
 * @tree: the tree
 * Return: 0 or 1
*/

int is_leef(const binary_tree_t *tree)
{
	if (!tree->left && !tree->right)
		return (1);
	return (0);
}

/**
 * binary_tree_depth - Measures the depth of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: Height of the tree, or 0 if tree is NULL
*/

size_t binary_tree_depth(const binary_tree_t *tree)
{

	int depth;

	if (!tree)
		return (0);

	if (!tree->parent)
		return (0);

	depth = 1 + binary_tree_depth(tree->parent);
	return (depth);
}

/**
 * is_complete - check if tree is complete
 * @tree: the tree
 * Return: 0 or 1
*/

int is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (is_leef(tree) == 1)
		return (binary_tree_depth(tree));

	int left, right;

	left = is_complete(tree->left);
	right = is_complete(tree->right);

	if (left && right)
	{
		if (left == right)
{			printf("%d\n", left);
			return (left);
			}
		return (0);

	}
	if (!right && left)
	{
		return (left);
	}
	if (!left && right)
	{
		return (right);
	}
	return (0);
}

/**
 * binary_tree_is_complete - check if tree is complete
 * @tree: the tree
 * Return: 0 or 1
*/

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->parent && !tree->left && tree->right)
		return (1);
	if (is_complete(tree))
		return (1);
	return (0);

}

