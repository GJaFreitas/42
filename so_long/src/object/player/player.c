#include "../../../headers/header.h"
#include <math.h>
#include <time.h>

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

static void	__player_keys(byte *keys)
{
	t_pos_vector	pos;

	pos = fthis()->object->pos;
	if (keys[XK_w] && __collision_check_y(pos, -5))
	{
		fthis()->object->pos.y -= 5;
		game()->moves++;
	}
	if (keys[XK_a] && __collision_check_x(pos, -5))
	{
		fthis()->object->pos.x -= 5;
		game()->moves++;
	}
	if (keys[XK_s] && __collision_check_y(pos, 5))
	{
		fthis()->object->pos.y += 5;
		game()->moves++;
	}
	if (keys[XK_d] && __collision_check_x(pos, 5))
	{
		fthis()->object->pos.x += 5;
		game()->moves++;
	}
}

#define FIREBALL_SPEED 30;

static int	__cooldown(time_t current)
{
	static time_t	last;
	double		time_past;

	time_past = difftime(last, current);
	last = current;
	if (time_past > 3)
		return (1);
	return (0);
}

static void	__vec_normalization(float *x, float *y)
{
	double	module;

	module = sqrt((*x * *x) + (*y * *y));
	*x /= module;
	*y /= module;
}

// Calculates the direction and then shoots the fireball taking care to not divide by 0
static void	__player_mouse()
{
	t_pos_vector vec;

	vec.x = engine()->mouse.x - game()->player->pos.x;
	vec.y = engine()->mouse.y - game()->player->pos.y;
	__vec_normalization(&vec.x, &vec.y);
	vec.x *= FIREBALL_SPEED;
	vec.y *= FIREBALL_SPEED;
	if (__cooldown(time(NULL)))
		game()->add_obj(new_fireball(vec));
}

t_object	*new_player(float x, float y)
{
	t_player	*player;

	player = constructor(sizeof(t_player));
	player->type = PLAYER;
	player->sprite = canva()->load_img("textures/player.xpm");
	player->func_keys = __player_keys;
	player->func_mouse = __player_mouse;
	player->pos.w = canva()->scale_factor_e;
	player->pos.h = canva()->scale_factor_e;
	player->pos.x = x;
	player->pos.y = y;
	game()->player = player;
	return ((t_object*)player);
}
