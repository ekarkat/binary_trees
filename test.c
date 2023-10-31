#include "binary_trees.h"

void print_b(const binary_tree_t *tree)
{
	if (!tree)
		return;
	print_b(tree->left);
	print_b(tree->right);
	printf("%d\n", tree->n);
}
