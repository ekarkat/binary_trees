#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int balance;

	binary_tree_t *tmp1;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_insert_left(root, 45);
    binary_tree_insert_right(root->left, 50);
    binary_tree_insert_left(root->left->left, 10);
    binary_tree_insert_left(root->left->left->left, 8);
    binary_tree_insert_left(root->left->left->right, 9);
	binary_tree_insert_right(root->left->left->right->left, 66);

    binary_tree_print(root);

	tmp1 = root->left->left;
	balance = binary_tree_balance(tmp1);
	printf("Balance of %d : %+d\n", tmp1->n, balance);

    return (0);
}
