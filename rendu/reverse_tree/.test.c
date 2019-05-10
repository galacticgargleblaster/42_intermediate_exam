#include <stdio.h>
#include "reverse_tree.c"
#include <stdlib.h>

int g_i = 0;

struct s_node *new_node(int value)
{
	struct s_node *new = malloc(sizeof(struct s_node));
	new->value = value;
	new->left =NULL;
	new->right=NULL;
	return new;
}

int width_tree(struct s_node *root)
{
	int max = 0;
	int min = 0;
}

#include <assert.h>

int main()
{
	struct s_node *root = new_node(10);
	root->left = new_node(5);
	root->left->left = new_node(6);
	root->left->right = new_node(9);
	root->left->left->left = new_node(7);
	root->left->left->right = new_node(13);


	struct s_node *r2 = new_node(5);
	r2->left = new_node(6);
	r2->right = new_node(4);
	r2->right->left = new_node(9);
	r2->right->right = new_node(3);
	r2->right->left->left = new_node(3);
	r2->right->left->right = new_node(2);
	r2->right->right->right = new_node(2);


	struct s_node *r3 = new_node(30);
	r3->left = new_node(15);
	r3->left->left = new_node(61);
	r3->right = new_node(41);
	r3->right = new_node(80);

	return 0;
}

