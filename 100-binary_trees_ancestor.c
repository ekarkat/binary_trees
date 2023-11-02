#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: the first node
 * @second: the second
 * Return: Return the ancestor
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
										const binary_tree_t *second)
{
	const binary_tree_t *first_par_tree;
	const binary_tree_t *sec_par_tree;

	first_par_tree = first;

	if (!first || !second)
		return (NULL);

	while (first_par_tree)
	{
		sec_par_tree = second;
		while (sec_par_tree)
		{
			if (first_par_tree == sec_par_tree)
				return ((binary_tree_t *)sec_par_tree);
			sec_par_tree = sec_par_tree->parent;
		}
		first_par_tree = first_par_tree->parent;
	}
	return (NULL);
}
