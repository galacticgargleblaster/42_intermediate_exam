#include <stdio.h>
#include "is_anagram.c"

int main(int ac, char **av)
{
	if (ac != 3)
	{
		printf("\n");
		return 0;
	}
	if (is_anagram(av[1], av[2]))
		printf("is anagram\n");
	else
		printf("not anagram\n");
	return 0;
}

