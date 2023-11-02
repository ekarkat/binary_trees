#include <stdlib.h>
#include <stdio.h>

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;

static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int width, left, right, is_left, i;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + width, depth + 1, s);
	for (i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];
	if (depth && is_left)
	{
		for (i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < left + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, i, j;

	if (!tree)
		return;
	height = _height(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;
	for (i = 0; i < height + 1; i++)
	{
		s[i] = malloc(sizeof(**s) * 255);
		if (!s[i])
			return;
		memset(s[i], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (i = 0; i < height + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (s[i][j] != ' ')
				break;
			s[i][j] = '\0';
		}
		printf("%s\n", s[i]);
		free(s[i]);
	}
	free(s);
}


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

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	new->parent = parent;
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	return (new);
}







/*-----------------------100-----------------------*/

int count_parent(const binary_tree_t *node)
{
	binary_tree_t *tmp = node;
	int count = 1;

	if (!tmp)
		return (0);
	while (tmp)
	{
		if (tmp->parent)
		{
			count = count + 1;
			tmp = tmp->parent;
		}
		else
			break;
	}
	return (count);
}

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
				return((binary_tree_t *)sec_par_tree);
			sec_par_tree = sec_par_tree->parent;
		}
		first_par_tree = first_par_tree->parent;
	}
	return (NULL);
}








/*------------------------------------------------*/


void launch_test(binary_tree_t *n1, binary_tree_t *n2)
{
    binary_tree_t *ancestor;

    ancestor = binary_trees_ancestor(n1, n2);
    printf("Ancestor of [%d] & [%d]: ", n1->n, n2->n);
    if (!ancestor)
        printf("(nil)\n");
    else
        printf("%d\n", ancestor->n);
}


int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    root->left->right = binary_tree_node(root->left, 54);
    root->right->right = binary_tree_node(root->right, 128);
    root->left->left = binary_tree_node(root->left, 10);
    root->right->left = binary_tree_node(root->right, 45);
    root->right->right->left = binary_tree_node(root->right->right, 92);
    root->right->right->right = binary_tree_node(root->right->right, 65);
    binary_tree_print(root);

    launch_test(root->left, root->right);
    launch_test(root->left, root->right->right->left);
    launch_test(root->right->left, root->right->right->right);
    launch_test(root->right->right, root->right->right->right);
    return (0);
}