#include "stack.h"

void	stack_add(t_stack *stack, int num)
{
	if (stack->size < 500)
		stack->a[stack->size++] = num;
}

void	stack_remove(t_stack *stack)
{
	if (stack->size > 0)
		stack->size--;
}
