#include "../../../headers/header.h"

/*
static void	__player_mouse()
{
}
*/

static void	__player_keys(byte *keys)
{
	if (keys[XK_w])
		fthis()->object->pos.y -= 5;
	if (keys[XK_a])
		fthis()->object->pos.x -= 5;
	if (keys[XK_s])
		fthis()->object->pos.y += 5;
	if (keys[XK_d])
		fthis()->object->pos.x += 5;
}

static void	__player_keys2(byte *keys)
{
	if (keys[XK_Up])
		fthis()->object->pos.y -= 5;
	if (keys[XK_Left])
		fthis()->object->pos.x -= 5;
	if (keys[XK_Down])
		fthis()->object->pos.y += 5;
	if (keys[XK_Right])
		fthis()->object->pos.x += 5;
}

static void	__player_mouse()
{
}

t_object	*new_player(t_type playernum)
{
	t_player	*player;

	player = constructor(sizeof(t_player));
	player->type = playernum;
	player->sprite = canva()->load_img("textures/player.xpm");
	if (playernum == PLAYER)
		player->func_keys = __player_keys;
	else
		player->func_keys = __player_keys2;
	player->func_mouse = __player_mouse;
	player->pos.x = WIDTH >> 1;
	player->pos.y = HEIGHT >> 1;
	player->pos.w = player->sprite->width >> 3;
	player->pos.h = player->sprite->height >> 3;
	return (object((t_object*)player));
}
