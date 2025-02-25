#include "../includes/push_swap.h"

// Sort 3 numbers in 2 instructions or less
void	ft_sort_three(t_ps *data)
{
	t_stack	*stack;

	stack = data->a;
	if (stack_min(stack) == stack_peek(stack, 1))
	{
		rra(data);
		if (!stack_issorted(stack))
			sa(data);
	}
	else if (stack_max(stack) == stack_peek(stack, 1))
	{
		ra(data);
		if (!stack_issorted(stack))
			sa(data);
	}
	else
	{
		if (stack_min(stack) == stack->a[1])
			sa(data);
		else
			ra(data);
	}
}

void	sort_one(t_ps *data, t_chunk *to_sort)
{
	if (to_sort->pos != TOP_A)
		move_from_to(data, to_sort->pos, TOP_A);
	to_sort->size -= 1;
}

void	sort_two(t_ps *data, t_chunk *to_sort)
{
	if (to_sort->pos != TOP_A)
	{
		move_from_to(data, to_sort->pos, TOP_A);
		move_from_to(data, to_sort->pos, TOP_A);
	}
	if (stack_peek(data->a, 1) < stack_peek(data->a, 2))
     		sa(data);
	to_sort->size -= 2;
}

