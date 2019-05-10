#include <stdlib.h>

struct s_node {
	void          *content;
	struct s_node *next;
};

struct s_stack {
	struct s_node *top;
};

struct s_stack *init(void)
{
	struct s_stack *stack = malloc(sizeof(struct s_stack));
	stack->top = NULL;
	return stack;
}

void *pop(struct s_stack *stack)
{
	void *content;
	struct s_node *tmp;
	if (stack->top)
	{
		content = stack->top->content;
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
		return content;
	}
	return NULL;
}

void push(struct s_stack *stack, void *content)
{
	struct s_node *node = malloc(sizeof(struct s_node));
	node->content = content;
	if (stack->top)
		node->next = stack->top;
	else
		node->next = NULL;
	stack->top = node;
}

void *peek(struct s_stack *stack)
{
	if (stack->top)
		return stack->top->content;
	else
		return NULL;
}


int isEmpty(struct s_stack *stack)
{
	return (stack->top == NULL);
}
