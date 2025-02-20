#include "../includes/push_swap.h"

// Sort 3 numbers in 2 instructions or less
void	ft_sort_three(t_stack *stack_a)
{
	if (stack_min(stack_a) == stack_a->a[0])
	{
		rra(stack_a);
		if (!stack_issorted(stack_a))
			sa(stack_a);
	}
	else if (stack_max(stack_a) == stack_a->a[0])
	{
		ra(stack_a);
		if (!stack_issorted(stack_a))
			sa(stack_a);
	}
	else
	{
		if (stack_min(stack_a) == stack_a->a[1])
			sa(stack_a);
		else
			rra(stack_a);
	}
}
