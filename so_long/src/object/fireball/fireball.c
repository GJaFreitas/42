#include "../../../headers/header.h"

static void	__fireball_mov(void)
{
	t_fireball	*fireball;

	fireball = (t_fireball*)fthis()->object;
	fireball->pos.x += fireball->shot_vec.x;
	fireball->pos.y += fireball->shot_vec.y;
	if (game()->obj_colision(fireball->pos))
	{
		game()->fireball = 0;
		vector(game()->to_remove)->add(fthis()->object);
	}
}

t_object	*new_fireball(t_pos_vector vec)
{
	t_fireball	*fireball;

	game()->fireball++;
	fireball = constructor(sizeof(t_fireball));
	fireball->type = FIREBALL;
	fireball->update = __fireball_mov;
	fireball->sprite = canva()->load_img("textures/steel.xpm");
	fireball->pos.w = canva()->scale_factor_e / 2;
	fireball->pos.h = canva()->scale_factor_e / 2;
	fireball->pos.x = game()->player->pos.x;
	fireball->pos.y = game()->player->pos.y;
	fireball->shot_vec = vec;
	return (object((t_object*)fireball));
}
