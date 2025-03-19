/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:27:11 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/19 11:45:00 by gjacome-         ###   ########.fr       */
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
t_stack *stk, int min)
{
	if (stack_peek(stk, 1) == min)
	{
		sa(data);
		rra(data);
		sa(data);
		ra(data);
	}
	else if (stack_peek(stk, 2) == min)
	{
		rra(data);
		sa(data);
		ra(data);
	}
	to_sort->pos = TOP_A;
	to_sort->size -= 1;
	sort_two(data, to_sort);
}

static void	sort_three_top_b(t_ps *data, t_chunk *to_sort,
t_stack *stk, int min)
{
	pa(data);
	if (stack_peek(stk, 1) == min)
	{
		pa(data);
		sa(data);
	}
	else if (stack_peek(stk, 2) == min)
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
				t_stack *stk, int min)
{
	ra(data);
	ra(data);
	if (stack_peek(stk, 1) == min)
	{
		sa(data);
		ra(data);
	}
	else if (stack_peek(stk, 2) == min)
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

static void	sort_three_bottom_b(t_ps *data, t_chunk *to_sort,
				t_stack *stk, int min)
{
	rb(data);
	rb(data);
	if (stack_peek(stk, 1) == min)
	{
		pa(data);
		rb(data);
	}
	else if (stack_peek(stk, 2) == min)
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
	int		min;

	stk = chunk_locate(data, to_sort->pos);
	min = chunk_min(data, to_sort);
	if (to_sort->pos == TOP_A)
		sort_three_top_a(data, to_sort, stk, min);
	else if (to_sort->pos == BOTTOM_A)
		sort_three_bottom_a(data, to_sort, stk, min);
	else if (to_sort->pos == TOP_B)
		sort_three_top_b(data, to_sort, stk, min);
	else if (to_sort->pos == BOTTOM_B)
		sort_three_bottom_b(data, to_sort, stk, min);
}
