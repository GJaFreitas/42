#include "../../../headers/header.h"

t_object	*new_bg(void)
{
	t_object	*bg;

	bg = constructor(sizeof(t_object));
	bg->type = BG;
	bg->pos.w = WIDTH;
	bg->pos.h = HEIGHT;
	bg->sprite = canva()->load_img("textures/background(new).xpm");
	return (bg);
}
