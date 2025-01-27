#include "push_swap.h"
#include "stack/stack.h"

void	ft_algo(t_stack *a, t_stack *b)
{
	while (!stack_empty(a))
	{
		while (stack_peek(a, 0) != stack_max(a))
			ra(a);
		pa(a, b);
	}
	while (!stack_empty(b))
	{
		pb(a, b);
	}
}
