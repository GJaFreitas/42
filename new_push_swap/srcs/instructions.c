/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:59:29 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/19 17:27:38 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Swaps first two elements of a stack | sa and sb

int	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		ft_error("Error occured while swapping!");
	tmp_val = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
}

void	sa(t_ps *data)
{
	if (swap(data->stack_a) == -1)
		return ;
	save_move("sa", data);
}

void	sb(t_ps *data)
{
	if (swap(data->stack_b) == -1)
		return ;
	save_move("sb", data);
}

void	ss(t_ps *data)
{
	if ((ft_lstsize(*data->stack_a) < 2) || (ft_lstsize(*data->stack_b) < 2))
		return ;
	swap(data->stack_a);
	swap(data->stack_b);
	save_move("ss", data);
}
