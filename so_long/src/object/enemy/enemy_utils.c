#include "../../../headers/header.h"

#ifndef ENEMY_SPEED
# define ENEMY_SPEED 4
#endif

t_pos_vector	__calc_vec(t_enemy *e, t_pos_vector *vec)
{
	t_pos_vector	direction;

	direction.x = e->pos.x - vec->x;
	direction.y = e->pos.y - vec->y;
	__vec_normalization(&direction.x, &direction.y);
	return (direction);
}

// Ret 1 if there is a colision with a wall
int	__check_wall(t_enemy *e, t_pos_vector vec)
{
	return (!collision_check_y(e->pos, vec.y
		|| !collision_check_x(e->pos, vec.x)));
}
