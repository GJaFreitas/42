#include "../../../headers/header.h"

#ifndef DASH_DISTANCE
#define DASH_DISTANCE 15
#endif
#ifndef DASH_COOLDOWN
#define DASH_COOLDOWN 0.5
#endif

int	__cooldown(clock_t *last, clock_t current, float cooldown);

static int	__dash_check(t_pos_vector vec, int mult)
{
	if (collision_check_x(game()->player->pos, vec.x * mult)\
	&& collision_check_y(game()->player->pos, vec.y * mult))
		return (1);
	return (0);
}

static void	__dash(t_pos_vector vec)
{
	t_player	*p;
	int		i;

	p = game()->player;
	i = DASH_DISTANCE;
	while (__dash_check(vec, (i--)))
		;
	p->pos.x -= vec.x * i;
	p->pos.y -= vec.y * i;
}

void	__mouse_right()
{
	static clock_t	init;
	t_pos_vector 	vec;

	vec.x = engine()->mouse.x - game()->player->pos.x;
	vec.y = engine()->mouse.y - game()->player->pos.y;
	__vec_normalization(&vec.x, &vec.y);
	if (__cooldown(&init, clock(), DASH_COOLDOWN))
		__dash(vec);
}
