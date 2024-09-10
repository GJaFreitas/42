#include "../../../headers/header.h"

t_object	*new_enemy(float x, float y)
{
	t_enemy	*enemy;

	enemy = constructor(sizeof(t_enemy));
	enemy->type = ENEMY;
	enemy->sprite = canva()->load_img("textures/slime.xpm");
	enemy->pos.w = canva()->scale_factor_e;
	enemy->pos.h = canva()->scale_factor_e;
	enemy->pos.x = x * canva()->scale_factor;
	enemy->pos.y = y * canva()->scale_factor;
	return (object((t_object*)enemy));
}
