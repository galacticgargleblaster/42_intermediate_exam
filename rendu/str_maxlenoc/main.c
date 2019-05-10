#include <unistd.h>
#include <stdlib.h>

size_t ft_strlen(char *str)
{
	size_t i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return i;
}

char *ft_strndup(char *str, size_t n)
{
	char *new = malloc(sizeof(char) * (n + 1));
	size_t i = 0;
	while (*str && i < n)
	{
		new[i++] = *str++;
	}
	new[i] = 0;
	return new;
}

void ft_puts(char *str)
{
	write(1, str, ft_strlen(str));
}

int ft_strstr(char *str, char *substr)
{
	size_t offset = 0;
	size_t i = 0;
	while (ft_strlen(substr) + offset <= ft_strlen(str))
	{
		i = 0;
		while (substr[i])
		{
			if (substr[i] == str[i + offset])
				i++;
			else
				break;
		}
		if (i == ft_strlen(substr))
			return 1;
		offset++;
	}
	return 0;
}


int main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_puts("\n");
		return 0;
	}
	char *str = av[1];
	size_t len = ft_strlen(str);
	size_t offset = 0;
	char *substr;
	char *longest = 0;
	while (len > 0)
	{
		offset = 0;
		while (len + offset <= ft_strlen(str))
		{
			substr = ft_strndup(str + offset, len);
			int a = 2;
			while (a < ac)
			{
				if (!ft_strstr(av[a], substr))
					break;
			    a++;
			}
			if (a == ac)
			{
				if (longest && (ft_strlen(substr) <= ft_strlen(longest)))
					;
				else
					longest = substr;
			}
			else
				free(substr);
			offset++;
		}
		len--;
	}
	if (longest)
		ft_puts(longest);
	else
		ft_puts("");
	ft_puts("\n");
	return 0;
}
