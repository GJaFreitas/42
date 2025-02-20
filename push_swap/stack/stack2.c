#include "stack.h"
#include <limits.h>

int	stack_min(const t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->size <= 0)
		return (INT_MAX);
	temp = INT_MAX;
	i = 0;
	while (i < stack->size)
	{
		if (stack->a[i] < temp)
			temp = stack->a[i];
		i++;
	}
	return (temp);
}

int	stack_max(const t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->size <= 0)
		return (INT_MIN);
	temp = INT_MIN;
	i = 0;
	while (i < stack->size)
	{
		if (stack->a[i] > temp)
			temp = stack->a[i];
		i++;
	}
	return (temp);
}

int	stack_issorted(const t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->a[i] >= stack->a[i + 1])
	{
		while (i < stack->size && stack->a[i] >= stack->a[i + 1])
			i++;
		return (++i == stack->size);
	}
	else
	{
		while (i < stack->size && stack->a[i] <= stack->a[i + 1])
			i++;
		return (++i == stack->size);
	}
}

int	stack_empty(const t_stack *stack)
{
	return (stack->size == 0);
}

int	stack_find(const t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (stack->a[i] != n)
		i++;
	return (i);
}
