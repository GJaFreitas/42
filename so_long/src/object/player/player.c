#include "../../../headers/header.h"

/*
static void	__player_mouse()
{
}
*/

static void	__player_keys(byte *keys)
{
	if (keys[(t_keys)W_KEY])
		fthis()->object->pos.y -= 5;
	if (keys[(t_keys)A_KEY])
		fthis()->object->pos.x -= 5;
	if (keys[(t_keys)S_KEY])
		fthis()->object->pos.y += 5;
	if (keys[(t_keys)D_KEY])
		fthis()->object->pos.x += 5;
}

t_object	*new_player()
{
	t_player	*player;

	player = constructor(sizeof(t_player));
	player->type = PLAYER;
	player->sprite = canva()->load_img("textures/player.xpm");
	player->func_keys = __player_keys;
	player->pos.x = WIDTH >> 1;
	player->pos.x = HEIGHT >> 1;
	player->pos.w = player->sprite->width >> 3;
	player->pos.h = player->sprite->height >> 3;
	return ((t_object *)player);
}
