#include "stack.h"

void	stack_add(t_stack *stack, int num)
{
	if (stack->size < 500)
		stack->a[stack->size++] = num;
}

int	stack_pop(t_stack *stack)
{
	int	pop;

	if (stack->size > 0)
	{
		stack->size--;
		pop = stack->a[stack->size];
		return (pop);
	}
	return (0);
}

int	stack_peek(const t_stack *stack, int n)
{
	int	i;

	i = stack->size - n - 1;
	return (stack->a[i]);
}

void	stack_rotate(t_stack *stack)
{
	int	i;
	int	temp;

	temp = stack_pop(stack);
	i = stack->size - 1;
	while (i >= 0)
	{
		stack->a[i + 1] = stack->a[i];
		i--;
	}
	stack->a[0] = temp;
	stack->size++;
}

void	stack_rev_rotate(t_stack *stack)
{
	int	i;
	int	temp;

	temp = stack->a[0];
	stack->size--;
	i = 0;
	while (i < stack->size)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack_add(stack, temp);
}
