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

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
										const binary_tree_t *second)
{
	const binary_tree_t *first_par_tree;
	const binary_tree_t *sec_par_tree;
	
	first_par_tree = first;
	int n = 5;
	int arr[n];
	arr[0] = 15;

	if (!first || !second)
		return (NULL);
	
	while (first_par_tree)
	{
		sec_par_tree = second;
		while (sec_par_tree)
		{
				printf("%d \n" , arr[0]);
			if (first_par_tree == sec_par_tree)
				return((binary_tree_t *)sec_par_tree);
			sec_par_tree = sec_par_tree->parent;
		}
		first_par_tree = first_par_tree->parent;
	}


	return (NULL);
}




binary_tree_t **tree_leaf(binary_tree_t **tree_tab, int size)
{
	binary_tree_t **new;
	new = malloc(sizeof(binary_tree_t *) * (size * 2));
	int i = 0;
	int j = 0;

	while (i < (size * 2))
	{
		if (tree_tab[j]->left == NULL)
			new[i] = NULL;
		else
			new[i] = tree_tab[j]->left;
		if (tree_tab[j]->right == NULL)
			new[i + 1] = NULL;
		else
			new[i + 1] = tree_tab[j]->right;
		j = j + 1;
		i = i + 2;
	}

	return (new);
}


/* level start from 1; root = 1*/
binary_tree_t **tree_table(binary_tree_t *node, int level)
{
	binary_tree_t **table;

	table = &node;
	int i = 1;
	if (level >= 2)
	{
		while (i < level)
		{
			table = tree_leaf(table, i);
			i = i + 1;
		}
	}

	return (table);
}

int is_leef(const binary_tree_t *tree)
{
	if (!tree->left && !tree->right)
		return (1);
	return (0);
}

size_t binary_tree_depth(const binary_tree_t *tree)
{

	int depth;

	if (!tree)
		return (0);

	if (!tree->parent)
		return (0);

	depth = 1 + binary_tree_depth(tree->parent);
	return (depth);
}

int is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (is_leef(tree) == 1)
		return (binary_tree_depth(tree));
	
	int left, right;

	left = is_complete(tree->left);
	right = is_complete(tree->right);

	if (left && right)
	{
		if (left == right)
{			printf("%d\n", left);		
			return(left);
			}
		return (0);

	}
	if (!right && left)
	{
		return(left);
	}
	if (!left && right)
	{
		return (right);
	}
	return (0);
}

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->parent && !tree->left && tree->right)
		return (1);
	if (is_complete(tree))
		return (1);
	return (0);

}


/*------------------------------------------------*/



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
	binary_tree_insert_left(root->right->left, 22);
    binary_tree_print(root);


	printf("%d\n", binary_tree_is_complete(root->left->left));
    return (0);
}
