#include "../../../headers/header.h"

static void	__player_keys(byte *keys)
{
	t_pos_vector	pos;

	pos = fthis()->object->pos;
	if (keys[XK_w] && collision_check_y(pos, -PLAYER_SPEED))
	{
		fthis()->object->pos.y -= PLAYER_SPEED;
		game()->moves++;
	}
	if (keys[XK_a] && collision_check_x(pos, -PLAYER_SPEED))
	{
		fthis()->object->pos.x -= PLAYER_SPEED;
		game()->moves++;
	}
	if (keys[XK_s] && collision_check_y(pos, PLAYER_SPEED))
	{
		fthis()->object->pos.y += PLAYER_SPEED;
		game()->moves++;
	}
	if (keys[XK_d] && collision_check_x(pos, PLAYER_SPEED))
	{
		fthis()->object->pos.x += PLAYER_SPEED;
		game()->moves++;
	}
}

void	__mouse_left(void);
void	__mouse_right(void);

static void	__player_mouse(void)
{
	if (engine()->mouse_press == 1)
		__mouse_left();
	else if (engine()->mouse_press == 3)
		return ;
}
//__mouse_right();

static void	__player_update(void)
{
	if (game()->player->hp <= 0)
		harbinger_of_chaos();
}

t_object	*new_player(float x, float y)
{
	t_player	*player;

	player = constructor(sizeof(t_player));
	player->hp = 100;
	player->type = PLAYER;
	player->sprite = canva()->load_img("textures/player.xpm");
	player->func_keys = __player_keys;
	player->func_mouse = __player_mouse;
	player->update = __player_update;
	player->pos.w = canva()->scale_factor_e;
	player->pos.h = canva()->scale_factor_e;
	player->pos.x = x;
	player->pos.y = y;
	game()->player = player;
	return ((t_object *)player);
}
