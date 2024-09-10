#include "../../../headers/header.h"

/*
 *
	if (keys[XK_w] && !game()->walls[(int)pos.y - 5][(int)pos.x]\
	&& !game()->walls[(int)(pos.y + pos.h - 5)][(int)pos.x])

	pos.y - 5 é a parte de cima do avatar
	pos.y + pos.h - 5 é a parte de baixo do avatar 
 *
 */

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

static void	__player_mouse()
{
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
	return (object((t_object*)player));
}
