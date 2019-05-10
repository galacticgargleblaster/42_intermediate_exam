#include <stdio.h>

#define IS_UPPER(c)((c) >= 'A' && (c) <= 'Z')
#define IS_ALPHA(c) (((c) >= 'a' && (c) <= 'z') || IS_UPPER(c))


char to_lower(char c)
{
	if (IS_UPPER(c))
		return c + 32;
	else
		return c;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("\n");
		return 0;
	}
	int count[200];
	char order[200];
    for (int i = 0; i < 200; i++)
	{
		count[i] = 0;
		order[i] = 0;
	}
	char *str = av[1];
	int set_size = 0;
	char c;
	int i;
	while(*str)
	{
		if (IS_ALPHA(*str))
		{
			c = to_lower(*str);
			i = 0;
			while (i < set_size)
			{
				if (order[i] == c)
					break;
				i++;
			}
			if (i == set_size)
			{
				order[set_size++] = c;
			}
			count[(int) c]++;
		}
		str++;
	}
	i = 0;
	int prev = 0;
	while (i < set_size)
	{
		c = order[i];
		if (prev)
			printf(", ");
		else
			prev = 1;
		printf("%d%c", count[(int) c], c);
		i++;
	}
	printf("\n");
	return 0;
}

