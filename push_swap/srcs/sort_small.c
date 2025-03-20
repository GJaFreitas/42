/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:27:44 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/20 19:30:10 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Sort 3 numbers in 2 instructions or less
// change this
void	ft_sort_three(t_ps *data)
{
	int	first;
	int	second;
	int	third;

	first = stack_peek(data->a, 1);
	second = stack_peek(data->a, 2);
	third = stack_peek(data->a, 3);
	if (first > second && third > second && third > first)
		sa(data);
	else if (first > second && third > second && first > third)
		ra(data);
	else if (second > first && second > third && first > third)
		rra(data);
	else if (second > first && second > third && third > first)
	{
		sa(data);
		ra(data);
	}
	else if (first > second && second > third && first > third)
	{
		sa(data);
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

void	sort_five(t_ps *data)
{
	while (data->a->size > 3)
	{
		if (stack_peek(data->a, 1) == 1 || stack_peek(data->a, 1) == 2)
			pb(data);
		else
			ra(data);
	}
	if (stack_peek(data->b, 1) > stack_peek(data->b, 2))
		sb(data);
	ft_sort_three(data);
	pa(data);
	pa(data);
}

void	ft_sort_small(t_ps *data)
{
	if (data->a->size == 5)
		sort_five(data);
	if (data->a->size == 3)
		ft_sort_three(data);
	else
		chunk_sort(data);
}
