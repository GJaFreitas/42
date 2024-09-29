#include "../../../headers/header.h"

#ifndef ENEMY_SPEED
# define ENEMY_SPEED 4
#endif

t_pos_vector	__calc_vec(t_enemy *e, t_pos_vector *vec);
void	__get_vec(t_enemy *e, t_pos_vector *vec);
int	__check_wall(t_enemy *e, t_pos_vector vec);
int	__collision_check_x(t_pos_vector pos, int mov);
int	__collision_check_y(t_pos_vector pos, int mov);
static void	__pathfind();

static void	__clear_wall()
{
	t_pos_vector		dummy;
	static t_pos_vector	vec;
	static int		flag;
	t_enemy			*e;

	e = (t_enemy *)fthis()->object;
	if (!__check_wall(e, __calc_vec(e, &dummy)))
	{
		printf("HALLO\n");
		return (e->update = __pathfind, (void)7);
	}
	if (!flag)
		__get_vec(e, &vec);
	flag = 1;
	e->pos.x -= vec.x;
	e->pos.y -= vec.y;
}

static void	__pathfind()
{
	t_enemy		*e;
	t_pos_vector	vec;

	vec = (t_pos_vector){0, 0, 0, 0};
	e = (t_enemy *)fthis()->object;
	if (__check_wall(e, __calc_vec(e, &vec)))
		return (e->update = __clear_wall, (void)7);
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
