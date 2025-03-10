/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:27:02 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/10 16:27:02 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Reverse rotate stack "s"
void	rra(t_ps *data)
{
	if (data->a->size < 2)
		return ;
	stack_rev_rotate(data->a);
	save_move(data, o_rra);
}

void	rrb(t_ps *data)
{
	if (data->b->size < 2)
		return ;
	stack_rev_rotate(data->b);
	save_move(data, o_rrb);
}

void	rrr(t_ps *data)
{
	if (data->b->size < 2 || data->a->size < 2)
		return ;
	rra(data);
	rrb(data);
	save_move(data, o_rrr);
}
