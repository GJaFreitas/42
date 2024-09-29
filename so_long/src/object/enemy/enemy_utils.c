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

// Ret 1 if no colision
int	__collision_check_y(t_pos_vector pos, int mov)
{
	return (!game()->walls[(int)pos.y + mov][(int)pos.x]\
	&& !game()->walls[(int)(pos.y + mov)][(int)(pos.x + pos.w)]\
	&& !game()->walls[(int)(pos.y + pos.h + mov)][(int)(pos.x + pos.w)]\
	&& !game()->walls[(int)(pos.y + pos.h + mov)][(int)(pos.x)]);
}

int	__collision_check_x(t_pos_vector pos, int mov)
{
	return (!game()->walls[(int)pos.y][(int)pos.x + mov]\
	&& !game()->walls[(int)(pos.y)][(int)(pos.x + pos.w + mov)]\
	&& !game()->walls[(int)(pos.y + pos.h)][(int)(pos.x + pos.w + mov)]\
	&& !game()->walls[(int)(pos.y + pos.h)][(int)(pos.x + mov)]);
}

// Ret 1 if there is a colision with a wall
int	__check_wall(t_enemy *e, t_pos_vector vec)
{
	return (!__collision_check_y(e->pos, vec.y
		|| !__collision_check_x(e->pos, vec.x)));
}
