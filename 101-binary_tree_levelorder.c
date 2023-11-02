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
 * print_level - prints the level
 * @root: root
 * @level_no: level_no
 * @func: function
*/
void print_level(binary_tree_t *root, int level_no, void (*func)(int))
{
	if (!root)
		return;
	if (level_no == 0)
		func(root->n);

	else
	{
		print_level(root->left, level_no - 1, func);
		print_level(root->right, level_no - 1, func);
	}
}

/**
 * binary_tree_levelorder - Goes through a binary tree using in-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
*/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int i = 0;
	int height = binary_tree_height(tree) + 1;

	if (!tree->left && !tree->right)
	{
		func(tree->n);
		return;
	}
	for (; i < height; i++)
		print_level((binary_tree_t *)tree, i, func);
}
