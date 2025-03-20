/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:27:42 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/20 17:08:46 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	chunk_to_the_top(t_ps *data, t_chunk *to_sort)
{
	if (to_sort->pos == BOTTOM_B && data->b->size == to_sort->size)
		to_sort->pos = TOP_B;
	if (to_sort->pos == BOTTOM_A && data->a->size == to_sort->size)
		to_sort->pos = TOP_A;
}

// Recursiveness is magic
static void	recursive_magic(t_ps *data, t_chunk *to_sort)
{
	t_split_dest	dests;

	chunk_to_the_top(data, to_sort);
	if (to_sort->size <= 3)
	{
		if (to_sort->size == 3)
			sort_three(data, to_sort);
		else if (to_sort->size == 2)
			sort_two(data, to_sort);
		else if (to_sort->size == 1)
			sort_one(data, to_sort);
		return ;
	}
	chunk_split(data, to_sort, &dests);
	recursive_magic(data, &dests.max);
	recursive_magic(data, &dests.mid);
	recursive_magic(data, &dests.min);
}

void	chunk_sort(t_ps *data)
{
	t_chunk	big_chunkaroo;

	big_chunkaroo.pos = TOP_A;
	big_chunkaroo.size = data->a->size;
	recursive_magic(data, &big_chunkaroo);
}
