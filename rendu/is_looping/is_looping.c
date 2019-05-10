#define MAX_N 500500

int     is_looping(struct s_node *node)
{
	void *visited_nodes[MAX_N];
	for (int i = 0; i < MAX_N; i++)
		visited_nodes[i] = 0;
	int i = 0;
	while (node)
	{
		visited_nodes[i] = node;
		for (int j = 0; j < i; j++)
		{
			if (visited_nodes[j] == node)
				return 1;
		}
		i++;
		node=node->next;
	}
	return 0;
}
