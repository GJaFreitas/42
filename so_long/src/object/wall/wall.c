/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/25 18:31:16 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/header.h"

static void	__put_pixel(int x, int y)
{
	if (x >= WIDTH_W || y >= HEIGHT_W)
		return ;
	game()->walls[y][x] = 1;
}

static void	__populate_array(t_pos_vector vec)
{
	t_pos_vector	v;
	int				x;
	int				y;

	y = 0;
	v.y = 0;
	v.h = vec.y / vec.h;
	v.w = vec.x / vec.w;
	while (y < vec.h)
	{
		x = 0;
		v.x = 0;
		while (x < vec.w)
		{
			__put_pixel((x + vec.x), (y + vec.y));
			v.x += v.w;
			x++;
		}
		y++;
		v.y += v.h;
	}
}

// TODO: Needs sprite
t_object	*new_wall(float x, float y)
{
	t_wall	*wall;

	wall = constructor(sizeof(t_wall));
	wall->type = WALL;
	wall->sprite = canva()->load_img("textures/walls.xpm");
	wall->pos.w = canva()->scale_factor;
	wall->pos.h = canva()->scale_factor;
	wall->pos.x = x * canva()->scale_factor;
	wall->pos.y = y * canva()->scale_factor;
	__populate_array(wall->pos);
	return (object((t_object *)wall));
}
