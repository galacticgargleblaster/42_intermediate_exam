struct s_node {
	int           value;
	struct s_node **nodes;
};

#define MAX(a,b) ((a) > (b) ? a : b)

int height_tree(struct s_node *root)
{
	int max;
	int current;
	int i = 0;

	if (root)
	{
		current = 0;
		if (root->nodes)
		{
			current = 1;
			max = 0;
			while (root->nodes[i])
			{
				max = MAX(max, height_tree(root->nodes[i]));
				i++;
			}
			current += max;
		}
	}
	else
		return -1;
	return current;
}
