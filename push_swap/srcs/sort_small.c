/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:27:44 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/20 15:52:25 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Sort 3 numbers in 2 instructions or less
// change this
void	ft_sort_three(t_ps *data)
{
	t_stack	*stack;

	stack = data->a;
	if (stack_min(stack) == stack_peek(stack, 1))
	{
		ra(data);
		if (!stack_issorted(stack))
			sa(data);
	}
	else if (stack_max(stack) == stack_peek(stack, 1))
	{
		rra(data);
		if (!stack_issorted(stack))
			sa(data);
	}
	else
	{
		if (stack_min(stack) == stack->a[1])
			sa(data);
		else
			rra(data);
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
	if (stack_peek(data->a, 1) > stack_peek(data->a, 2))
		sa(data);
	to_sort->size -= 2;
}
