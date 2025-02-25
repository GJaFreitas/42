#include "../includes/push_swap.h"

/*

	These functions server 1 purpose, putting the biggest number in the right place.
	if the three numbers we have are 3 2 1 all that matters is that the 3 goes to his
	rightfull spot and then we call sort_two() and that handles the rest.

*/

static void	sort_three_top_a(t_ps *data, t_chunk *to_sort, t_stack *stk, int max)
{
	if (stack_peek(stk, 1) == max)
	{
		sa(data);
		ra(data);
		sa(data);
		rra(data);
	}
	else if (stack_peek(stk, 2) == max)
	{
		ra(data);
		sa(data);
		rra(data);
	}
	to_sort->pos = TOP_A;
	to_sort->size -= 1;
	sort_two(data, to_sort);
}

static void	sort_three_top_b(t_ps *data, t_chunk *to_sort, t_stack *stk, int max)
{
	pa(data);
	if (stack_peek(stk, 2) == max)
	{
		pa(data);
		sa(data);
	}
	else if (stack_peek(stk, 1) == max)
	{
		sb(data);
		pa(data);
		sa(data);
	}
	else
		pa(data);
	pa(data);
	to_sort->pos = TOP_A;
	to_sort->size -= 1;
	sort_two(data, to_sort);
}

// Why is this one different? Oh what a question, im sure there's an answer
static void	sort_three_bottom_a(t_ps *data, t_chunk *to_sort, t_stack *stk, int max)
{
	max = chunk_min(data, to_sort);
	ra(data);
	ra(data);
	if (stack_peek(stk, 1) == max)
	{
		sa(data);
		ra(data);
	}
	else if (stack_peek(stk, 2) == max)
		ra(data);
	else
	{
		pb(data);
		ra(data);
		sa(data);
		pa(data);
	}
	to_sort->pos = TOP_A;
	to_sort->size -= 1;
	sort_two(data, to_sort);
}

static void	sort_three_bottom_b(t_ps *data, t_chunk *to_sort, t_stack *stk, int max)
{
	rb(data);
	rb(data);
	if (stack_peek(stk, 2) == max)
	{
		pa(data);
		rb(data);
	}
	else if (stack_peek(stk, 1) == max)
	{
		sb(data);
		pa(data);
		rb(data);
	}
	else
	{
		rb(data);
		pa(data);
	}
	to_sort->pos = TOP_B;
	to_sort->size -= 1;
	sort_two(data, to_sort);
}

void	sort_three(t_ps *data, t_chunk *to_sort)
{
	t_stack	*stk;
	int		max;

	stk = chunk_locate(data, to_sort->pos);
	max = chunk_max(data, to_sort);
	if (to_sort->pos == TOP_A)
		sort_three_top_a(data, to_sort, stk, max);
	else if (to_sort->pos == BOTTOM_A)
		sort_three_bottom_a(data, to_sort, stk, max);
	else if (to_sort->pos == TOP_B)
		sort_three_top_b(data, to_sort, stk, max);
	else if (to_sort->pos == BOTTOM_B)
		sort_three_bottom_b(data, to_sort, stk, max);
}
