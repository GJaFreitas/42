#include "../../../headers/header.h"

// TODO: Needs sprite
t_object	*new_start(float x, float y)
{
	t_start	*start;

	start = constructor(sizeof(t_start));
	start->type = START;
	start->sprite = canva()->load_img("textures/slime.xpm");
	start->pos.w = canva()->scale_factor;
	start->pos.h = canva()->scale_factor;
	start->pos.x = x * canva()->scale_factor;
	start->pos.y = y * canva()->scale_factor;
	game()->add_obj(new_player(\
			    start->pos.x + start->pos.w / 4,\
			    start->pos.y + start->pos.h / 4));
	return ((t_object*)start);
}
