/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:58:54 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/19 17:21:05 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_min(t_list **stack, int val)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

void	sort_3(t_ps *data)
{
	t_list	*head;

	head = *(data->stack_a);
	if (is_sorted(data->stack_a))
		return ;
	if (head->index == get_min(data->stack_a, -1) \
		&& head->next->index != get_min(data->stack_a, get_min(data->stack_a, -1)))
	{
		ra(data);
		sa(data);
		rra(data);
	}
	else if (head->index == get_min(data->stack_a, get_min(data->stack_a, -1)))
		if (head->next->index == get_min(data->stack_a, -1))
			sa(data);
	else
		rra(data);
	else
		if (head->next->index == get_min(data->stack_a, -1))
			ra(data);
	else
	{
		sa(data);
		rra(data);
	}
}

void	sort_4(t_ps *data)
{
	int	distance;

	if (is_sorted(data->stack_a))
		return ;
	distance = get_distance(data->stack_a, get_min(data->stack_a, -1));
	if (distance == 1)
		ra(data);
	else if (distance == 2)
	{
		ra(data);
		ra(data);
	}
	else if (distance == 3)
		rra(data);
	if (is_sorted(data->stack_a))
		return ;
	pb(data);
	sort_3(data);
	pa(data);
}

void	sort_5(t_ps *data)
{
	int	distance;

	distance = get_distance(data->stack_a, get_min(data->stack_a, -1));
	if (distance == 1)
		ra(data);
	else if (distance == 2)
	{
		ra(data);
		ra(data);
	}
	else if (distance == 3)
	{
		rra(data);
		rra(data);
	}
	else if (distance == 4)
		rra(data);
	if (is_sorted(data->stack_a))
		return ;
	pb(data);
	sort_4(data);
	pa(data);
}
