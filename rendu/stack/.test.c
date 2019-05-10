#include "stack.c"
#include <assert.h>

int main()
{
	struct s_stack *stack = init();
	assert(isEmpty(stack));
	assert(peek(stack) == NULL);
	assert(pop(stack) == NULL);

	int foo = 4;
	push(stack, &foo);
	assert(peek(stack) == &foo);
	assert(isEmpty(stack) == 0);

	int bar = 2;
	push(stack, &bar);
	assert(peek(stack) == &bar);

	int *baz;
	baz = pop(stack);
	assert(baz == &bar);

	baz = pop(stack);
	assert(baz == &foo);

	baz = pop(stack);
	assert(baz == NULL);
	assert(isEmpty(stack));
}
	
	
