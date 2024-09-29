#include "../../../headers/header.h"

void	__calc_vec(t_enemy *e, t_pos_vector *vec);
void	__check_wall(t_enemy *e, t_pos_vector *vec);

static void	__pathfind()
{
	t_enemy		*e;
	t_pos_vector	vec;

	vec = (t_pos_vector){0, 0, 0, 0};
	e = (t_enemy *)fthis()->object;
	__calc_vec(e, &vec);
	__check_wall(e, &vec);
	e->pos.x -= vec.x;
	e->pos.y -= vec.y;
}

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
	enemy->update = __pathfind;
	return (object((t_object*)enemy));
}
