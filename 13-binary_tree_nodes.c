#include "binary_trees.h"


/**
 * count - return 1 if the node has at least 1 child nide else 0
 * @tree: the root
 * Return: return 1 if the node has at least 1 child nide else 0
*/

size_t count(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	return (1);
}

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: Height of the tree, or 0 if tree is NULL
*/

size_t binary_tree_nodes(const binary_tree_t *tree)
{

	int left = 0;
	int right = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (0);

	/**
		* the function count should count the parent node only once; so it should
		* be added eaither in left or right
	*/
	left = count(tree) + binary_tree_nodes(tree->left);
	right = right + binary_tree_nodes(tree->right);


	return ((left + right));
}
