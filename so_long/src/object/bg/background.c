#include "../../../headers/header.h"

// Returns a new instance of the menu object
t_object	*new_bg()
{
	t_object	*bg;

	bg = constructor(sizeof(t_object));
	bg->type = BG;
	bg->pos.w = WIDTH;
	bg->pos.h = HEIGHT;
	bg->sprite = canva()->load_img("textures/grass.xpm");
	return ((t_object *)bg);
}
