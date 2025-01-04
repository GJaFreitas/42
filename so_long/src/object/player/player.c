#include "../../../headers/header.h"

#ifndef PLAYER_SPEED
# define PLAYER_SPEED 5
#endif
#ifndef FIREBALL_SPEED
#define FIREBALL_SPEED 30
#endif
#ifndef FIREBALL_COOLDOWN
#define FIREBALL_COOLDOWN 1
#endif

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

int	__cooldown(clock_t *last, clock_t current, float cooldown)
{
	double		time_past;

	time_past = (double)(current - *last) / CLOCKS_PER_SEC;
	if (time_past > cooldown)
	{
		*last = current;
		return (1);
	}
	return (0);
}

// Calculates the direction and then shoots the fireball taking care to not divide by 0
void	__mouse_left(void)
{
	static clock_t	init;
	t_pos_vector 	vec;

	vec.x = engine()->mouse.x - game()->player->pos.x;
	vec.y = engine()->mouse.y - game()->player->pos.y;
	__vec_normalization(&vec.x, &vec.y);
	vec.x *= FIREBALL_SPEED;
	vec.y *= FIREBALL_SPEED;
	if (__cooldown(&init, clock(), FIREBALL_COOLDOWN))
		game()->add_obj(new_fireball(vec));
}

void	__mouse_right(void);

static void	__player_mouse(void)
{
	if (engine()->mouse_press == 1)
		__mouse_left();
	else if (engine()->mouse_press == 3)
		return ;
		//__mouse_right();
}

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
	return ((t_object*)player);
}
