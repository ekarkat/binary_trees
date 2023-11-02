#include "binary_trees.h"

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp;

	tmp = *tree;
	if (!tmp)
		return(binary_tree_node(NULL, value));
	
	else if (value < (tmp)->n)
		bst_insert(&((tmp)->left), value);
	else if (value > (tmp)->n)
		bst_insert(&((tmp)->right), value);

	return(binary_tree_node((tmp), value));	

}