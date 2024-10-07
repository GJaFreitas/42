#include "../../../headers/header.h"

#ifndef ENEMY_SPEED
# define ENEMY_SPEED 4
#endif

void	__calc_vec(t_enemy *e, t_pos_vector *vec);

static void	__new_vec(t_pos_vector *vec)
{
	if (vec->x > vec->y)
	{
		vec->y = ENEMY_SPEED * (vec->y / f_abs(vec->y));
		vec->x = 0;
	}
	else
	{
		vec->x = ENEMY_SPEED * (vec->x / f_abs(vec->x));
		vec->y = 0;
	}
}

void	__get_vec(t_enemy *e, t_pos_vector *vec)
{
	int	x;
	int	y;

	__calc_vec(e, vec);
	x = collision_check_x(e->pos, ENEMY_SPEED * (vec->x / f_abs(vec->x)));
	y = collision_check_y(e->pos, ENEMY_SPEED * (vec->y / f_abs(vec->y)));
	if (x && y)
	{
		__new_vec(vec);
	}
	else if (y)
	{
		vec->x = ENEMY_SPEED * (vec->x / f_abs(vec->x));
		vec->y = 0;
	}
	else
	{
		vec->y = ENEMY_SPEED * (vec->y / f_abs(vec->y));
		vec->x = 0;
	}
}
