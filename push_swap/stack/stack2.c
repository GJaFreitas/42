#include "stack.h"
#include <limits.h>

int	stack_min(t_stack *stack)
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

int	stack_max(t_stack *stack)
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

int	stack_issorted(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->a[i] >= stack->a[i + 1])
	{
		while (i < stack->size && stack->a[i] >= stack->a[i + 1])
			i++;
		return (stack->a[i] >= stack->a[i + 1]);
	}
	else
	{
		while (i < stack->size && stack->a[i] <= stack->a[i + 1])
			i++;
		return (stack->a[i] <= stack->a[i + 1]);
	}
}
