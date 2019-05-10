#include <stdio.h>
#include "height_tree.c"
#include <stdlib.h>
#include <assert.h>

struct s_node *new_node(int n_children)
{
	struct s_node *root = malloc(sizeof(struct s_node));
	root->value = 0;
	root->nodes = malloc(sizeof(struct s_node *) * (n_children + 1));
	for (int i = 0; i < n_children; i++)
	{
		root->nodes[i] = malloc(sizeof(struct s_node));
		root->nodes[i]->value = i;
		root->nodes[i]->nodes = NULL;
	}
	root->nodes[n_children] = NULL;
	return root;
}


int main()
{
	struct s_node *root = NULL;
	assert(height_tree(root) == -1);

	root = malloc(sizeof(struct s_node));
	root->value = 0;
	root->nodes = NULL;
	assert(height_tree(root) == 0);

	root = new_node(5);
	assert(height_tree(root) == 1);

	root->nodes[0] = new_node(4);
	assert(height_tree(root) == 2);

	root->nodes[0]->nodes[3] = new_node(2);
	assert(height_tree(root) == 3);


	struct s_node *ex = new_node(2);
	ex->nodes[0] = new_node(2);
	ex->nodes[1] = new_node(1);
	ex->nodes[1]->nodes[0] = new_node(0);
	assert(height_tree(ex) == 3);
}




