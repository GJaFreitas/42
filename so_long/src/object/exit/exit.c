/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 14:22:28 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/header.h"

static void	__update_exit(void)
{
	t_enemy		*e;

	e = (t_enemy *)fthis()->object;
	if (game()->player->collectibles == game()->collectibles_num \
	&& collides(game()->player->pos, e->pos))
		harbinger_of_chaos();
}

// TODO: Needs sprite
t_object	*new_exit(float x, float y)
{
	t_exit	*exit;

	exit = constructor(sizeof(t_exit));
	exit->update = __update_exit;
	exit->type = EXIT;
	exit->sprite = canva()->load_img("textures/exit.xpm");
	exit->pos.w = canva()->scale_factor;
	exit->pos.h = canva()->scale_factor;
	exit->pos.x = x * canva()->scale_factor;
	exit->pos.y = y * canva()->scale_factor;
	return (object((t_object *)exit));
}
