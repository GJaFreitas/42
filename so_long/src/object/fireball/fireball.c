#include "../../../headers/header.h"

// TODO: add explosion?
static void	__fireball_mov(void)
{
	t_fireball	*fireball;
	t_object	*colide;

	fireball = (t_fireball*)fthis()->object;
	fireball->pos.x += fireball->shot_vec.x;
	fireball->pos.y += fireball->shot_vec.y;
	colide = game()->obj_colision(fireball->pos, (t_type[]){WALL, ENEMY, 0});
	if (colide && colide->type == WALL)
		vector(game()->to_remove)->add(fthis()->object);
	else if (colide && colide->type == ENEMY)
	{
		colide->hp -= 101;
		vector(game()->to_remove)->add(fthis()->object);
	}
}

t_object	*new_fireball(t_pos_vector vec)
{
	t_fireball	*fireball;

	fireball = constructor(sizeof(t_fireball));
	fireball->type = FIREBALL;
	fireball->update = __fireball_mov;
	fireball->sprite = canva()->load_img("textures/fireball.xpm");
	fireball->pos.w = canva()->scale_factor_e / 2;
	fireball->pos.h = canva()->scale_factor_e / 2;
	fireball->pos.x = game()->player->pos.x + (game()->player->pos.w / 2);
	fireball->pos.y = game()->player->pos.y + (game()->player->pos.h / 2);
	fireball->shot_vec = vec;
	return (object((t_object*)fireball));
}
