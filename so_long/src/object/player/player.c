#include "../../../headers/header.h"

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

#define FIREBALL_SPEED 10;

// Calculates the direction and then shoots the fireball taking care to not divide by 0
static void	__player_mouse()
{
	t_pos_vector vec;
	float	x;
	float	y;

	x = engine()->mouse.x - game()->player->pos.x;
	y = engine()->mouse.y - game()->player->pos.y;
	if (x == 0)
		vec = (t_pos_vector){ 0, (y / f_abs(y)), 0, 0 };
	else if (x > y)
	{
		vec.x = (x / canva()->scale_factor);
		vec.y = (y / canva()->scale_factor) / f_abs(vec.x);
		vec.x /= f_abs(vec.x);
	}
	else
	{
		vec.y = (y / canva()->scale_factor);
		vec.x = (x / canva()->scale_factor) / f_abs(vec.y);
		vec.y /= f_abs(vec.y);
	}
	vec.x *= FIREBALL_SPEED;
	vec.y *= FIREBALL_SPEED;
	if (!game()->fireball)
	{
		// TODO: fix the damn objects
		//game()->add_obj(new_fireball(vec));
	}
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
	return (object((t_object*)player));
}
