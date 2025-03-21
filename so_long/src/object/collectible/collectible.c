/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 17:22:11 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/header.h"

void	__scale_img(t_sprite *img, t_pos_vector vec);

static void	__col_render(void)
{
	t_collectible	*col;

	col = (t_collectible *)fthis()->object;
	if (col->is_render)
		__scale_img(col->get_sprite(), col->pos);
}

static void	__update_col(void)
{
	t_collectible	*col;

	col = (t_collectible *)fthis()->object;
	if (col->is_render \
		&& collides(game()->player->pos, col->pos))
	{
		game()->player->collectibles++;
		col->is_render = 0;
	}
}

t_object	*new_collectible(float x, float y)
{
	t_collectible	*collectible;

	collectible = constructor(sizeof(t_collectible));
	collectible->is_render = 1;
	collectible->type = COLLECTIBLE;
	collectible->render = __col_render;
	collectible->sprite = canva()->load_img("textures/steel.xpm");
	collectible->pos.x = x * canva()->scale_factor;
	collectible->pos.y = y * canva()->scale_factor;
	collectible->pos.w = canva()->scale_factor_e;
	collectible->pos.h = canva()->scale_factor_e;
	collectible->update = __update_col;
	return (object((t_object *)collectible));
}
