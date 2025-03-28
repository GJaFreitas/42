/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 15:40:30 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

// AABB (Axis-Aligned Bounding Box)
int	collides(t_pos_vector pos1, t_pos_vector pos2)
{
	if (pos1.x < pos2.x + pos2.w && pos1.x + pos1.w > pos2.x && \
		pos1.y < pos2.y + pos2.h && pos1.y + pos1.h > pos2.y)
		return (1);
	return (0);
}

// Returns 1 if position is outside boundary of the screen
int	out_of_bounds(t_pos_vector pos)
{
	return ((pos.x > WIDTH_W || pos.x < 0) \
	|| (pos.y > HEIGHT_W || pos.y < 0));
}

int	collision_check_y(t_pos_vector pos, int mov)
{
	return (!game()->walls[(int)pos.y + mov][(int)pos.x] \
	&& !game()->walls[(int)(pos.y + mov)][(int)(pos.x + pos.w)] \
	&& !game()->walls[(int)(pos.y + pos.h + mov)][(int)(pos.x + pos.w)] \
	&& !game()->walls[(int)(pos.y + pos.h + mov)][(int)(pos.x)]);
}

int	collision_check_x(t_pos_vector pos, int mov)
{
	return (!game()->walls[(int)pos.y][(int)pos.x + mov] \
	&& !game()->walls[(int)(pos.y)][(int)(pos.x + pos.w + mov)] \
	&& !game()->walls[(int)(pos.y + pos.h)][(int)(pos.x + pos.w + mov)] \
	&& !game()->walls[(int)(pos.y + pos.h)][(int)(pos.x + mov)]);
}
