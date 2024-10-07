#include "../../../headers/header.h"

#ifndef ENEMY_SPEED
# define ENEMY_SPEED 4
#endif

void	__calc_vec(t_enemy *e, t_pos_vector *vec)
{
	vec->x = e->pos.x - game()->player->pos.x;
	vec->y = e->pos.y - game()->player->pos.y;
	__vec_normalization(&vec->x, &vec->y);
	vec->x *= ENEMY_SPEED;
	vec->y *= ENEMY_SPEED;
}

// Ret 1 if there is a colision with a wall
int	__check_wall(t_enemy *e, t_pos_vector vec)
{
	return (!collision_check_y(e->pos, vec.y
		|| !collision_check_x(e->pos, vec.x)));
}
