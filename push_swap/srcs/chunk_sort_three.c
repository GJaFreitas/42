/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:27:11 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/20 17:05:18 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*

	These functions server 1 purpose,
	putting the biggest number in the right place.
	if the three numbers we have are 3 2 1
	all that matters is that the 3 goes to his
	rightfull spot and then we call
	sort_two() and that handles the rest.

*/

static void	sort_three_top_a(t_ps *data, t_chunk *to_sort,
t_stack *stk, int max)
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

static void	sort_three_top_b(t_ps *data, t_chunk *to_sort,
t_stack *stk, int max)
{
	pa(data);
	if (stack_peek(stk, 1) == max)
	{
		pa(data);
		sa(data);
	}
	else if (stack_peek(stk, 2) == max)
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

static void	sort_three_bottom_a(t_ps *data, t_chunk *to_sort,
				t_stack *stk, int max)
{
	rra(data);
	rra(data);
	if (stack_peek(stk, 1) == max)
	{
		sa(data);
		rra(data);
	}
	else if (stack_peek(stk, 2) == max)
		rra(data);
	else
	{
		pb(data);
		rra(data);
		sa(data);
		pa(data);
	}
	to_sort->pos = TOP_A;
	to_sort->size -= 1;
	sort_two(data, to_sort);
}

static void	sort_three_bottom_b(t_ps *data, t_chunk *to_sort,
				t_stack *stk, int max)
{
	rrb(data);
	rrb(data);
	if (stack_peek(stk, 1) == max)
	{
		pa(data);
		rrb(data);
	}
	else if (stack_peek(stk, 2) == max)
	{
		sb(data);
		pa(data);
		rrb(data);
	}
	else
	{
		rrb(data);
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
