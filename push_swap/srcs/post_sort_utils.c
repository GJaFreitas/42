/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:27:34 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/10 16:27:34 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Assumes there is a previous operation!
void	remove_op(t_list *delete)
{
	delete->prev->next = delete->next;
	if (delete->next)
		delete->next->prev = delete->prev;
	ft_lstdelone(delete, free);
}

// Return the opposite operation to the current one 
t_op	oposite_op(t_op op)
{
	if (op == o_pa)
		return (o_pb);
	if (op == o_pb)
		return (o_pa);
	if (op == o_ra)
		return (o_rra);
	if (op == o_rb)
		return (o_rrb);
	if (op == o_rra)
		return (o_ra);
	if (op == o_rrb)
		return (o_rb);
	if (op == o_sa)
		return (o_sa);
	if (op == o_sb)
		return (o_sb);
	if (op == o_rr)
		return (o_rrr);
	return (0);
}

t_op	_mergable(t_op first, t_op second)
{
	if ((first == o_ra && second == o_rb) || (first == o_rb && second == o_ra))
		return (o_rr);
	else if ((first == o_rra && second == o_rrb)
		|| (first == o_rrb && second == o_rra))
		return (o_rrr);
	else if ((first == o_sa && second == o_sb)
		|| (first == o_sb && second == o_sa))
		return (o_ss);
	else
		return (0);
}

t_op	child_op(t_op first, t_op second)
{
	if ((first == o_ra && second == o_rb) || (first == o_rb && second == o_ra))
		return (o_rr);
	else if ((first == o_rra && second == o_rrb)
		|| (first == o_rrb && second == o_rra))
		return (o_rrr);
	else if ((first == o_sa && second == o_sb)
		|| (first == o_sb && second == o_sa))
		return (o_ss);
	else
		return (515);
}
