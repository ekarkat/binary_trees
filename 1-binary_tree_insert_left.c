#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left child of another node
 * @parent: Pointer to the parent node
 * @value: Value to put in the new node
 * Return: Pointer to the new node
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);
	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->right = NULL;
	new->parent = parent;
	new->n = value;
	new->left = parent->left;
	if (parent->left == NULL)
	{
		parent->left = new;
		return (new);
	}
	parent->left->parent = new;
	parent->left = new;
	return (new);
}
