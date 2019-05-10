#include <stdlib.h>
#include <unistd.h>
#include "stack.h"

void sort(struct s_stack *stack, int cmp(char *w1, char *w2))
{
	struct s_node *tmp = stack->top;
	char *content;

	while (tmp && tmp->next)
	{
		if (cmp(tmp->content, tmp->next->content))
			tmp = tmp->next;
		else
		{
			content = tmp->content;
			tmp->content = tmp->next->content;
			tmp->next->content = content;
			tmp = stack->top;
		}
	}
}

int ft_strlen(char *a)
{
	int len = 0;
	while (*a)
	{
		len++;
		a++;
	}
	return len;
}

char to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c - 32;
	else
		return c;
}

int by_alpha(char *a, char *b)
{
	int weight_a = 0;
	int weight_b = 0;
	while (*a && *b)
	{
		weight_a = (int)to_lower(*a++);
		weight_b = (int)to_lower(*b++);
		if (weight_a != weight_b)
			return (weight_a < weight_b);
	}
	return (1);
}


void ft_puts(char *str)
{
	write(1, str, ft_strlen(str));
}


char *ft_strndup(char *str, size_t n)
{
	size_t i = 0;
	char *out = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (*str && i < n)
	{
		out[i] = str[i];
		i++;
	}
	out[i] = 0;
	return out;
}

char *get_next_word(char **str_ptr)
{
	char *str = *str_ptr;
	char *next_word;
	int len = 0;
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
		{
			if (len)
			{
				next_word = ft_strndup(str-len, len);
				str++;
				*str_ptr = str;
				return (next_word);
			}
		}
		else
			len++;
		str++;
	}
	if (len)
	{
		*str_ptr = str;
		return (ft_strndup(str-len, len));
	}
	return NULL;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_puts("\n");
		return 0;
	}
	struct s_stack *words_by_len[2000];
	for (int i = 0; i < 2000; i++)
		words_by_len[i] = NULL;
	char *next_word;
	while ((next_word = get_next_word(&av[1])))
	{
		int idx = ft_strlen(next_word);
		if (words_by_len[idx] == NULL)
			words_by_len[idx] = init();
		push(words_by_len[idx], next_word);
	}
	struct s_stack *wordlist;
	char *word;
	for (int i = 0; i < 2000; i++)
	{
		if ((wordlist = words_by_len[i]))
		{
			sort(wordlist, &by_alpha);
			while ((word = pop(wordlist)))
			{
				ft_puts(word);
				if (peek(wordlist))
					ft_puts(" ");
			}
			ft_puts("\n");
		}
	}
	return 0;
}

