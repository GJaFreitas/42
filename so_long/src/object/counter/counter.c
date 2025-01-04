#include "../../../headers/header.h"

/*
static void	__counter_destructor(void)
{
	t_counter	*c;

	c = (t_counter *)fthis()->object;
	mlx_destroy_image(engine()->mlx,
		   fthis()->object->sprite->img);
	free(fthis()->object->get_sprite());
}

static void	__counter_render(void)
{
	t_counter	*c;

	c = (t_counter *)fthis()->object;
	canva()->scale_img(
		c->get_sprite(c->current % 10), \
		c->pos);
	if (c->current > 9)
		canva()->scale_img(
			c->get_sprite(c->current / 10), \
			(t_pos_vector)\
			{c->pos.x - 50, c->pos.y,\
			c->pos.w, c->pos.h});
}

static t_sprite	*__counter_get_sprite(int i)
{
	return (((t_counter *)fthis()->object)->nums[i]);
}

t_object	*new_counter()
{
	t_counter	*new;

	new = constructor(sizeof(t_counter));
	new->render = __counter_render;
	new->get_sprite = __counter_get_sprite;
	new->destructor = __counter_destructor;
	new->nums[0] = canva()->load_img("");
	return ((t_object *)new);
}
*/
