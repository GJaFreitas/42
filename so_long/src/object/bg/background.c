#include "../../../headers/header.h"

t_object	*new_bg()
{
	t_object	*bg;

	bg = constructor(sizeof(t_object));
	bg->type = BG;
	bg->pos.w = WIDTH;
	bg->pos.h = HEIGHT;
	bg->sprite = canva()->load_img("textures/grass.xpm");
	return (bg);
}
