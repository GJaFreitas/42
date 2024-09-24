#include "../../../headers/header.h"

/*
static void	__new()
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (!game()->obj_colision((t_pos_vector)\
		{x, y, canva()->scale_factor_e, canva()->scale_factor_e},\
		(int[]){PLAYER, START, EXIT, COLLECTIBLE, BG, 0}))
	{
		x = rng(0, WIDTH);
		y = rng(0, HEIGHT);
	}
	printf("Coll x: %d y: %d\n", x, y);
	game()->add_obj(new_collectible(x, y));
	vector(game()->to_render)->sort();
}
*/

static void	__update_col(void)
{
	if (collides(game()->player->pos, fthis()->object->pos))
	{
		vector(game()->to_remove)->add(fthis()->object);
		game()->player->collectibles++;
		//__new();
	}
}

t_object	*new_collectible(float x, float y)
{
	t_collectible	*collectible;

	collectible = constructor(sizeof(t_collectible));
	collectible->type = COLLECTIBLE;
	collectible->sprite = canva()->load_img("textures/steel.xpm");
	collectible->pos.x = x * canva()->scale_factor;
	collectible->pos.y = y * canva()->scale_factor;
	collectible->pos.w = canva()->scale_factor_e;
	collectible->pos.h = canva()->scale_factor_e;
	collectible->update = __update_col;
	return (object((t_object*)collectible));
}
