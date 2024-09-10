#include "../../../headers/header.h"

// TODO: Needs sprite
t_object	*new_exit(float x, float y)
{
	t_exit	*exit;

	exit = constructor(sizeof(t_exit));
	exit->type = EXIT;
	exit->sprite = canva()->load_img("textures/slime.xpm");
	exit->pos.w = canva()->scale_factor;
	exit->pos.h = canva()->scale_factor;
	exit->pos.x = x * canva()->scale_factor;
	exit->pos.y = y * canva()->scale_factor;
	return (object((t_object*)exit));
}
