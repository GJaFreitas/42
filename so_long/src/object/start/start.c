/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 17:54:41 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/header.h"

void	__add_obj(t_object *o);

// TODO: Needs sprite
t_object	*new_start(float x, float y)
{
	t_start	*start;

	start = constructor(sizeof(t_start));
	start->type = START;
	start->sprite = canva()->load_img("textures/start.xpm");
	start->pos.w = canva()->scale_factor;
	start->pos.h = canva()->scale_factor;
	start->pos.x = x * canva()->scale_factor;
	start->pos.y = y * canva()->scale_factor;
	__add_obj(new_player(\
			start->pos.x + start->pos.w / 4, \
			start->pos.y + start->pos.h / 4));
	game()->add_obj(new_hud());
	return ((t_object *)start);
}
