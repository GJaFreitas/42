/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:59:18 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/19 17:26:58 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Shift up all elements of a stack by 1.
// The first element becomes the last one | ra and rb

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

void	ra(t_ps *data)
{
	if (rotate(data->stack_a) == -1)
		return ;
	save_move("ra", data);
}

void	rb(t_ps *data)
{
	if (rotate(data->stack_b) == -1)
		return ;
	save_move("rb", data);
}

void	rr(t_ps *data)
{
	if ((ft_lstsize(*data->stack_a) < 2) || (ft_lstsize(*data->stack_b) < 2))
		return ;
	rotate(data->stack_a);
	rotate(data->stack_b);
	save_move("rr", data);
}
