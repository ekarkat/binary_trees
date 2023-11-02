#include "binary_trees.h"

/**
 * 
*/


binary_tree_t **table(const binary_tree_t *tree, int size)
{

}

void print_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (!tree)
		return;
	
	while (level)
	{
		
	}
}

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree)
		return;

	func(tree->n);
	binary_tree_levelorder(tree->left, func);
	binary_tree_levelorder(tree->right, func);
}
