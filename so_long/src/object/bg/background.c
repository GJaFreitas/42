#include "../../../headers/header.h"

static void	__player_keys(byte *keys)
{
	/*
	if (keys[(t_keys)W_KEY])
		fthis()->object->pos.y -= 10;
	if (keys[(t_keys)A_KEY])
		fthis()->object->pos.x -= 10;
	if (keys[(t_keys)S_KEY])
		fthis()->object->pos.y += 10;
	if (keys[(t_keys)D_KEY])
		fthis()->object->pos.x += 10;
	*/
	(void)keys;
}

t_object	*new_bg()
{
	t_object	*bg;

	bg = constructor(sizeof(t_object));
	bg->type = BG;
	bg->pos.w = WIDTH;
	bg->pos.h = HEIGHT;
	bg->func_keys = __player_keys;
	bg->sprite = canva()->load_img("textures/grass.xpm");
	return (object(bg));
}
