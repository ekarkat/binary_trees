#include "binary_trees.h"

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
