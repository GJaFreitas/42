#include "../../../headers/header.h"

#define HP_SIZE 400

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
	// The only free not protected agaisnt double free
	// Which isnt a problem since if this was called the
	// whole memory region will be freed and set to null anyway
	free(hud->get_sprite(1));
	free(hud->get_sprite(0));
}

static void	__hud_render(void)
{
	t_hud	*hud;

	hud = (t_hud *)fthis()->object;
	hud->hpsize.w = hud->hpsize.w * (game()->player->hp / 100);
	canva()->scale_img(
		hud->get_sprite(0), \
		hud->hpsize);
	/*
	canva()->scale_img(
		hud->get_sprite(1), \
		hud->pos);
	*/
	hud->hpsize.w = HP_SIZE;
}

t_object	*new_hud()
{
	t_hud	*hud;

	hud = constructor(sizeof(t_hud));
	hud->render = __hud_render;
	hud->get_sprite = __hud_sprites;
	hud->destructor = __hud_destructor;
	hud->type = HUD;
	hud->pos.x = 100;
	hud->pos.y = 100;
	hud->pos.w = 192*3;
	hud->pos.h = 200;
	hud->hpsprite = canva()->load_img("textures/hp.xpm");
	hud->hpsize.x = 50;
	hud->hpsize.y = 50;
	hud->hpsize.w = HP_SIZE;
	hud->hpsize.h = 35;
	hud->hpbar = canva()->load_img("textures/health-bar.xpm");
	return ((t_object*)hud);
}
