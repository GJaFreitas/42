/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 18:25:25 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/header.h"

#define HP_SIZE 400

void	__scale_img(t_sprite *img, t_pos_vector vec);

// 1 - Deco
// 0 - Bar
static t_sprite	*__hud_sprites(int which)
{
	t_hud	*hud;

	hud = (t_hud *)fthis()->object;
	if (which == 1)
		return (hud->hpbar);
	return (hud->hpsprite);
}

static void	__hud_destructor(void)
{
	t_hud	*hud;

	hud = (t_hud *)fthis()->object;
	mlx_destroy_image(engine()->mlx,
		hud->get_sprite(1)->img);
	mlx_destroy_image(engine()->mlx,
		hud->get_sprite(0)->img);
	free(hud->get_sprite(1));
	free(hud->get_sprite(0));
}

static void	__hud_render(void)
{
	t_hud	*hud;

	hud = (t_hud *)fthis()->object;
	hud->hpsize.w = hud->hpsize.w * (game()->player->hp / 100);
	__scale_img(
		hud->get_sprite(0), \
		hud->hpsize);
	__scale_img(
		hud->get_sprite(1), \
		hud->pos);
	hud->hpsize.w = HP_SIZE;
}

t_object	*new_hud(void)
{
	t_hud	*hud;

	hud = constructor(sizeof(t_hud));
	hud->render = __hud_render;
	hud->get_sprite = __hud_sprites;
	hud->destructor = __hud_destructor;
	hud->type = HUD;
	hud->pos.x = -85;
	hud->pos.y = -25;
	hud->pos.w = 650;
	hud->pos.h = 200;
	hud->hpsprite = canva()->load_img("textures/hp.xpm");
	hud->hpsize.x = 50;
	hud->hpsize.y = 50;
	hud->hpsize.w = HP_SIZE;
	hud->hpsize.h = 35;
	hud->hpbar = canva()->load_img("textures/health-bar.xpm");
	game()->add_obj(new_counter());
	return ((t_object *)hud);
}
