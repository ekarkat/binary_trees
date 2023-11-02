#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotates a binary tree to the left
 * @tree: Pointer to the root node of the tree to rotate
 * Return: Pointer to the new root node of the rotated tree
*/

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *right;
	binary_tree_t *par;


	if (!tree)
		return (NULL);

	if (!tree->right)
		return (tree);
	right = tree->right;
	par = tree->parent;

	tree->parent = right;
	tree->right = right->left;

	right->left = tree;
	right->parent = par;

	return (right);
}
