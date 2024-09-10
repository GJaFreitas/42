#include "../../../headers/header.h"

t_object	*new_collectible(float x, float y)
{
	t_collectible	*collectible;

	collectible = constructor(sizeof(t_collectible));
	collectible->type = COLLECTIBLE;
	collectible->sprite = canva()->load_img("textures/steel.xpm");
	collectible->pos.x = x * canva()->scale_factor;
	collectible->pos.y = y * canva()->scale_factor;
	collectible->pos.w = canva()->scale_factor_e;
	collectible->pos.h = canva()->scale_factor_e;
	return (object((t_object*)collectible));
}
