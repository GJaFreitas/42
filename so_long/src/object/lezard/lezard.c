#include "../../../headers/header.h"

// Returns a new instance of the menu object
t_object	*new_lezard()
{
	t_object	*bg;

	bg = constructor(sizeof(t_object));
	bg->type = BG;
	bg->pos.w = 200;
	bg->pos.h = 100;
	bg->pos.x = WIDTH >> 2;
	bg->pos.y = WIDTH >> 2;
	bg->sprite = canva()->load_img("textures/lezard.xpm");
	return (object(bg));
}
