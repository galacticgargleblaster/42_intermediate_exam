int     is_anagram(char *a, char *b)
{
	int arr[200];
	for (int i = 0; i < 200; i++)
		arr[i] = 0;
	while (*a)
		arr[(int)(*a++)]++;
	while (*b)
		arr[(int)(*b++)]--;
	for (int i = 0; i < 200; i++)
	{
		if (arr[i] != 0)
			return 0;
	}
	return 1;
}
