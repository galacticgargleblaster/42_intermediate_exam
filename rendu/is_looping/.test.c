#include <stdio.h>

struct s_node {
        int value;
        struct s_node *next;
};

#include "is_looping.c"
#include <stdlib.h>

int g_i = 0;

struct s_node *new_node()
{
	struct s_node *new = malloc(sizeof(struct s_node));
	new->value = g_i;
	g_i++;
	new->next = NULL;
	return new;
}

#include <assert.h>

int main()
{
	struct s_node *root = new_node();
	root->next = new_node();
	root->next->next = new_node();
	assert(!(is_looping(root)));
	root->next->next->next = root;
	assert(is_looping(root));
	return 0;
}

