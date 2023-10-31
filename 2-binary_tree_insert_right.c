#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left child of another node
 * @parent: Pointer to the parent node
 * @value: Value to put in the new node
 * Return: Pointer to the new node
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);
	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->left = NULL;
	new->parent = parent;
	new->n = value;
	new->right = parent->right;
	if (parent->right == NULL)
	{
		parent->right = new;
		return (new);
	}
	parent->right->parent = new;
	parent->right = new;
	return (new);
}
