struct s_node
{
        int value;
        struct s_node *left;
        struct s_node *right;
};

int     longest_sequence(struct s_node *node)
{
	int longest = 0;
	if (node)
	{
		longest++;
		if (node->left)
		{
			if (node->left->value != node->value + 1)
				longest = 0;
			longest += longest_sequence(node->left);
		}
		else if (node->right)
		{
			if (node->right->value != node->value + 1)
				longest = 0;
			longest += longest_sequence(node->right);
		}
	}
	return longest;
}

