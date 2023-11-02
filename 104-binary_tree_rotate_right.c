#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Rotates a binary tree to the right
 * @tree: Pointer to the root node of the tree to rotate
 * Return: Pointer to the new root node of the rotated tree
*/

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *left;
	binary_tree_t *par;


	if (!tree)
		return (NULL);

	if (!tree->left)
		return (tree);
	left = tree->left;
	par = tree->parent;

	tree->parent = left;
	tree->left = left->right;

	left->right = tree;
	left->parent = par;

	return (left);
}
