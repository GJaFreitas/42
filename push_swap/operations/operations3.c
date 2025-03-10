/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:27:06 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/10 16:27:06 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_ps *data)
{
	if (data->a->size < 2)
		return ;
	stack_rotate(data->a);
	save_move(data, o_ra);
}

void	rb(t_ps *data)
{
	if (data->b->size < 2)
		return ;
	stack_rotate(data->b);
	save_move(data, o_rb);
}

void	rr(t_ps *data)
{
	if (data->b->size < 2 || data->a->size < 2)
		return ;
	ra(data);
	rb(data);
	save_move(data, o_rr);
}
