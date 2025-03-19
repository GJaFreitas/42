/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:59:14 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/19 17:26:21 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Shifts down all elements of a stack by 1.
// The last element becomes the first one | rra and rrb

int	reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

void	rra(t_ps *data)
{
	if (reverse_rotate(data->stack_a) == -1)
		return ;
	save_move("rra", data);
}

void	rrb(t_ps *data)
{
	if (reverse_rotate(data->stack_b) == -1)
		return ;
	save_move("rrb", data);
}

void	rrr(t_ps *data)
{
	if ((ft_lstsize(*data->stack_a) < 2) || (ft_lstsize(*data->stack_b) < 2))
		return ;
	reverse_rotate(data->stack_a);
	reverse_rotate(data->stack_b);
	save_move("rrr", data);
}
