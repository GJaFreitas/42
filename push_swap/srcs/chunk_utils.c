/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:27:22 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/10 16:27:22 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Returns the position n in the chunk
int	chunk_get(t_ps *data, t_chunk *chunk, int n)
{
	t_stack	*s;
	int		i;

	s = chunk_locate(data, chunk->pos);
	if (chunk->pos == TOP_A || chunk->pos == TOP_B)
		i = s->size - 1;
	else if (chunk->pos == BOTTOM_A || chunk->pos == BOTTOM_B)
		i = 0;
	while (--n)
	{
		if (chunk->pos == TOP_A || chunk->pos == TOP_B)
			i--;
		else if (chunk->pos == BOTTOM_A || chunk->pos == BOTTOM_B)
			i++;
	}
	return (s->a[i]);
}

// Where am i
t_stack	*chunk_locate(t_ps *data, t_pos pos)
{
	if (pos == TOP_A || pos == BOTTOM_A)
		return (data->a);
	else
		return (data->b);
}

// How big am i
int	chunk_max(t_ps *data, t_chunk *chunk)
{
	t_stack	*s;
	int		size;
	int		max;
	int		i;

	s = chunk_locate(data, chunk->pos);
	size = chunk->size;
	max = 0;
	if (chunk->pos == TOP_A || chunk->pos == TOP_B)
		i = s->size - 1;
	else if (chunk->pos == BOTTOM_A || chunk->pos == BOTTOM_B)
		i = 0;
	while (size--)
	{
		if (s->a[i] > max)
			max = s->a[i];
		if (chunk->pos == TOP_A || chunk->pos == TOP_B)
			i--;
		else if (chunk->pos == BOTTOM_A || chunk->pos == BOTTOM_B)
			i++;
	}
	return (max);
}

// How small am i
int	chunk_min(t_ps *data, t_chunk *chunk)
{
	t_stack	*s;
	int		size;
	int		min;
	int		i;

	s = chunk_locate(data, chunk->pos);
	size = chunk->size;
	min = 777777;
	if (chunk->pos == TOP_A || chunk->pos == TOP_B)
		i = s->size - 1;
	else if (chunk->pos == BOTTOM_A || chunk->pos == BOTTOM_B)
		i = 0;
	while (size--)
	{
		if (s->a[i] < min)
			min = s->a[i];
		if (chunk->pos == TOP_A || chunk->pos == TOP_B)
			i--;
		else if (chunk->pos == BOTTOM_A || chunk->pos == BOTTOM_B)
			i++;
	}
	return (min);
}
