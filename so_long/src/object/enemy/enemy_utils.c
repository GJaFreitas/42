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

static int	__collision_check_y(t_pos_vector pos, int mov)
{
	return (!game()->walls[(int)pos.y + mov][(int)pos.x]\
	&& !game()->walls[(int)(pos.y + mov)][(int)(pos.x + pos.w)]\
	&& !game()->walls[(int)(pos.y + pos.h + mov)][(int)(pos.x + pos.w)]\
	&& !game()->walls[(int)(pos.y + pos.h + mov)][(int)(pos.x)]);
}

static int	__collision_check_x(t_pos_vector pos, int mov)
{
	return (!game()->walls[(int)pos.y][(int)pos.x + mov]\
	&& !game()->walls[(int)(pos.y)][(int)(pos.x + pos.w + mov)]\
	&& !game()->walls[(int)(pos.y + pos.h)][(int)(pos.x + pos.w + mov)]\
	&& !game()->walls[(int)(pos.y + pos.h)][(int)(pos.x + mov)]);
}

static void	__avoid_wall(t_enemy *e, t_pos_vector *vec)
{
	if (game()->walls[(int)(e->pos.y + vec->y)][(int)e->pos.x])
		vec->h = 1;
	if (game()->walls[(int)e->pos.y][(int)(e->pos.x + vec->x)])
		vec->w = 1;
	if (vec->w && vec->h)
	{
		//TODO: Fucking corners
		//__corner(e, vec);
		printf("Fockin corner m8\n");
		return ;
	}
	if (vec->w)
	{
		vec->x = 0;
		vec->y = ENEMY_SPEED * (vec->y / f_abs(vec->y));
	}
	if (vec->h)
	{
		vec->y = 0;
		vec->x = ENEMY_SPEED * (vec->x / f_abs(vec->x));
	}
}

void	__check_wall(t_enemy *e, t_pos_vector *vec)
{
	if (!__collision_check_y(e->pos, vec->y))
		__avoid_wall(e, vec);
	if (!__collision_check_x(e->pos, vec->x))
		__avoid_wall(e, vec);
}
