#include "../../../headers/header.h"

/*
static void	__player_mouse()
{
}
*/

static void	__player_keys(byte *keys)
{
	if (keys[(t_keys)ARROWUP_KEY])
		fthis()->object->pos.y -= 5;
	if (keys[(t_keys)ARROWLEFT_KEY])
		fthis()->object->pos.x -= 5;
	if (keys[(t_keys)ARROWDOWN_KEY])
		fthis()->object->pos.y += 5;
	if (keys[(t_keys)ARROWRIGHT_KEY])
		fthis()->object->pos.x += 5;
}

t_object	*new_player2()
{
	t_player	*player;

	player = constructor(sizeof(t_player));
	player->type = PLAYER;
	player->sprite = canva()->load_img("textures/player.xpm");
	player->func_keys = __player_keys;
	player->pos.x = WIDTH >> 1;
	player->pos.y = 0;
	player->pos.w = player->sprite->width >> 1;
	player->pos.h = player->sprite->height >> 3;
	return (object((t_object*)player));
}
