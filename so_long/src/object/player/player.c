#include "../../../headers/header.h"

t_object	*new_player()
{
	t_player	*player;

	player = constructor(sizeof(t_player));
	player->sprite = canva()->load_img("textures/player.xpm");
	player->pos.x = WIDTH >> 1;
	player->pos.x = HEIGHT >> 1;
	player->pos.w = player->sprite->width >> 3;
	player->pos.h = player->sprite->height >> 3;
	return ((t_object *)player);
}
