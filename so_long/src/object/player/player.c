#include "../../../headers/header.h"
#include <math.h>
#include <time.h>

#ifndef PLAYER_SPEED
# define PLAYER_SPEED 5
#endif
#ifndef FIREBALL_SPEED
#define FIREBALL_SPEED 30
#endif
#ifndef FIREBALL_COOLDOWN
#define FIREBALL_COOLDOWN 1
#endif

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
	if (keys[XK_w] && __collision_check_y(pos, -PLAYER_SPEED))
	{
		fthis()->object->pos.y -= PLAYER_SPEED;
		game()->moves++;
	}
	if (keys[XK_a] && __collision_check_x(pos, -PLAYER_SPEED))
	{
		fthis()->object->pos.x -= PLAYER_SPEED;
		game()->moves++;
	}
	if (keys[XK_s] && __collision_check_y(pos, PLAYER_SPEED))
	{
		fthis()->object->pos.y += PLAYER_SPEED;
		game()->moves++;
	}
	if (keys[XK_d] && __collision_check_x(pos, PLAYER_SPEED))
	{
		fthis()->object->pos.x += PLAYER_SPEED;
		game()->moves++;
	}
}


static int	__cooldown(clock_t *last, clock_t current)
{
	double		time_past;

	time_past = (double)(current - *last) / CLOCKS_PER_SEC;
	if (time_past > FIREBALL_COOLDOWN)
	{
		*last = current;
		return (1);
	}
	return (0);
}

// Calculates the direction and then shoots the fireball taking care to not divide by 0
static void	__player_mouse()
{
	static clock_t	init;
	t_pos_vector 	vec;

	vec.x = engine()->mouse.x - game()->player->pos.x;
	vec.y = engine()->mouse.y - game()->player->pos.y;
	__vec_normalization(&vec.x, &vec.y);
	vec.x *= FIREBALL_SPEED;
	vec.y *= FIREBALL_SPEED;
	if (__cooldown(&init, clock()))
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
